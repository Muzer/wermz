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
    string str;
    ifstream file;
    file.open("data/constants.ini");
    string line;
    if (file.is_open())
    {
        while (! file.eof())
        {
            getline(file, line);
            if (line[0] == '[' && line[line.length() - 1] == ']')
            {
                cout << line << endl;
            }
        }
    }
    else
    {
        cout << "ERROR: Unable to open constants.ini." << endl;
        exit(1);
    }
    // >> Set dict_name if [dict_name]
    // >> Set variable_name if variable_name=hello
    // >> Set str to whatever you have done.
    logger->print(str);
    // Close File
}
