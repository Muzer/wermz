#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <map>
#include <string>

#include "constants.h"

using namespace std;

class Dictionary
{
public:
    Dictionary();
    map<string, string> dict;
};

#endif
