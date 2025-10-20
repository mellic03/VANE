#pragma once


namespace vane
{
    class Renderer;

    class GameScene;
}


class vane::Renderer
{
public:
    Renderer();
    void drawScene( GameScene* );
    void drawObject( GameScene* );

private:

};
