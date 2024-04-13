#include "graphics/PZ_Window.h"
#include "graphics/PZ_Level.h"

extern "C" {
    _declspec(dllexport) unsigned long NvOptimusEnablement = 1;
    _declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

int main()
{
	Window window("Hello World!", 1280, 720, RendererTypes::OpenGL);
    Level level;
    level.FillTiles(0);

    while (!window.GetWindowCloseEvent())
    {
        window.Update();
        level.Update();
        window.Render();
        level.Render();
    }
}