#include <File.h>
#include <string>
#include <filesystem>
#include <spdlog/spdlog.h>
#include <fstream>

    FileRep::File::File(std::string filename)
    {
        this->_filename = std::move(filename);
        try
        {
            this->_filesize = std::filesystem::file_size(std::filesystem::path(this->_filename));
        }
        catch (const std::filesystem::filesystem_error &error)
        {
            spdlog::error(
                fmt::format("Error while opening file '{}', does the file exist?", this->_filename)
                );
            std::exit(127);
        }
    }

    uint32_t FileRep::File::filesize()
    {
        return this->_filesize;
    }

    std::string FileRep::File::filename()
    {
        return this->_filename;
    }

    std::string FileRep::File::algorithm()
    {
        return this->_algorithm;
    }

    std::vector<unsigned char> FileRep::File::readFileContent()
    {
        spdlog::debug(fmt::format("Reading file {}",this->_filename));
        std::vector<unsigned char> buffer(this->filesize());
        std::fstream file(this->filename(), std::ios::in | std::ios::binary);

        file.read(reinterpret_cast<char*>(buffer.data()), buffer.size());

        spdlog::debug(fmt::format("File: {} read!",this->_filename));

        return buffer;
    }

    std::string FileRep::File::filenameOnly()
    {
        std::string filename = this->_filename;
        size_t TargetPos = filename.find(".");
        if (TargetPos == std::string::npos)
        {
            spdlog::error("Target char in filename not found.");
        }

        while (filename.length() != TargetPos)
        {
            filename.pop_back();
        }

        return filename;
    }
