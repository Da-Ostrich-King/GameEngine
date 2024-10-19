#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>

#include <map>
#include <string>
#include <memory>

namespace Engine {
    class ResourceManager;
}

class Engine::ResourceManager {
    std::map<std::string, std::shared_ptr<SDL_Texture>> textures;
};

#endif