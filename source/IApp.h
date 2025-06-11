#pragma once
#include <functional>
#include <CLI/CLI.hpp>
#include "Ihelp.h"
#include "IFile.h"
#include <memory>

namespace Izip
{
    class IApp
    {
    public:
        virtual ~IApp() = default;
        std::function<void()> current_version;
        virtual int get_exit_code()             = 0;
        virtual int start(const int argc,char **argv) = 0;
        std::unique_ptr<CLI::App> Arg_parser;
        const char* version                                  = nullptr;
        std::unique_ptr<Wrappers::CompHelp::Ihelp> Help_menu = nullptr;
        std::unique_ptr<Wrappers::CompFile::IFile> File      = nullptr;

         // Options
        CLI::Option *OptVersion          = nullptr;
        CLI::Option *OptDecompress       = nullptr;
        CLI::Option *OptCompress         = nullptr;
        CLI::Option *OptRecursive        = nullptr;
        CLI::Option *OptPermissions      = nullptr;
    };
}
