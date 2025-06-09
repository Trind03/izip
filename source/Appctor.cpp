#include <iostream>
#include <memory>
#include <spdlog/spdlog.h>
#include "Help.h"
#include "File.h"
#include "universal/exit_codes.hpp"
#include "App.h"

namespace app
{
    App::App()
    {
        exit_code  = EXIT_CODE::SUCCESS;
        Help_menu  = std::make_unique<help::Help>();
        Arg_parser = std::make_unique<CLI::App>(Help_menu->general_message_descriptor(help::descriptor::PROGRAM_DESCRIPTION));
        File = std::make_unique<wrappers::file::File>();

        try {

            this->OptVersion = Arg_parser->set_version_flag(Help_menu->param_symbol_descriptor(help::descriptor::MYVERSION),VERSION);

            this->OptDecompress = Arg_parser->add_option(Help_menu->param_symbol_descriptor(help::descriptor::DECOMPRESS),
                        File->filename,Help_menu->param_message_descriptor(help::descriptor::DECOMPRESS));

            this->OptCompress = Arg_parser->add_option(Help_menu->param_symbol_descriptor(help::descriptor::COMPRESS),
                        File->filename,Help_menu->param_message_descriptor(help::descriptor::COMPRESS));
            const CLI::App *recursive = Arg_parser->add_subcommand("recursive","myrecursive");
        }
        catch(const CLI::ArgumentMismatch& myException)
        {
            spdlog::error<const char*>("Argument mismatch error.");
            exit_code = EXIT_CODE::INVALID_ARG;
        }

        catch(const std::exception& Unknown_error)
        {
            spdlog::error<const char*>(Unknown_error.what());
            exit_code = EXIT_CODE::FAILURE;
        }
    }
}
