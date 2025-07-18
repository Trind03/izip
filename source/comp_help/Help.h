#pragma once
#include <array>

namespace CompHelp
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