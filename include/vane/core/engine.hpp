// #pragma once

// #include <cstddef>
// #include <vane/util/reliant.hpp>
// #include <cstdint>

// namespace vane
// {
//     class Engine;
//     class GameWorld;
//     class Platform;
// }

//     Platform *mPlatform;
//     VaneApp  *mVaneApp;
//     bool      mRunning;
//     uint64_t  mTicksCurr;
//     uint64_t  mTicksPrev;
// class vane::Engine
// {
// public:
//     Engine( Platform*, VaneApp* );
//     // ~Engine() {  }
//     Engine( const Engine& ) = delete;
//     Engine( Engine&& ) = delete;
//     Engine &operator=( Engine&& ) = delete;
//     Engine &operator=( const Engine& ) = delete;

//     void   update();
//     void   shutdown() { mRunning = false; }
//     bool   running()  { return mRunning; }
//     double tsec()     { return double(mTicksCurr) / 1000.0; }
//     uint64 tmsec()    { return mTicksCurr; }

//     Platform &getPlatform() { return *mPlatform; }
//     VaneApp  *getVaneApp() { return mVaneApp; }

// private:
//     Platform *mPlatform;
//     VaneApp  *mVaneApp;
//     bool      mRunning;
//     uint64_t  mTicksCurr;
//     uint64_t  mTicksPrev;


// };

