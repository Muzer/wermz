#ifndef WERMZ_H
#define WERMZ_H

#include <cstdlib>
#include <iostream>

#if defined WIN32 || defined WIN64
#include "win_funcs.h"
#else
#include "lin_funcs.h"
#endif

#include "constants.h"
#include "logger.h"

using namespace std;

#if defined WIN32 || defined WIN64
string data_path = string(getenv("APPDATA")) + "\\wermz";
#else
string data_path = string(getenv("HOME")) + "/.wermz";
#endif

class Wermz
{
public:
    Wermz(bool debug);
    ~Wermz();
    bool init();
    bool run();
    bool quit();
    
private:
    Logger *logger;
};

#endif
