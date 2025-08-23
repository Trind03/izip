#include <vector>
#include <spdlog/spdlog.h>
#include <archive.h>
#include <archive_entry.h>
#include <ArchiveComputation.h>
#include <universal/exit_codes.hpp>
#include <macros/aliases.h>

#include "gtest/internal/gtest-port.h"

archive_entry*
SoftArchive::RenderArchiveEntry(FileRep::IFile *File)
{
    archive_entry* p_archive_entry  = archive_entry_new();
    archive_entry_set_pathname(p_archive_entry,File->filename().c_str());

    return p_archive_entry;
}


int
SoftArchive::Decompress(FileRep::IFile *File)
{
    constexpr mode_t UserPermission = ARCHIVE_EXTRACT_PERM;
    std::array<char, 8192> Buffer {};
    int StatusCode   = resolve(Universal::EXIT_CODE::SUCCESS);
    int flags        = 0;

    flags  = ARCHIVE_EXTRACT_TIME;
    flags |= ARCHIVE_EXTRACT_ACL;
    flags |= ARCHIVE_EXTRACT_PERM;
    flags |= ARCHIVE_EXTRACT_FFLAGS;

    spdlog::debug("Initializing handler");

    archive_entry* CurrentArchiveEntry  = RenderArchiveEntry(File);
    archive* CurrentArchive             = archive_read_new();
    archive* WritableArchive            = archive_write_disk_new();

    if (archive_read_support_format_all(CurrentArchive) != resolve(Universal::EXIT_CODE::SUCCESS)) {
        spdlog::error("Failed to initialize archive reader");
        return resolve(Universal::EXIT_CODE::FAILURE);
    }

    if (archive_read_support_filter_all(CurrentArchive) != resolve(Universal::EXIT_CODE::SUCCESS)) {
        spdlog::error("Failed to initialize archive reader");
        return resolve(Universal::EXIT_CODE::FAILURE);
    }

    if (archive_write_disk_set_options(WritableArchive, flags) != resolve(Universal::EXIT_CODE::SUCCESS)) {
        spdlog::error("Failed to initialize archive writer");
        return resolve(Universal::EXIT_CODE::FAILURE);
    }
    StatusCode = archive_write_disk_set_standard_lookup(WritableArchive);


    if (StatusCode != resolve(Universal::EXIT_CODE::SUCCESS)) {
        spdlog::error("Failed to initialize multi-support.");
        return StatusCode;
    }


    if (archive_read_open_memory2(CurrentArchive, File->readFileContent().data(),
            File->readFileContent().size(), 1024) == ARCHIVE_OK)
    {
        spdlog::debug(fmt::format("Successfully loaded archive: {}", File->filename()));
    }

    else
    {
        spdlog::error("Failed to load archive from {}", File->filename());
        return ARCHIVE_FATAL;
    }

    while (archive_read_next_header(CurrentArchive, &CurrentArchiveEntry) == ARCHIVE_OK)
    {
        std::string PathName  = archive_entry_pathname_utf8(CurrentArchiveEntry);

        if (archive_entry_filetype(CurrentArchiveEntry) == AE_IFDIR )
            mkdir(PathName.c_str(), UserPermission);


        if (PathName.empty())
        {
            spdlog::warn("Archive in invalid state or nothing left to process.");
            return resolve(Universal::EXIT_CODE::INVALID_FILE);
        }
        spdlog::info(PathName);

        if (archive_entry_filetype(CurrentArchiveEntry) == AE_IFDIR)
        {
            spdlog::info("Creating new directory!");

            if (mkdir(PathName.c_str(), UserPermission) != resolve(Universal::EXIT_CODE::SUCCESS))
            {
                spdlog::error("Failed to create pathname: {}", PathName);
                return resolve(Universal::EXIT_CODE::FAILURE);
            }
        }

        if (archive_write_header(WritableArchive, CurrentArchiveEntry) != resolve(Universal::EXIT_CODE::SUCCESS)) {
            spdlog::error("Failed to write header: {}", PathName);
            return resolve(Universal::EXIT_CODE::FAILURE);
        }

        while (const la_ssize_t x = (archive_read_data(CurrentArchive, &Buffer, Buffer.size())) > ARCHIVE_OK)
        {
            if (x < ARCHIVE_OK)
                spdlog::error("Failed to read data from {}", PathName);

            archive_write_data(WritableArchive, Buffer.data(), Buffer.size());
        }
    }
    archive_read_close(CurrentArchive);
    archive_read_free(CurrentArchive);
    archive_write_close(WritableArchive);
    archive_write_free(WritableArchive);

    return StatusCode;
}
