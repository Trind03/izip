//
// Created by Torstein on 15/06/2025.
//

#pragma once
#include <archive.h>
#include "FileComputation.h"

namespace Izip::Wrappers::CompFile
{
    int FileComputation::compress(std::string_view filename)
    {
        int statusCode = 0;
        struct archive* Current_Archive = archive_write_new();
        statusCode = archive_write_set_format_zip(Current_Archive);
        statusCode = archive_write_add_filter_none(Current_Archive);

        return statusCode;
    }
}