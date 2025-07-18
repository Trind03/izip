#include <File.h>
#include <string>
#include <filesystem>
#include <spdlog/spdlog.h>
#include <fstream>

namespace CompFile
{
    File::File(std::string filename)
    {
        this->_filename = std::move(filename);
        this->_filesize = std::filesystem::file_size(std::filesystem::path(this->_filename));
    }

    uint32_t File::filesize()
    {
        return   this->_filesize;
    }
    std::string File::filename()
    {
        return this->_filename;
    }

    std::vector<char> File::readFileContent()
    {
        spdlog::info(fmt::format("Reading file {}",this->_filename));
        std::vector<char> buffer(this->filesize());
        std::fstream file(this->filename(), std::ios::in | std::ios::binary);

        file.read(buffer.data(), buffer.size());

        spdlog::info(fmt::format("File: {} read!",this->_filename));

        return buffer;
    }

    std::string File::filenameOnly()
    {
        int32_t length;
        {
        // Scope this to invalidate iterators used
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
}
