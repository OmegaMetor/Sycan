#include "Sycan.h"
#include <SDL2/SDL.h>
#include <CommandLib/CommandScheduler.h>

using namespace Sycan;

Engine::Engine(const char *name, int width, int height)
{
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
        HandleWindowEvents();
        Commands::CommandScheduler::getInstance().run();
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
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);

}

Engine::~Engine()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}
