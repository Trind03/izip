#include "universal/exit_codes.hpp"
#include <spdlog/spdlog.h>
#include "Help.h"
#include "App.h"

namespace Izip
{
    int App::start(const int argc,char **argv)
    {
        CLI11_PARSE(*Arg_parser,argc,Arg_parser->ensure_utf8(argv));

        if (File->UserPermissions == 0)
            File->UserPermissions = 700;

        if (File->filename.c_str())
        {
            spdlog::info(fmt::format("detected file: {}",File->filename));

            if (File->recursive)
            {
                File->recursive_decompression(File->filename);
                return this->exit_code;
            }
            else
                File->decompress_archive(File->filename);
        }

        return exit_code;
    }

    int App::get_exit_code()
    {
        return exit_code;
    }


}
