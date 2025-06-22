#include <iostream>
#include <memory>
#include <spdlog/spdlog.h>
#include <FileComputation.h>
#include <universal/exit_codes.hpp>
#include <App.h>
#include <comp_help/Help.h>
#include <universal/Spesifier.hpp>
#include <macros/aliases.h>

using namespace Izip::Wrappers::CompHelp;
using namespace  Izip::Universal;

namespace Izip
{
    App::App()
    {
        exit_code  = resolve(EXIT_CODE::SUCCESS);

        Arg_parser = std::make_unique<CLI::App>(general_message_descriptor(
            resolve(GeneralSpesifier::PROGRAM_DESCRIPTION)));

        try {
            this->OptVersion = Arg_parser->set_version_flag(param_symbol_descriptor(resolve(Spesifier::MYVERSION)),VERSION);

            this->OptDecompress = Arg_parser->add_option(param_symbol_descriptor(resolve(Spesifier::DECOMPRESS)),
            fileComputation.filename,param_message_descriptor(resolve(Spesifier::DECOMPRESS)));

            this->OptCompress = Arg_parser->add_option(param_symbol_descriptor(resolve(Spesifier::COMPRESS)),
                fileComputation.filename,param_message_descriptor(resolve(Spesifier::COMPRESS)));
        }
        catch(const CLI::ArgumentMismatch& myException)
        {
            spdlog::error<const char*>("Argument mismatch error.");
            exit_code = resolve(EXIT_CODE::FAILURE);
        }

        catch(const std::exception& Unknown_error)
        {
            spdlog::error<const char*>(Unknown_error.what());
            exit_code = resolve(EXIT_CODE::FAILURE);
        }
    }
}
