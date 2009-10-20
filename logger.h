#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

using namespace std;

class Logger
{
public:
    Logger(bool d);
    ~Logger();
    void print(string str);

private:
    bool debug;
};

#endif
