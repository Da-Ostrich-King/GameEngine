#ifndef GAME_HPP
#define GAME_HPP

#include "../../include/Core.hpp"

class Game : public Engine::Core {
public:
    Game();
    void initGameLoop();

private:
    bool isGame = true;
};

#endif