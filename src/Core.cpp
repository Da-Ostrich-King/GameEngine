#include "../include/Core.hpp"
#include "../include/GameEngineException.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>

#include <iostream>


// c'tor
Engine::Core::Core() {
    // Initialize core engine components
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "FATAL: FAILED SDL_Init\n";
        // throw with exception if SDL initialization fails
        throw Engine::Exception("SDL_INIT_FAIL");
    }

    // initialize all KEY's to false
    for (int i = 0; i < 322; i++) {
        KEY[i] = false;
    }

    // initialize all MOD's to false
    for (int i = 0; i < 12; i++) {
        MOD[i] = false;
    }
}

// Process all keyboard events
void Engine::Core::processKeyboardEvents() {
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            // Check if the quit button is pressed (or equivilent)
            case SDL_QUIT:
                quitPressed = true;
                break;
            // check if the current key is down
            case SDL_KEYDOWN:
                // set current key to true ie pressed
                KEY[event.key.keysym.sym] = true;
                break;
            case SDL_KEYUP:
                // do opposite
                KEY[event.key.keysym.sym] = false;
                break;
            default:
                break;
        }
    }
}

// initialize all resources

int Engine::Core::init() {

    
    return 0;
}