#include <memory>
#include "App.h"
#include "IApp.h"

int main(const int argc, char** argv)
{
    const std::unique_ptr<app::IApp> myapp = std::make_unique<app::App>();
    myapp->start(argc,argv);

    return myapp->get_exit_code();
}
