#include <vector>
#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include <archive.h>
#include <ArchiveComputation.h>
#include <macros/aliases.h>
#include <universal/exit_codes.hpp>

CompFile::ArchiveComputation::ArchiveComputation() : exit_code(0)
{
    this->UserPermissions = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;
}

int
CompFile::ArchiveComputation::get_exit_code() const
{
    return exit_code;
}

int
CompFile::ArchiveComputation::InteroptHandler(std::string_view msg,std::string_view dir)
{
    int status = EXIT_SUCCESS;
    spdlog::error(msg);

    if (rmdir(dir.data()) != 0) {
        status = resolve(Universal::EXIT_CODE::REMOVAL_DIR_ERROR);
        spdlog::critical(fmt::format("Failed to remove directory {}",dir));
        return status;
    }
    else {
        spdlog::info("output directory removed successfully!");
    }
    return status;
}