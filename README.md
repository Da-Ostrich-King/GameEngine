*go away
```
make build
make lib
make test
```

To use this "library", make a game.cpp file that says something like this
```
#ifndef GAME_HPP
#define GAME_HPP

#include <GameEngine/GameEngine.hpp>

class Game : public Engine::GameEngine {
public:
    Game();
    void initGameLoop();
};

#endif
```

to build this library only run ```make build``` to make the build system and ```make lib``` to actually build the library. Copy everything in ```include``` to a folder in an include path (/usr/include/, or specify an include directory with ```-I/path/to/includedir```), and link with the .so file by copying it to a lib dir (/usr/lib/, or specify it with ```-L/path/to/libGameEngine.so```). Link the library with ```-lGameEngine```