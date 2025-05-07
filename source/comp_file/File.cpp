#include <memory>
#include "File.h"
#include <string>
#include <fmt/core.h>
#include <fstream>
#include "exit_codes.hpp"
#include <spdlog/spdlog.h>
#include <archive.h>

extern const int BLOCK_SIZE;

namespace wrappers
{
    namespace file
    {
        File::File() : exit_code(0)
        {
        }

        int File::get_exit_code()
        {    
            return exit_code;
        }

        int File::copy_data(struct archive* myarchive,struct archive* archivew)
        {
            int r;
            const void *buff;
            size_t size;
            la_int64_t offset;

            for (;;) {
                r = archive_read_data_block(myarchive, &buff, &size, &offset);
                if (r == ARCHIVE_EOF)
                    return (ARCHIVE_OK);
                if (r < ARCHIVE_OK)
                    return (r);
                r = archive_write_data_block(archivew, buff, size, offset);
                if (r < ARCHIVE_OK) {
                    fprintf(stderr, "%s\n", archive_error_string(archivew));
                    return (r);
                }
            }
        }
    }
}
