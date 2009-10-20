#ifndef WERMZ_H
#define WERMZ_H

#include "logger.h"

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
