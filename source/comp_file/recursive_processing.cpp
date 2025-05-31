#include "File.h"
#include <archive.h>
#include <spdlog/spdlog.h>
#include "universal/exit_codes.hpp"

int
wrappers::file::File::recursive_decompression(struct archive *Archive, struct archive_entry *Archive_entry, const char* prefix)
{
    int local_exit_code = EXIT_CODE::SUCCESS;

    spdlog::info("This is an folder!");

    return local_exit_code;
}
