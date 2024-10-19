#include "../include/GameEngine.hpp"
#include "../include/GameEngineException.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>

#include <iostream>

Engine::GameEngine::GameEngine() {
    // Initialize core engine components
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "FATAL: FAILED SDL_Init\n";
        throw Engine::Exception("SDL_INIT_FAIL");
    }
}