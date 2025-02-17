#pragma once
#include <array>
#include "Ihelp.h"

constexpr int COMMON_SIZE   = 3;
constexpr int GENERALL_SIZE = 1;


namespace help
{
    class Help : public help::Ihelp
    {
    public:
        Help() = default;
        std::string param_message_descriptor(int selector) override;
        std::string param_view_descriptor(int selector)   override;
        std::string general_message_descriptor(int selector) override;
    protected:
        const std::array<const char*, COMMON_SIZE> PARAM_MESSAGE_DESCRIPTOR =
        {
            "Returns the current release build version.",
            "Takes file-path / filename for compression",
            "prints spesified input string, to test basic io functionality.",
        };

        const std::array<const char*, COMMON_SIZE> PARAM_DESCRIPTOR =
        {
            "-v, --verison",
            "-f, --file",
            "-p, --print",

        };

        const std::array<const char*,GENERALL_SIZE> GENERAL_MESSAGE =
        {
            "Ligth-weigth program for compressing and uncompressing zip and tarball files."
        };
    };
}
