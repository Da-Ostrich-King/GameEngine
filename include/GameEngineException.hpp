#ifndef GAME_ENGINE_EXCEPTION_HPP
#define GAME_ENGINE_EXCEPTION_HPP


#include <exception>
#include <string>

namespace Engine {
    class Exception;
}

class Engine::Exception : std::exception {
public:
    
    Exception(const char* msg);
    const char* what();

private:
    std::string message;
};


#endif