#include <iostream>
#include <memory>
#include "File.h"
#include <string>
#include <fstream>
#include "exit_codes.hpp"
#include <spdlog/spdlog.h>
#include <archive.h>
extern const int BLOCK_SIZE;

namespace wrappers
{
    namespace file
    {
        File::File(std::string filename)
        {
            this->filename = filename;
            this->file_stream = std::make_unique<std::fstream>(filename,std::ios::binary);
        }
        std::string File::filetype()
        {
            return "";
        }

        int File::get_exit_code()
        {
            return 0;
        }

        void File::read_file()
        {
            return;
        }

        std::ifstream::pos_type File::get_filesize(const char* filename)
        {
            std::ifstream stream(filename,std::ifstream::ate | std::ifstream::binary);
            return stream.tellg();
        }
    }
}
