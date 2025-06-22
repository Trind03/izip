#pragma once
#include <array>


constexpr int PARAM_LENGTH   = 2;
constexpr int GENERAL_SIZE = 1;

namespace Izip::Wrappers::CompHelp
{
    class Help
    {
    public:

        [[nodiscard]] static Help& getInstance()
        {
            static Help helpInstance;
            return helpInstance;
        }

        [[nodiscard]] std::string param_message_descriptor(size_t selector)   const;
        [[nodiscard]] std::string param_symbol_descriptor(size_t  selector)    const;
        [[nodiscard]] std::string general_message_descriptor(size_t selector) const;

        const std::array<std::string, PARAM_LENGTH> PARAM_MESSAGE_DESCRIPTOR =
        {
            "Returns the current release build version.",
            "Takes file-path/filename for decompression",
        };

        const std::array<std::string, PARAM_LENGTH> PARAM_DESCRIPTOR =
        {
            "-v, --verison",
            "-d, --decompress",
        };

        const std::array<std::string,GENERAL_SIZE> GENERAL_MESSAGE =
        {
            "Ligth-weigth program for compressing and uncompressing zip and tarball files."
        };
    private:
        Help() = default;
    };
}
