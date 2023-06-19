#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "Object.h"

namespace Sycan{

class Engine
{
private:
    SDL_Window* window;
    bool running;
    std::vector<Object> objects = {};
    void HandleWindowEvents();
    void Render();
    static Engine* engine;
    int lastFrameCount = 0;
    int avgFPS = 0;
    int frameCount = 0;
public:
    Engine(const char *name, int width, int height);
    void run();
    ~Engine();
    void addObject(Object object);
    static Engine* getEngine();
    SDL_Renderer* renderer;
};



}