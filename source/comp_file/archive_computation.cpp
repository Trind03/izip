#include <spdlog/spdlog.h>
#include <fmt/core.h>
#include <archive.h>
#include <archive_entry.h>
#include "File.h"
#include "universal/exit_codes.hpp"
#include <filesystem>


archive_entry* wrappers::file::File::render_archive_entry()
{
    struct archive_entry* p_archive_entry;

    p_archive_entry = archive_entry_new();
    archive_entry_set_pathname(p_archive_entry,this->filename.c_str());

    return p_archive_entry;
}



int wrappers::file::File::decompress_archive(const char* filename)
{
    constexpr int EXPRECTED_BLOCK_SIZE = 128;
    int status_code = 0;
    int flags       = 0;

    flags  = ARCHIVE_EXTRACT_TIME;
    flags |= ARCHIVE_EXTRACT_ACL;
    flags |= ARCHIVE_EXTRACT_PERM;
    flags |= ARCHIVE_EXTRACT_FFLAGS;

    struct archive_entry* current_archive_entry;
    struct archive* processed_archive;
    struct archive* current_archive;

    spdlog::debug("Initializing handler");

    current_archive         = archive_read_new();
    processed_archive       = archive_write_disk_new();
    current_archive_entry   = render_archive_entry();

    spdlog::debug("archive handlers initialized!");

    archive_read_support_format_all(current_archive);
    archive_read_support_filter_all(current_archive);

    archive_write_disk_set_options(processed_archive,flags);
    archive_write_disk_set_standard_lookup(processed_archive);


    if (archive_read_open_filename(current_archive, filename, EXPRECTED_BLOCK_SIZE) != ARCHIVE_OK)
    {
        spdlog::error("failed to open archive, perhaps files doesnt exist or blocking file permissions.");
        return status_code;
    }
    else
    {
        spdlog::info("File opened successfully!");
    }

    spdlog::info("Processing supplied file");

    for(;;)
    {
        int status = archive_read_next_header(current_archive, &current_archive_entry);
        pathname = archive_entry_pathname(current_archive_entry);
        archive_type = archive_entry_filetype(current_archive_entry);

        if (archive_type == AE_IFDIR)
        {
            int mkdir_code = mkdir(pathname.c_str(),744);

            if(mkdir_code != ARCHIVE_OK)
            {
                spdlog::error(fmt::format("Failure to handel folder structure, with exit_code: {}",mkdir_code));
                rmdir(pathname.c_str());
            }
        }

        if (status == ARCHIVE_EOF)
        {
            spdlog::info("Processing finished.");
            break;
        }

        if (status_code < ARCHIVE_OK)
        {
            spdlog::warning("NOK!");
        }

        if (status_code < ARCHIVE_WARN)
        {
            spdlog::warn("exited with warnings");
            return status_code;
        }

        exit_code = archive_write_header(processed_archive,current_archive_entry);

        if(exit_code != EXIT_CODE::SUCCESS)
            spdlog::error("Unknown issue writing to iterative chunk to disk.");


        if (exit_code < ARCHIVE_OK)
            spdlog::warn("Less then ok ;<");

        else if (archive_entry_size(current_archive_entry) > 0)
        {
            exit_code = copy_data(current_archive,processed_archive);

            if (exit_code < ARCHIVE_OK)
                spdlog::error("some error");

            if (exit_code < ARCHIVE_WARN)
                return status_code;
        }


        exit_code = archive_write_finish_entry(processed_archive);

        if(exit_code != EXIT_CODE::SUCCESS)
            spdlog::error("Unknown issue finishing up, in last iteration");

        return status_code;

        if (status_code < ARCHIVE_OK)
            spdlog::warn("NOK!");

        if (status_code < ARCHIVE_WARN)
            return status_code;

    }

    if(status_code != 0)
    {
        spdlog::error("Failure to write extracted element to disk :<");
    }


    if (status_code != ARCHIVE_OK)
        spdlog::error("Files could't be written to disk due to unknown extraction error");

    archive_read_close(current_archive);
    archive_read_free(current_archive);
    archive_write_close(processed_archive);
    archive_write_free(processed_archive);

    return status_code;
}
