#pragma once
#include <array>

constexpr int PARAM_LENGTH   = 6;
constexpr int GENERAL_SIZE = 1;

namespace Izip::Wrappers::CompHelp
{
    class Help
    {
    public:

        static Help& getInstance()
        {
            static Help helpInstance;
            return helpInstance;
        }

        std::string param_message_descriptor(std::size_t selector);
        std::string param_symbol_descriptor(std::size_t selector);
        std::string general_message_descriptor(std::size_t selector);

        const std::array<std::string, PARAM_LENGTH> PARAM_MESSAGE_DESCRIPTOR =
        {
            "Returns the current release build version.",
            "Takes file-path/filename for decompression",
            "Takes file-path/filename for compression",
            "Processes archives recursively such as feks folders.",
            "Spesify file permssions for output file. Default: 700",
            "Selection of algorithms."
        };

        const std::array<std::string, PARAM_LENGTH> PARAM_DESCRIPTOR =
        {
            "-v, --verison",
            "-d, --decompress",
            "-c, --compress",
            "-r, --recursive",
            "-p, --permissions",
            "-a, --algorithm"

        };

        const std::array<std::string,GENERAL_SIZE> GENERAL_MESSAGE =
        {
            "Ligth-weigth program for compressing and uncompressing zip and tarball files."
        };
    private:
        Help() = default;
    };
}
