#include <spdlog/spdlog.h>
#include "Help.h"
#include "App.h"

namespace Izip
{
    int App::start(int argc,char **argv) const
    {
        CLI11_PARSE(*Arg_parser,argc,Arg_parser->ensure_utf8(argv));

        if (!(File.filename.empty()))
        {
            spdlog::info(fmt::format("detected file: {}",File.filename));
            File.decompress_archive(File.filename);
        }

        return exit_code;
    }

    int App::get_exit_code() const
    {
        return exit_code;
    }
}
