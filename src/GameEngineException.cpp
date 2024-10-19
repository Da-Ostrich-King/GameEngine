
#include "../include/GameEngineException.hpp"

#include <string>
Engine::Exception::Exception(const char* msg) {
    message = msg;
}

const char* Engine::Exception::what() {
    return message.c_str();
}

