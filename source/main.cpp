#include <App.h>

int main(const int argc, char** argv)
{
    App app;
    app.Start(argc,argv);

    return app.GetExitCode();
}
