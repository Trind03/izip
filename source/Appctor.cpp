#include <iostream>
#include <memory>
#include <spdlog/spdlog.h>
#include <ArchiveComputation.h>
#include <universal/exit_codes.hpp>
#include <comp_help/Help.h>
#include <universal/Spesifier.hpp>
#include <macros/aliases.h>
#include <App.h>

using namespace Universal;

App::App()
{
    exit_code  = resolve(Universal::EXIT_CODE::SUCCESS);

    Arg_parser = std::make_unique<CLI::App>(
        CompHelp::GENERAL_MESSAGE[resolve(Universal::
            GeneralSpesifier::PROGRAM_DESCRIPTION)]
        );

    try {
        this->OptVersion = Arg_parser->set_version_flag(
            CompHelp::PARAM_DESCRIPTOR[resolve(Universal::Spesifier::MYVERSION)]);


        this->OptDecompress = Arg_parser->add_option(
            CompHelp::PARAM_DESCRIPTOR[resolve(Universal::Spesifier::DECOMPRESS)], DecompressTargets,
            CompHelp::PARAM_MESSAGE_DESCRIPTOR[resolve(Universal::Spesifier::DECOMPRESS)]);

        this->OptCompress = Arg_parser->add_option(
            CompHelp::PARAM_DESCRIPTOR[resolve(Universal::Spesifier::COMPRESS)],CompressTargets,
            CompHelp::PARAM_MESSAGE_DESCRIPTOR[resolve(Universal::Spesifier::COMPRESS)]);
    }
    catch(const CLI::ArgumentMismatch&)
    {
        spdlog::error<const char*>("Argument mismatch error.");
        exit_code = resolve(Universal::EXIT_CODE::FAILURE);
    }

    catch(const std::exception& Unknown_error)
    {
        spdlog::error<const char*>(Unknown_error.what());
        exit_code = resolve(Universal::EXIT_CODE::FAILURE);
    }
}

