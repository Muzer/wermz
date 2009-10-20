#include "logger.h"

Logger::Logger(bool d)
{
    debug = d;
}

Logger::~Logger()
{
}

void Logger::print(string str)
{
    if (debug)
    {
        cout << "DEBUG: " << str << endl;
    }
}
