#pragma once
#include <array>

namespace Izip::Wrappers::CompHelp
{

        [[nodiscard]] std::string param_message_descriptor(size_t selector);
        [[nodiscard]] std::string param_symbol_descriptor(size_t  selector);
        [[nodiscard]] std::string general_message_descriptor(size_t selector);
}

namespace Izip::Wrappers::CompHelp::helpMessage
{
        const std::array<std::string, PARAM_LENGTH> PARAM_MESSAGE_DESCRIPTOR =
        {
                "Returns the current release build version.",
                "Takes archive-path for decompression.",
                "Experimental file compression"
        };

        const std::array<std::string, PARAM_LENGTH> PARAM_DESCRIPTOR =
        {
                "-v, --version",
                "-d, --decompress",
                "-c, --compress"
        };

        const std::array<std::string,GENERAL_SIZE> GENERAL_MESSAGE =
        {
                "Ligth-weigth program for compressing and uncompressing zip and tarball files."
        };
}