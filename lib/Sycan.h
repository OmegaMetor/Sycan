#pragma once
#include <iostream>
#include <SDL2/SDL.h>


namespace Sycan{

class Engine
{
private:
    SDL_Window* window;
    bool running;
    SDL_Renderer* renderer;
    void HandleWindowEvents();
    void Render();
public:
    Engine(const char *name, int width, int height);
    void run();
    ~Engine();
};



}