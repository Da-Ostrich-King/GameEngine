#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include "ResourceManager.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>


namespace Engine {
    class Core;
}

class Engine::Core {
public:
    Core();
    virtual ~Core();
    virtual int init();
    virtual void processKeyboardEvents();

    // List of which keys are pressed
    bool KEY[322];
    // List of which mod-keys are pressed
    bool MOD[12];

    // Current FPS
    int FPS;
    // Current target FPS
    int targetFPS;
    // Is quit pressed
    bool quitPressed = false;

    ResourceManager resourceManager;


private:
    SDL_Renderer* renderer;
    // SDL event handler
    SDL_Event event;
    // Main SDL window
    SDL_Window* window;
};

#endif