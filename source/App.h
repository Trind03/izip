#include <CLI/CLI.hpp>
#include "Help.h"
#include "File.h"


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
        Wrappers::CompHelp::Help& Help_menu = Wrappers::CompHelp::Help::getInstance();
        Wrappers::CompFile::File& File = Wrappers::CompFile::File::getInstance();
        int exit_code = 0;
        static constexpr auto VERSION  = "1.0";

        // Options
        CLI::Option *OptVersion          = nullptr;
        CLI::Option *OptDecompress       = nullptr;
        CLI::Option *OptCompress         = nullptr;
        CLI::Option *OptRecursive        = nullptr;
        CLI::Option *OptPermissions      = nullptr;
    };
}
