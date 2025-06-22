#include <string>
#include <Help.h>


namespace Izip::Wrappers::CompHelp
{
    std::string param_message_descriptor(size_t selector)
    {
        if (selector >= helpMessage::PARAM_MESSAGE_DESCRIPTOR.size())
            return "";

        return helpMessage::PARAM_MESSAGE_DESCRIPTOR[selector];
    }

    std::string param_symbol_descriptor(size_t selector)
    {

        if (selector >= helpMessage::PARAM_DESCRIPTOR.size())
            return "";

        return helpMessage::PARAM_DESCRIPTOR[selector];
    }

    std::string general_message_descriptor(size_t selector)
    {
        if (selector >= helpMessage::GENERAL_MESSAGE.size())
            return "";

        return helpMessage::GENERAL_MESSAGE[selector];
    }
}
