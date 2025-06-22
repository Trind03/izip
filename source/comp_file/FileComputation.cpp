#include <memory>
#include <string>
#include <fmt/core.h>
#include "universal/exit_codes.hpp"
#include <spdlog/spdlog.h>
#include <archive.h>
#include <archive_entry.h>
#include "FileComputation.h"


Izip::Wrappers::CompFile::FileComputation::FileComputation() : exit_code(0)
{
    this->UserPermissions = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;
}

int
Izip::Wrappers::CompFile::FileComputation::get_exit_code() const
{
    return exit_code;
}

int
Izip::Wrappers::CompFile::FileComputation::InteroptHandler(std::string_view msg,std::string_view dir)
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