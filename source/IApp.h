#pragma once
#include <functional>
#include <CLI/CLI.hpp>
#include "Ihelp.h"
#include "IFile.h"
#include <memory>

namespace app
{
    class IApp
    {
    public:
        virtual ~IApp() = default;

        std::function<void()> current_version;
        virtual int get_exit_code()             = 0;
        virtual int start(int argc,char **argv) = 0;
        virtual void message()                  = 0;
        std::unique_ptr<CLI::App> Arg_parser;

        const char* version                         = nullptr;
        std::unique_ptr<help::Ihelp> Help_menu      = nullptr;
        std::unique_ptr<wrappers::file::IFile> File = nullptr;
    };
}
