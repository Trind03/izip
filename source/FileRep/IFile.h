#pragma once
#include <string>
#include <cstdint>
#include <vector>

namespace FileRep
{
    class IFile
    {
        public:
            IFile()          			                            = default;
            virtual ~IFile() 			                            = default;
            virtual std::vector<unsigned char> readFileContent()    = 0;
            virtual uint32_t          filesize()                    = 0;
            virtual std::string       filename()                    = 0;
            virtual std::string       filenameOnly()                = 0;
            virtual std::string       algorithm()                   = 0;
        protected:
            std::string _filename;
            int _filesize = 0;
            std::string _algorithm;
    };
}
