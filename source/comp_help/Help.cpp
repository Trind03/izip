#include <string>
#include "Help.h"
#include "universal/exit_codes.hpp"

namespace help
{
    std::string Help::param_message_descriptor(std::size_t selector)
    {
        return selector < PARAM_MESSAGE_DESCRIPTOR.size() && selector >= 0 ? PARAM_MESSAGE_DESCRIPTOR[selector] : "";
    }

    std::string Help::param_symbol_descriptor(std::size_t selector)
    {
        return selector < PARAM_DESCRIPTOR.size() && selector >= 0 ? PARAM_DESCRIPTOR[selector] : "";
    }

    std::string Help::general_message_descriptor(std::size_t selector)
    {
        return selector < GENERAL_MESSAGE.size() && selector >= 0 ? GENERAL_MESSAGE[selector] : "";
    }
}
