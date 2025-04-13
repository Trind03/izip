#pragma once
#include <fstream>
#include <string>
#include <memory>
#include <archive.h>


namespace wrappers
{
    namespace file
    {
        class IFile
        {
        public:
            virtual void read_file()                        = 0;
            virtual std::string filetype()                  = 0;
            virtual     ~IFile()                            = default;
            virtual std::ifstream::pos_type get_filesize(const char* filename)  = 0;
            virtual int get_exit_code() = 0;
            std::unique_ptr<std::fstream> file_stream       = nullptr;
        };
    }
}
