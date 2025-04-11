#pragma once
#include <fstream>
#include <string>
#include <memory>

namespace wrappers
{
    namespace file
    {
        class IFile
        {
        public:
            virtual int read_file()        = 0;
            virtual int extract_tarball(std::string filename,std::string output_dir)  = 0;
            virtual std::string filetype() = 0;
            virtual     ~IFile()           = default;
            virtual int get_exit_code()    = 0;
            std::unique_ptr<std::fstream> file_stream = nullptr;
        };
    }
}
