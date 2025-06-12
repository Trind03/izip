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
        Help_menu  = std::make_unique<Wrappers::CompHelp::Help>();
        Arg_parser = std::make_unique<CLI::App>(Help_menu->general_message_descriptor(
            Universal::GeneralSpesifier::PROGRAM_DESCRIPTION));
        File = std::make_unique<Izip::Wrappers::CompFile::File>();

        try {

            this->OptVersion = Arg_parser->set_version_flag(Help_menu->param_symbol_descriptor(Universal::Spesifier::MYVERSION),VERSION);

            this->OptDecompress = Arg_parser->add_option(Help_menu->param_symbol_descriptor(Universal::Spesifier::DECOMPRESS),
                        File->filename,Help_menu->param_message_descriptor(Universal::Spesifier::DECOMPRESS));

            this->OptCompress = Arg_parser->add_option(Help_menu->param_symbol_descriptor(Universal::Spesifier::COMPRESS),
                        File->filename,Help_menu->param_message_descriptor(Universal::Spesifier::COMPRESS));


            this->OptRecursive = Arg_parser->add_flag(Help_menu->param_symbol_descriptor(Universal::Spesifier::RECURSIVE),
               File->recursive,Help_menu->param_message_descriptor(Universal::Spesifier::RECURSIVE));

            this->OptPermissions = Arg_parser->add_option(Help_menu->param_symbol_descriptor(
                Universal::Spesifier::PERMISSIONS),File->UserPermissions,
                Help_menu->param_message_descriptor(Universal::Spesifier::PERMISSIONS));
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
