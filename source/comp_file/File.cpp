#include <memory>
#include <string>
#include <fmt/core.h>
#include "universal/exit_codes.hpp"
#include <spdlog/spdlog.h>
#include <archive.h>
#include <archive_entry.h>
#include "File.h"


Izip::Wrappers::CompFile::File::File() : exit_code(0)
{
    this->UserPermissions = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;

}

int
Izip::Wrappers::CompFile::File::get_exit_code()
{
    return exit_code;
}

int
Izip::Wrappers::CompFile::File::InteroptHandler(std::string_view msg,std::string_view dir)
{
    int status = EXIT_SUCCESS;
    spdlog::error(msg);

    if (rmdir(dir.data()) != 0) {
        status = Izip::Universal::EXIT_CODE::REMOVAL_DIR_ERROR;
        spdlog::critical(fmt::format("Failed to remove directory {}",dir));
        return status;
    }
    else {
        spdlog::info("output directory removed successfully!");
    }
    return status;
}

int
Izip::Wrappers::CompFile::File::copy_data(struct archive* myarchive,struct archive* archivew)
{
    int status_code = Izip::Universal::EXIT_CODE::SUCCESS;
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
            spdlog::error(fmt::format("{}",archive_error_string(archivew)));

            return status_code;
        }
    }
}
