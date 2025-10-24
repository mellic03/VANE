#pragma once

#include "service.hpp"
#include <vector>

namespace vane
{
    class VaneApp;
    void AppEnter( VaneApp&, int, char** );
    void AppExit( VaneApp&, int );

    namespace detail
    {
        struct AppAccess;
    }

    class Platform;
}


class vane::VaneApp
{
private:
    friend struct detail::AppAccess;
    std::vector<VaneService*> mServices;
    Platform &mPlat;
    bool      mRunning;
    int       mExitCode;
    size_t    mTicksCurr;
    size_t    mTicksPrev;

    void _AppEnter( int, char** );
    void _AppExit( int );

public:

    VaneApp( Platform &p )
    :   mPlat(p), mRunning(true), mExitCode(0), mTicksCurr(0), mTicksPrev(0)
    {

    }

    VaneApp( const VaneApp& ) = delete;
    VaneApp( VaneApp&& ) = delete;
    VaneApp &operator=( VaneApp&& ) = delete;
    VaneApp &operator=( const VaneApp& ) = delete;
    virtual ~VaneApp() = default;

    template <typename service_type>
    void addService() { addService(new service_type(*this)); }
    void addService( VaneService* );

    bool running() { return mRunning; }
    void update();

    auto &platform() { return mPlat; }
    size_t appTime() { return mTicksCurr; }
    size_t delTime() { return mTicksCurr-mTicksPrev; }

};

