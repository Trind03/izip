#pragma once
#include "universal/composite.hpp"

namespace help
{
    class Ihelp
    {
    public:
        virtual std::string param_message_descriptor(std::size_t selector)     = 0;
        virtual std::string param_view_descriptor(std::size_t selector)        = 0;
        virtual std::string general_message_descriptor(std::size_t selector)   = 0;
        virtual ~Ihelp() = default;
    };
}
