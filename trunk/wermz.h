#ifndef WERMZ_H
#define WERMZ_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>

#if defined WIN32 || defined WIN64
#include "win_funcs.h"
#else
#include "lin_funcs.h"
#endif

#include "constants.h"
#include "logger.h"

#include "SDL.h"
#include "SDL_opengl.h"

using namespace std;

class Wermz
{
public:
    Wermz(bool debug);
    ~Wermz();
    bool init();
    bool run();
    bool quit();
    void parse_constants_init();
    void init_sdl();
    GLuint get_texture(string path);
    bool main_menu();
    
private:
    Logger *logger;
    string data_path;
    SDL_Surface *screen;
};

#endif
