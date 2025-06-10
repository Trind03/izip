#include <memory>
#include "App.h"
#include "IApp.h"

int main(const int argc, char** argv)
{

    const std::unique_ptr<Izip::IApp> myapp = std::make_unique<Izip::App>();
    myapp->start(argc,argv);

    return myapp->get_exit_code();
}
