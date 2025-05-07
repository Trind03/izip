#include "exit_codes.hpp"
#include <spdlog/spdlog.h>
#include "Help.h"
#include "App.h"

namespace app
{
    int App::start(int argc,char **argv)
    {
        CLI11_PARSE(*Arg_parser,argc,Arg_parser->ensure_utf8(argv));

        if(comp_file->filename.c_str())
        {
            spdlog::info(fmt::format("detected file: {}",comp_file->filename.c_str()));
            comp_file->decompress_archive(comp_file->filename.c_str());
        }

        return exit_code;
    }

    int App::get_exit_code()
    {
        return exit_code;
    }

    void App::message()
    {
        spdlog::info("Message function in App class.");
    }
}
