#include "wermz.h"

Wermz::Wermz(bool debug)
{
    logger = new Logger(debug);
    logger->print("Running Wermz()");
}

Wermz::~Wermz()
{
    logger->print("Running ~Wermz()");
    delete logger;
}

bool Wermz::init()
{
    bool result = true;
    logger->print("Running init()");
    return result;
}

bool Wermz::run()
{
    bool result = true;
    logger->print("Running run()");
    return result;
}

bool Wermz::quit()
{
    bool result = true;
    logger->print("Running quit()");
    return result;
}
