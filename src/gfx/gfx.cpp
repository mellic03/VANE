#include <vane/gfx/gfx.hpp>


uint32_t create_texture( int w, int h, void *data )
{
    GLuint tex;

    gl::CreateTextures(GL_TEXTURE_2D, 1, &tex);
    
    gl::TextureStorage2D(tex, 1, GL_RGBA8, w, h);
    gl::TextureSubImage2D(tex, 0, 0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, data);

    gl::TextureParameteri(tex, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    gl::TextureParameteri(tex, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    gl::TextureParameteri(tex, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    gl::TextureParameteri(tex, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // gl::GenerateTextureMipmap(tex);

    return tex;
}


void test_framebuffer()
{
    GLuint fb;

    // gl::CreateFramebuffers(1, &fb);

    // gl::NamedFramebufferTexture(fb, GL_COLOR_ATTACHMENT0, tex, 0);
    // gl::NamedFramebufferTexture(fb, GL_DEPTH_ATTACHMENT, depthTex, 0);

    // GLuint res = gl::CheckNamedFramebufferStatus(fb, GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE;
    // if (res != 0)
    // {
    //     std::cerr << "framebuffer error\n";
    // }
}


void test_vao_ibo()
{
    GLint alignment = GL_NONE;
    gl::GetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, &alignment);

    GLuint vao = GL_NONE;
    GLuint ibo = GL_NONE;

    // auto const ind_len = GLsizei(ind_count * sizeof(element_t));
    // auto const vrt_len = GLsizei(vrt_count * sizeof(vertex));

    // auto const ind_len_aligned = align(ind_len, alignment);
    // auto const vrt_len_aligned = align(vrt_len, alignment);

    // auto const ind_offset = vrt_len_aligned;
    // auto const vrt_offset = 0;

    // glCreateBuffers(1, &ibo);
    // glNamedBufferStorage(ibo, ind_len_aligned + vrt_len_aligned, nullptr, GL_DYNAMIC_STORAGE_BIT);

    // glNamedBufferSubData(ibo, ind_offset, ind_len, ind_data);
    // glNamedBufferSubData(ibo, vrt_offset, vrt_len, vrt_data);

    // glCreateVertexArrays(1, &vao);
    // glVertexArrayVertexBuffer(vao, 0, ibo, vrt_offset, sizeof(vertex));
    // glVertexArrayElementBuffer(vao, ibo);

    //continue with setup
}