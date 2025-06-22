#include <iostream>
#include <memory>
#include <spdlog/spdlog.h>
#include "File.h"
#include "universal/exit_codes.hpp"
#include "App.h"
#include "comp_help/Help.h"
#include "universal/Spesifier.hpp"

namespace Izip
{
    App::App()
    {
        exit_code  = Universal::EXIT_CODE::SUCCESS;

        Arg_parser = std::make_unique<CLI::App>(Help_menu.general_message_descriptor(
            Universal::GeneralSpesifier::PROGRAM_DESCRIPTION));

        try {
            std::string x = Help_menu.param_symbol_descriptor(Universal::Spesifier::MYVERSION);

            this->OptVersion = Arg_parser->set_version_flag(Help_menu.param_symbol_descriptor(Universal::Spesifier::MYVERSION),VERSION);

            this->OptDecompress = Arg_parser->add_option(Help_menu.param_symbol_descriptor(Universal::Spesifier::DECOMPRESS),
                        File.filename,Help_menu.param_message_descriptor(Universal::Spesifier::DECOMPRESS));

        }
        catch(const CLI::ArgumentMismatch& myException)
        {
            spdlog::error<const char*>("Argument mismatch error.");
            exit_code = Universal::EXIT_CODE::FAILURE;
        }

        catch(const std::exception& Unknown_error)
        {
            spdlog::error<const char*>(Unknown_error.what());
            exit_code = Universal::EXIT_CODE::FAILURE;
        }
    }
}
