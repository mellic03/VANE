#include <vane/core/app.hpp>
#include <vane/core/platform.hpp>
#include <vane/core/log.hpp>

using namespace vane;


void VaneApp::_AppEnter( int, char** )
{
    while (running())
    {
        update();
    }
}


void VaneApp::_AppExit( int code )
{
    mRunning  = false;
    mExitCode = code;
}


void VaneApp::update()
{
    mTicksPrev = mTicksCurr;
    mTicksCurr = SDL_GetTicksNS();
    mPlat.update();

    for (auto *srv: mServices)
    {
        srv->preUpdate();
    }

    for (auto *srv: mServices)
    {
        srv->update();
    }

    for (auto *srv: mServices)
    {
        srv->postUpdate();
    }

}


void VaneApp::addService( VaneService *srv )
{
    mServices.push_back(srv);
}



struct vane::detail::AppAccess {
    static void app_enter( VaneApp &V, int argc, char **argv )
    { V._AppEnter(argc, argv); }

    static void app_exit( VaneApp &V, int code )
    { V._AppExit(code); }
};

void vane::AppEnter( VaneApp &V, int argc, char **argv )
{ detail::AppAccess::app_enter(V, argc, argv); }

void vane::AppExit( VaneApp &V, int code )
{ detail::AppAccess::app_exit(V, code); }

