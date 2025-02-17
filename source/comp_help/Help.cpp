#include <string>
#include "Help.h"
#include "exit_codes.hpp"

namespace help
{
    std::string Help::param_message_descriptor(int selector)
    {
        return selector < PARAM_MESSAGE_DESCRIPTOR.size() && selector >= 0 ? PARAM_MESSAGE_DESCRIPTOR[selector] : "";
    }

    std::string Help::param_view_descriptor(int selector)
    {
        return selector < PARAM_DESCRIPTOR.size() && selector >= 0 ? PARAM_DESCRIPTOR[selector] : "";
    }
    std::string Help::general_message_descriptor(int selector)
    {
        return selector < GENERAL_MESSAGE.size() && selector >= 0 ? GENERAL_MESSAGE[selector] : "";
    }
}
