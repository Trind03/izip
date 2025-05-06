#include <spdlog/spdlog.h>
#include <fmt/core.h>
#include <archive.h>
#include <archive_entry.h>
#include "File.h"
#include "exit_codes.hpp"
#include <filesystem>
#include <stdio.h>


int wrappers::file::File::write_file_to_disk(struct archive* myarchive,struct archive_entry* myarchive_entry)
{
    int status_code = EXIT_CODE::SUCCESS;

    status_code = archive_write_header(myarchive,myarchive_entry);

    return status_code;
}



archive_entry* wrappers::file::File::render_archive_entry()
{
    struct archive_entry* p_archive_entry;

    p_archive_entry = archive_entry_new();
    archive_entry_set_pathname(p_archive_entry,this->filename.c_str());

    return p_archive_entry;

}

archive* wrappers::file::File::read_load_archive(const char* filename)
{
    int status_code = 0;
    int flags       = 0;

    flags  = ARCHIVE_EXTRACT_TIME;
    flags |= ARCHIVE_EXTRACT_ACL;
    flags |= ARCHIVE_EXTRACT_PERM;
    flags |= ARCHIVE_EXTRACT_FFLAGS;

    struct archive_entry* current_archive_entry;
    struct archive* processed_archive;
    struct archive* current_archive;

    spdlog::info("extracting archive");

    current_archive         = archive_read_new();
    processed_archive       = archive_write_disk_new();
    current_archive_entry   = render_archive_entry();

    archive_read_support_format_all(current_archive);
    archive_read_support_filter_all(current_archive);

    archive_write_disk_set_options(processed_archive,flags);
    archive_write_disk_set_standard_lookup(processed_archive);

    if (archive_read_open_filename(current_archive, filename, 10240) != ARCHIVE_OK)
    {
        spdlog::info("failed to open archive");
        return nullptr;
    }


    for(;;)
    {
        status_code = archive_read_next_header(current_archive, &current_archive_entry);

        if (size == 0)
            break;

        if (status_code != ARCHIVE_OK)
        {
            fmt::print("{}",archive_error_string(current_archive));
            break;
        }

        if (status_code < ARCHIVE_OK)
        {
            spdlog::info("NOK!");
        }

        if (status_code < ARCHIVE_WARN)
        {
            spdlog::warn("exited with warnings");
            return nullptr;
        }

        status_code = write_file_to_disk(processed_archive,current_archive_entry);
        if (status_code < ARCHIVE_OK)
        {
            spdlog::warn("Less then ok ;<");
        }

        else if (archive_entry_size(current_archive_entry) > 0)
        {

            if (status_code < ARCHIVE_OK)
                spdlog::error("some error");

            if (status_code < ARCHIVE_WARN)
                return nullptr;
        }

        if (status_code < ARCHIVE_OK)
            spdlog::warn("NOK!");

        if (status_code < ARCHIVE_WARN)
            return nullptr;

    }


    if(status_code != 0)
    {
        spdlog::error("Failure to write extracted element to disk :<");
    }


    if (status_code == ARCHIVE_OK)
    {
        spdlog::error("Files could't be written to disk due to unknown extraction error");
        archive_read_close(current_archive);
        archive_read_free(current_archive);
        archive_write_close(processed_archive);
        archive_write_free(processed_archive);
    }

    return processed_archive;
}
