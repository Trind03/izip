#pragma once
#include <array>
#include "Ihelp.h"

constexpr int PARAM_LENGTH   = 5;
constexpr int GENERAL_SIZE = 1;

namespace help
{
    class Help : public help::Ihelp
    {
    public:
        Help() = default;
        std::string param_message_descriptor(std::size_t selector) override;
        std::string param_symbol_descriptor(std::size_t selector)   override;
        std::string general_message_descriptor(std::size_t selector) override;

        const std::array<const char*, PARAM_LENGTH> PARAM_MESSAGE_DESCRIPTOR =
        {
            "Returns the current release build version.",
            "Takes file-path/filename for decompression",
	        //"Processes archives recursively such as feks folders."
            "Takes file-path/filename for compression",
            "prints spesified input string, to test basic io functionality.",
            "Selection of algorithms."
        };

        const std::array<const char*, PARAM_LENGTH> PARAM_DESCRIPTOR =
        {
            "-v, --verison",
            "-d, --decompress",
            //"-r, --recursive",
            "-c, --compress",
            "-p, --print",
            "-a, --algorithm"

        };

        const std::array<const char*,GENERALL_SIZE> GENERAL_MESSAGE =
        {
            "Ligth-weigth program for compressing and uncompressing zip and tarball files."
        };
    };
}
