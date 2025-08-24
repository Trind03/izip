#include <vector>
#include <spdlog/spdlog.h>
#include <archive.h>
#include <archive_entry.h>
#include <ArchiveComputation.h>
#include <universal/exit_codes.hpp>
#include <macros/aliases.h>

#include "gtest/internal/gtest-port.h"

int
SoftArchive::Decompress(FileRep::IFile *File)
{
    mode_t UserPermissions;
    std::array<char, 8192> Buffer {};
    int StatusCode   = resolve(Universal::EXIT_CODE::SUCCESS);
    int flags        = 0;

    flags  = ARCHIVE_EXTRACT_TIME;
    flags |= ARCHIVE_EXTRACT_ACL;
    flags |= ARCHIVE_EXTRACT_PERM;
    flags |= ARCHIVE_EXTRACT_FFLAGS;

    spdlog::debug("Initializing handler");

    archive_entry* CurrentArchiveEntry  = archive_entry_new();
    archive* CurrentArchive             = archive_read_new();
    archive* WritableArchive            = archive_write_disk_new();

    archive_entry_set_pathname(CurrentArchiveEntry, File->filename().c_str());

    archive_read_support_format_all(CurrentArchive);
    archive_read_support_filter_all(CurrentArchive);

    archive_write_disk_set_options(CurrentArchive,flags);
    archive_write_disk_set_standard_lookup(WritableArchive);


    if (archive_read_open_filename(CurrentArchive, File->filename().c_str(),1024)
        == ARCHIVE_OK)
    {
        spdlog::debug(fmt::format("Successfully loaded archive: {}", File->filename()));
    }

    else
    {
        spdlog::error(archive_error_string(CurrentArchive));
        return ARCHIVE_FATAL;
    }

    while (true)
    {
        {
            int x = archive_read_next_header(CurrentArchive, &CurrentArchiveEntry);
            if (x == ARCHIVE_EOF)
            {
                spdlog::info("Finished reading archive");
                return 0;
            }
            if (x != ARCHIVE_OK)
             {
                spdlog::error(archive_error_string(CurrentArchive));
                return x;
             }
            UserPermissions = archive_entry_perm(CurrentArchiveEntry);
        }

        std::string PathName = archive_entry_pathname_utf8(CurrentArchiveEntry);

        // if (archive_entry_filetype(CurrentArchiveEntry) == AE_IFDIR )
        //     mkdir(PathName.c_str(), archive_entry_perm(CurrentArchiveEntry));


        if (PathName.empty())
        {
            spdlog::warn("Archive in invalid state or nothing left to process.");
            return resolve(Universal::EXIT_CODE::INVALID_FILE);
        }
        spdlog::info(PathName);

        if (archive_entry_filetype(CurrentArchiveEntry) == AE_IFDIR)
        {
            spdlog::info("Creating new directory!");

            if (mkdir(PathName.c_str(), UserPermissions) != resolve(Universal::EXIT_CODE::SUCCESS))
            {
                spdlog::error("Failed to create pathname: {}", PathName);
                return resolve(Universal::EXIT_CODE::FAILURE);
            }
        }

        if (archive_write_header(WritableArchive, CurrentArchiveEntry) != resolve(Universal::EXIT_CODE::SUCCESS)) {
            spdlog::error("Failed to write header: {}", PathName);
            return resolve(Universal::EXIT_CODE::FAILURE);
        }

        while (const la_ssize_t x = archive_read_data(CurrentArchive, &Buffer, Buffer.size()) != ARCHIVE_OK)
        {
            // if (x < ARCHIVE_OK)
            //     spdlog::error("Failed to read data from {}", PathName);

            archive_write_data(WritableArchive, Buffer.data(), Buffer.size());
        }
    }
    archive_read_close(CurrentArchive);
    archive_read_free(CurrentArchive);
    archive_write_close(WritableArchive);
    archive_write_free(WritableArchive);

    return StatusCode;
}
