#include <File.h>
#include <string>
#include <filesystem>
#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/bundled/compile.h"

Izip::compfile::File::File(std::string filename)
{
    this->_filename = std::move(filename);
    this->_filesize = std::filesystem::file_size(std::filesystem::path(this->_filename));
}

unsigned int Izip::compfile::File::filesize()
{
    return   this->_filesize;
}
std::string Izip::compfile::File::filename()
{
    return this->_filename;
}

std::string Izip::compfile::File::filenameOnly()
{
    int32_t length;
    // Scope this to invalidate iterators used
    {
        std::string::iterator exttarget = std::find(this->_filename.begin(), this->_filename.end(), '.');
        std::string::iterator end = this->_filename.end();
        int32_t templen = &exttarget - &end;

        if (templen == 0)
            spdlog::warn("Invalid ext value");

        length = templen;
    }

    std::string filename = this->_filename;

    for (int32_t i = 0; i < length; i++)
        filename.pop_back();

    return filename;
}