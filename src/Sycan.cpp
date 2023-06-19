#include "Sycan.h"
#include <SDL2/SDL.h>
#include <CommandLib/CommandScheduler.h>
#include <CommandLib/Command.h>
#include <iostream>
#include <unistd.h>

using namespace Sycan;

Engine* Engine::engine = nullptr; 

Engine* Engine::getEngine(){
    return engine;
}

Engine::Engine(const char *name, int width, int height)
{
    if(engine == nullptr)
        engine = this;
    else
        return;

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(renderer, width, height);
}

void Engine::run()
{
    running = true;
    while (running)
    {
        // Handle window events, including input and similar.
        HandleWindowEvents();
        // Run the command scheduler, aka, main game update loop.
        Commands::CommandScheduler::getInstance().run();
        // Run the renderer, 
        Render();
    }
}

void Engine::HandleWindowEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        
        default:
            break;
        }

    }

}

void Engine::Render()
{
        SDL_RenderClear(renderer);
        for (int i = 0; i < objects.size(); i++)
        {
            SDL_RenderCopy(renderer, objects.at(i).textureProvider.getTexture(), NULL, NULL);
        }
        SDL_RenderPresent(renderer);

        int frameTime = SDL_GetPerformanceCounter() - lastFrameCount;
        lastFrameCount = SDL_GetPerformanceCounter();
        float elapsed = frameTime / (float)SDL_GetPerformanceFrequency();   
        frameCount += 1;
        if (frameCount == 0) return;
        avgFPS += 1/elapsed;
        std::cout << avgFPS/frameCount << std::endl;  
}

Engine::~Engine()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Engine::addObject(Object object){
    objects.push_back(object);
}