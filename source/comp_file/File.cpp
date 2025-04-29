#include <memory>
#include "File.h"
#include <string>
#include <fmt/core.h>
#include <fstream>
#include "exit_codes.hpp"
#include <spdlog/spdlog.h>
#include <archive.h>
extern const int BLOCK_SIZE;

namespace wrappers
{
    namespace file
    {
        File::File() : exit_code(0)
        {
        }

        int File::get_exit_code()
        {    
            return exit_code;
        }
    }
}
