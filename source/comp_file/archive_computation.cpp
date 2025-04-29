#include <spdlog/spdlog.h>
#include <fmt/core.h>
#include <archive.h>
#include <archive_entry.h>
#include "File.h"
#include "exit_codes.hpp"

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

    flags =  ARCHIVE_EXTRACT_TIME;
    flags |= ARCHIVE_EXTRACT_ACL;
    flags |= ARCHIVE_EXTRACT_PERM;
    flags |= ARCHIVE_EXTRACT_FFLAGS;

    struct archive_entry* s_archive_entry;
    struct archive* processed_archive;
    struct archive* s_archive;
    spdlog::info("extracting archive");

    s_archive         = archive_read_new ();
    processed_archive = archive_write_disk_new();

    archive_read_support_format_all(s_archive);
    archive_read_support_filter_all(s_archive);

    archive_write_disk_set_options(processed_archive,flags);
    archive_write_disk_set_standard_lookup(processed_archive);

    if ((status_code = archive_read_open_filename(s_archive, filename, 10240)))
    {
        spdlog::info("failed to open archive");
        return nullptr;
    }

    for (;;) {
        status_code = archive_read_next_header(s_archive, &s_archive_entry);
        if (status_code == ARCHIVE_EOF)
            break;

        if (status_code < ARCHIVE_OK)
        {
            spdlog::info("NOK!");
        }

        if (status_code < ARCHIVE_WARN)
        {
            spdlog::warn("exited with warnings");
            return nullptr;
        }

        status_code = archive_write_header(processed_archive, s_archive_entry);
        if (status_code < ARCHIVE_OK)
        {
            spdlog::warn("Less then ok ;<");
        }

        // else if (archive_entry_size(s_archive_entry) > 0)
        // {
        //     status_code = copy_data(a, ext);

        //     if (status_code < ARCHIVE_OK)
        //         fprintf(stderr, "%s\n", archive_error_string(ext));

        //     if (status_code < ARCHIVE_WARN)
        //         return 1;
        // }

        status_code = archive_write_finish_entry(processed_archive);
        if (status_code < ARCHIVE_OK)
            spdlog::warn("NOK!");

        if (status_code < ARCHIVE_WARN)
            return nullptr;
    }
    archive_read_close(s_archive);
    archive_read_free(s_archive);
        /*
        archive_write_close(s_archive_entry);
        archive_write_free(s_archive_entry);
        */

    return processed_archive;
}

int wrappers::file::File::write_file_to_disk(struct archive* myarchive)
{
    return EXIT_CODE::SUCCESS;
}
