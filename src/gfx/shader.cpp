#include <vane/core/gl.hpp>
#include <vane/gfx/shader.hpp>
#include <vane/core/assert.hpp>
#include <vane/util/file.hpp>
#include <fstream>

using namespace vane;


void gfx::ShaderArchive::openArchive( const std::string &path )
{
    std::string str = loadRaw(path);
    std::string name, data;

    auto *buf = reinterpret_cast<uint8_t*>(&str[0]);
    auto *H = (ArchiveHeader*)buf;
    auto *A = (ArchiveData*)(H->data);

    for (size_t i=0; i<H->nshaders; i++)
    {
        name.resize(A->namesize);
        data.resize(A->datasize);

        memcpy(&name[0], A->data+0, A->namesize);
        memcpy(&data[0], A->data+A->namesize, A->datasize);

        mShaders.push_back({name, data});

        A = (ArchiveData*)(A->data + A->namesize + A->datasize);
    }
}


void gfx::ShaderArchive::saveArchive( const std::string &path )
{
    std::ofstream stream(path, std::ofstream::binary);
    VANE_ASSERT(stream.is_open(), "Error opening file.");

    size_t nshaders = mShaders.size();
    stream.write((const char*)(&nshaders), sizeof(size_t));

    for (auto &[name, data]: mShaders)
    {
        size_t nsize = name.size();
        size_t dsize = data.size();
        stream.write((const char*)(&nsize), sizeof(size_t));
        stream.write((const char*)(&dsize), sizeof(size_t));
        stream.write(name.c_str(), nsize);
        stream.write(data.c_str(), dsize);
    }
}


void gfx::ShaderArchive::addFile( const std::string &path )
{
    mShaders.push_back({path, vane::loadRaw(path)});
}



void rerere()
{
    GLuint prog = gl::CreateProgram();
    GLuint vert = gl::CreateShader(GL_VERTEX_SHADER);
    GLuint frag = gl::CreateShader(GL_FRAGMENT_SHADER);

    std::string vstr = vane::loadRaw("vane/shader/quad.vs");
    std::string fstr = vane::loadRaw("vane/shader/quad.fs");
    const char *vsrc = vstr.c_str();
    const char *fsrc = fstr.c_str();

    gl::ShaderSource(vert, 1, &vsrc, NULL);
    gl::ShaderSource(frag, 1, &fsrc, NULL);

    gl::CompileShader(vert);
    gl::CompileShader(frag);

    gl::AttachShader(prog, vert);
    gl::AttachShader(prog, frag);
    gl::LinkProgram(prog);

}


// #include <vane/core/log.hpp>

// void gfx::ShaderArchive::compileSPIRV( const std::string &src, const std::string &dst )
// {
//     syslog log("ShaderArchive::compileSPIRV");

//     auto &conf = vane::GetConfig();
//     std::string glslc = std::string(conf["path"]["binaries"]) + "/glslc";
//     std::string cmd = glslc + " " + src + " -o " + dst;

//     log("glslc: \"%s\"", glslc.c_str());
//     log("cmd: \"%s\"", cmd.c_str());
//     int res = std::system(cmd.c_str());
//     log("res: %d", res);

//     VANE_ASSERT(res==0, "res!=0, res==%d.", res);
// }

