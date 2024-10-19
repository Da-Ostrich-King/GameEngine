// All paths are relative "tbuild" executable, ideally placed at project root
#pragma once
// DEFAULT CONFIGURATION
// MOVE THE TINYBUILD DIRECTORY TO THE ROOT OF THE PROJECT AND THIS FROM THE TINYBUILD DIRECTORY TO THE ROOT OF THE PROJECT
// FOR MORE INFORMATION GO TO REAMDE.md
//
// FOR LICENSE INFORMAITION GO TO LICENSE
// IF I WAS STUPID AND FORGOT TO PUT A LICENSE, REFER TO https://www.gnu.org/licenses/gpl-3.0.en.html#license-text FOR LICENSE INFORMATION

// This is the actual config for "GAMEENGINE?", other one is tinybuild default config

#include "defines.hpp"
#include <cstdlib>
#include <string>
#include <filesystem>
#include <format>
#include <iostream>

#define BUILDDIR "./build"
#define EXTENSION "cpp"

#define TINYBUILD_SOURCE_PATH "./tinybuild/tinybuild"
#define REBUILD_COMMAND "g++ {} -o {} --std=c++20 -I. -Itinybuild/tinybuild"

// yell at me i dont care
void buildLib () {
    // override build command completely
    std::string srcFiles;
    std::filesystem::path srcdir(std::string("./src"));
    for (const std::filesystem::directory_entry& file : std::filesystem::directory_iterator(srcdir)) { // get every file in src dir
        if (file.path().generic_string().substr(file.path().generic_string().find_last_of(".") + 1) == std::string(EXTENSION)) {
            srcFiles += std::string(file.path().generic_string()); srcFiles += " ";
        }
    }    
    std::cout << "Build Command: " << std::format(
        "g++ -L/usr/lib -lSDL2 -I/usr/include/SDL2 -D_REENTRANT -lSDL2_image -lm -c -fPIC -shared -o build/lib/libgameengine.so {}\n", 
        srcFiles).c_str();


    std::system(std::format (
        "g++ -L/usr/lib -lSDL2 -I/usr/include/SDL2 -D_REENTRANT -lSDL2_image -lm -c -fPIC -shared -o build/lib/libgameengine.so {}\n", 
        srcFiles).c_str());
}

// build config
const BuildConfig configs[] = {
    {
        .name="lib",
        .CC="g++",
        .MAKEBUILDDIR=true,
        .initFunction=buildLib
    },
    {
        .name="test",
        .CC="g++",
        .binarys={
            {
                .bin="test",
                .srcdirs={"./TestProject/src"},
                .CCFLAGS="-L./build/lib -lgameengine"
            }
        },
        .MAKEBUILDDIR=true,
        .initFunction=nullptr
    }
};



// View defines.hpp for more information (if there isnt the information, too bad)