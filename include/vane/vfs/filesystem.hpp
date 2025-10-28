#pragma once

#include <cstddef>
#include <cstdint>
#include "archive.hpp"
// #include <map>
// #include <string>
// #include <vector>
// #include <functional>

namespace vanefs
{
    using File = void*;
    class iFileReader;
    class iFileWriter;
    class iFileSystem;
    class PkgFsReader;
    class StdFsReader;
    class StdFsWriter;
}



// class vanefs::File
// {
// public:

// private:
//     friend class vanefs::FileFactory;
//     iFileSystem *mFileSystem;
//     void  *mBase;
//     size_t mSize;

//     File( iFileSystem *f, void *b, size_t s )
//     :   mFileSystem(f), mBase(b), mSize(s) {  }
//     // ~File() {  };

// };

class vanefs::iFileReader
{
public:
    virtual bool exists( const char* ) = 0;
    virtual File open( const char* ) = 0;
    virtual size_t read( File, size_t offset, void *dst, size_t n ) = 0;
    virtual size_t size( File ) = 0;

private:

};


class vanefs::iFileWriter: public vanefs::iFileReader
{
public:
    virtual size_t write( File, size_t offset, void *src, size_t n ) = 0;

private:

};


class vanefs::iFileSystem
{
private:
    iFileReader *mReader;
    iFileWriter *mWriter;

public:
    iFileSystem( iFileReader *r=nullptr, iFileWriter *w=nullptr )
    :   mReader(r), mWriter(w) {  }
    bool exists(const char *s){ return mReader->exists(s); }
    File open(const char *s) { return mReader->open(s); }
    size_t size(File f) { return mReader->size(f); }
    size_t read(File f, size_t o, void *d, size_t n) { return mReader->read(f, o, d, n); }
    size_t write(File f, size_t o, void *s, size_t n) { return mWriter->write(f, o, s, n); }

};




class vanefs::PkgFsReader: public iFileReader
{
public:
    PkgFsReader( const char *pkgpath );
    virtual bool exists( const char* ) final;
    virtual File open( const char* ) final;
    virtual size_t read( File, size_t offset, void *dst, size_t n ) final;
    virtual size_t size( File ) final;
    void *base( File );

private:
    vane::PkgArchive mArchive;

};


class vanefs::StdFsReader: public iFileReader
{
public:
    virtual bool exists( const char* ) final;
    virtual File open( const char* ) = 0;
    virtual size_t read( File, size_t, void *dst, size_t n ) final;

private:

};


class vanefs::StdFsWriter: public iFileWriter
{
public:
    virtual size_t write( File, size_t, void*, size_t ) final;
private:
};

