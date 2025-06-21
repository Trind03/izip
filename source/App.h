#include <CLI/CLI.hpp>
#include <memory>
#include "IFile.h"
#include "Ihelp.h"


namespace Izip
{
    class App
    {
    public:
        App();
        ~App()                 = default;
        App(App&)              = delete;
        App(App&&)             = delete;
        App&& operator=(App&&) = delete;
        App& operator=(App&)   = delete;

        int get_exit_code();
        int start(const int argc, char **argv);

        std::unique_ptr<CLI::App> Arg_parser;

    private:
        // Properties
        std::unique_ptr<Izip::Wrappers::CompHelp::Ihelp> Help_menu      = nullptr;
        std::unique_ptr<Izip::Wrappers::CompFile::IFile> File           = nullptr;
        int exit_code = 0;
        static constexpr const char* VERSION  = "1.0";

        // Options
        CLI::Option *OptVersion          = nullptr;
        CLI::Option *OptDecompress       = nullptr;
        CLI::Option *OptCompress         = nullptr;
        CLI::Option *OptRecursive        = nullptr;
        CLI::Option *OptPermissions      = nullptr;
    };
}
