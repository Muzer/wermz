#include "wermz.h"

Wermz::Wermz(bool debug)
{
    logger = new Logger(debug);
    logger->print("Running Wermz()");
#if defined WIN32 || defined WIN64
    data_path = string(getenv("APPDATA")) + "\\wermz";
#else
    data_path = string(getenv("HOME")) + "/.wermz";
#endif
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
    logger->print("Parsing constants.ini...");
    parse_constants_init();
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

void Wermz::parse_constants_init()
{
    ifstream file;
    file.open("data/constants.ini");
    string line;
    string dict;
    if (file.is_open())
    {
        while (! file.eof())
        {
            getline(file, line);
            if (line[0] == '[' && line[line.length() - 1] == ']')
            {
                dict = line.substr(1, line.length() - 2);
                dictionaries[dict] = Dictionary();
            }
            else
            {
                if (line.find("=", 0) != string::npos)
                {
                    string var;
                    string res;
                    var = line.substr(0, line.find("=", 0));
                    res = line.substr(line.find("=", 0) + 1, line.length() - 1);
                    logger->print(dict + ": [" + var + ":" + res + "]");
                    dictionaries[dict].dict[var] = res;
                }
            }
        }
    }
    else
    {
        cout << "ERROR: Unable to open constants.ini." << endl;
        exit(1);
    }
    file.close();
}
