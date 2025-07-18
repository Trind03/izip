#pragma once
#include <string>
#include <cstdint>
#include <vector>

namespace CompFile
{
    class FileIfc
    {
        public:
        FileIfc()          			                = default;
        virtual ~FileIfc() 			                = default;
        virtual std::vector<char> readFileContent() = 0;
        virtual uint32_t          filesize()        = 0;
        virtual std::string       filename()        = 0;
        virtual std::string       filenameOnly()    = 0;

    protected:
        std::string _filename;
        unsigned int _filesize = 0;
    };
}
