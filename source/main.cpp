#include <App.h>

int main(const int argc, char** argv)
{
    App app;
    app.start(argc,argv);

    return app.get_exit_code();
}
