#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include "SDL_surface.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>

#include <map>
#include <string>

namespace Engine {
    class ResourceManager;
}

class Engine::ResourceManager {
public:
    ResourceManager();


    // Will overwrite existing texture
    void addTexture(std::string name, std::string path);

private:
    std::map<std::string, SDL_Surface> textures;
};

#endif