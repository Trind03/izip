//
// Created by Torstein on 15/06/2025.
//

#include <archive.h>
#include <fstream>
#include <archive_entry.h>
#include <ArchiveComputation.h>
#include <universal/exit_codes.hpp>
#include <../FileRep/IFile.h>
#include <spdlog/spdlog.h>

#include "macros/aliases.h"



int SoftArchive::Compress(FileRep::IFile* File)
{
    constexpr int BLOCK_SIZE = 1024;
    archive_entry*  ArchiveEntry    = archive_entry_new();
    archive*        ArchiveRead     = archive_read_new();
    archive*        ArchiveWrite    = archive_write_new();

    archive_read_open_filename(ArchiveRead, File->filename().c_str(), BLOCK_SIZE);
    return resolve(Universal::EXIT_CODE::SUCCESS);
}
