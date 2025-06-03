#include "File.h"
#include <archive.h>
#include <archive_entry.h>
#include <spdlog/spdlog.h>
#include "universal/exit_codes.hpp"

int
wrappers::file::File::recursive_decompression(std::string_view filename)
{
    constexpr int EXPRECTED_BLOCK_SIZE = 128;
    int status_code = EXIT_CODE::SUCCESS;
    int flags       = 0;

    flags  = ARCHIVE_EXTRACT_TIME;
    flags |= ARCHIVE_EXTRACT_ACL;
    flags |= ARCHIVE_EXTRACT_PERM;
    flags |= ARCHIVE_EXTRACT_FFLAGS;

    struct archive_entry* current_archive_entry;
    struct archive* processed_archive;
    struct archive* current_archive;

    spdlog::info("Initializing handler");

    current_archive         = archive_read_new();
    processed_archive       = archive_write_disk_new();
    current_archive_entry   = render_archive_entry();

    spdlog::info("Recrusive archive handlers initialized!");

    archive_read_support_format_all(current_archive);
    archive_read_support_filter_all(current_archive);

    archive_write_disk_set_options(processed_archive,flags);
    archive_write_disk_set_standard_lookup(processed_archive);


    if (archive_read_open_filename(current_archive, filename.data(), EXPRECTED_BLOCK_SIZE) != ARCHIVE_OK)
    {
        spdlog::error("failed to open archive, perhaps files doesnt exist or blocking file permissions.");
        status_code = EXIT_FAILURE;
        return status_code;
    }
    else
    {
        spdlog::info("File opened successfully!");
    }

    spdlog::info("Processing supplied file");

    for(;;)
    {
        status_code = archive_read_next_header(current_archive, &current_archive_entry);
        pathname = archive_entry_pathname(current_archive_entry);
        archive_type = archive_entry_filetype(current_archive_entry);

        if (status_code != EXIT_CODE::SUCCESS)
        {
            spdlog::error("failed to read file-header, inconsistant formatting or corrupted file.");
            return status_code;
        }

        if (archive_type == AE_IFDIR)
        {
            status_code = mkdir(pathname.c_str(),111);

            if(status_code != ARCHIVE_OK)
            {
                spdlog::error(fmt::format("Failure to handel folder structure, with exit_code: {}",status_code));
                rmdir(pathname.c_str());
            }
        }

        if (status_code == ARCHIVE_EOF)
        {
            spdlog::info("Processing finished.");
            break;
        }

        if (status_code < ARCHIVE_OK)
        {
            spdlog::warn("NOK!");
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
        }

        exit_code = archive_write_finish_entry(processed_archive);

        if(exit_code != EXIT_CODE::SUCCESS)
            spdlog::error("Unknown issue finishing up, in last iteration");

    }

    archive_read_close(current_archive);
    archive_read_free(current_archive);
    archive_write_close(processed_archive);
    archive_write_free(processed_archive);

    return status_code;
}
