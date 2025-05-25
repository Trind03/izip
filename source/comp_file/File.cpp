#include <memory>
#include "File.h"
#include <string>
#include <fmt/core.h>
#include <fstream>
#include "universal/exit_codes.hpp"
#include <spdlog/spdlog.h>
#include <archive.h>


wrappers::file::File::File() : exit_code(0)
{

}

int
wrappers::file::File::get_exit_code()
{
    return exit_code;
}

int
wrappers::file::File::copy_data(struct archive* myarchive,struct archive* archivew)
{
    int status_code = EXIT_CODE::SUCCESS;
    const void *buff;
    size_t size;
    la_int64_t offset;

    for (;;) {
        status_code = archive_read_data_block(myarchive, &buff, &size, &offset);
        if (status_code == ARCHIVE_EOF)
            return (ARCHIVE_OK);

        if (status_code < ARCHIVE_OK)
            return (status_code);

        status_code = archive_write_data_block(archivew, buff, size, offset);

        if (status_code < ARCHIVE_OK) {
            fprintf(stderr, "%s\n", archive_error_string(archivew));
            return (status_code);
        }
    }
}

mode_t
wrappers::file::File::get_archive_type(const std::string_view filename)
{
    struct archive_entry *probe_archive_entry = render_archive_entry();
    return 0;
}

