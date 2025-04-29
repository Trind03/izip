#include <CLI/CLI.hpp>
#include <functional>
#include "IApp.h"
#include <memory>
#include "IFile.h"
#include "Ihelp.h"



namespace app
{
    class App : public IApp
    {
    public:

        App();
        ~App() override  = default;
        App(App&)        = delete;
        App(App&&)       = delete;

        int get_exit_code()              override;
        void message()                   override;
        int start(int argc, char **argv) override;

        std::unique_ptr<CLI::App> Arg_parser;
    private:

        // Properties
        std::unique_ptr<help::Ihelp> Help_menu           = nullptr;
        std::unique_ptr<wrappers::file::IFile> File      = nullptr;
        std::unique_ptr<wrappers::file::IFile> comp_file = nullptr;
        int exit_code = 0;
    };
}
