#include <CLI/CLI.hpp>
#include "Help.h"
#include "FileComputation.h"


namespace Izip
{
    class App
    {
    public:
        App();
        ~App() = default;
        App(App&)              = delete;
        App(App&&)             = delete;
        App&& operator=(App&&) = delete;
        App& operator=(App&)   = delete;

        int get_exit_code();
        int start(int argc, char **argv) const;

        std::unique_ptr<CLI::App> Arg_parser;

    private:
        // Properties
        Wrappers::CompFile::FileComputation& File = Wrappers::CompFile::FileComputation::getInstance();
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
