//
// Created by Torstein on 15/06/2025.
//

#pragma once
#include <archive.h>
#include "FileComputation.h"
#include "spdlog/spdlog.h"

namespace Izip::Wrappers::CompFile
{
    int FileComputation::compress(std::string_view filename,std::string_view algorithm)
    {
        int statusCode = 0;
        archive* Current_Archive = archive_write_new();

        switch (algorithm)
        {
            default:
                spdlog::info("Compression algorithm: Tar");
                statusCode = archive_write_zip_set_compression_xz(Current_Archive);
        }

        return statusCode;
    }
}
