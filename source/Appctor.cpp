#include <iostream>
#include <memory>
#include <spdlog/spdlog.h>
#include "Help.h"
#include "File.h"
#include "exit_codes.hpp"
#include "App.h"
#define VERSION "0.0.0.0 - Genisis"

namespace app
{
    App::App()
    {
        exit_code  = EXIT_CODE::SUCCESS;
        Help_menu  = std::make_unique<help::Help>();
        Arg_parser = std::make_unique<CLI::App>(Help_menu->general_message_descriptor(help::descriptor::PROGRAM_DESCRIPTION));
        comp_file = std::make_unique<wrappers::file::File>();

        try
        {
            Arg_parser->set_version_flag(Help_menu->param_view_descriptor(help::descriptor::MYVERSION),VERSION);

            Arg_parser->add_option(Help_menu->param_view_descriptor(help::descriptor::FILE),
                            comp_file->filename,Help_menu->param_message_descriptor(help::descriptor::FILE));
        }

        catch(const CLI::ArgumentMismatch& myException)
        {
            spdlog::error<const char*>("Argument mismach error.");
            exit_code = EXIT_CODE::INVALID_ARG;
        }

        catch(const std::exception& Unknown_error)
        {
            spdlog::error<const char*>(Unknown_error.what());
            exit_code = EXIT_CODE::FAILURE;
        }
    }
}
