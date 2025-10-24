#pragma once

#include <cstddef>
#include <cstdint>


namespace vane
{
    class VaneApp;
    class Platform;

    // int vmain( int argc, char **argv, VaneApp* );
}


class vane::VaneApp
{
private:

public:
    bool      mRunning;
    uint64_t  mTicksCurr;
    uint64_t  mTicksPrev;
    Platform *mPlatform;

    static int va_entry( int argc, char **argv, VaneApp *V );

    VaneApp( Platform *p )
    :   mRunning(true), mTicksCurr(0), mTicksPrev(0), mPlatform(p) {  }
    VaneApp( const VaneApp& ) = delete;
    VaneApp( VaneApp&& ) = delete;
    VaneApp &operator=( VaneApp&& ) = delete;
    VaneApp &operator=( const VaneApp& ) = delete;
    virtual ~VaneApp() = default;

    bool running() { return mRunning; }
    virtual void update() = 0;
    virtual int startup(int, char**) = 0;
    virtual int shutdown() = 0;

    double   tsec()  { return double(mTicksCurr) / 1000.0; }
    uint64_t tmsec() { return mTicksCurr; }

};


namespace vane
{
    const auto &vmain = VaneApp::va_entry;
}
