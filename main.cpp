#include "wermz.h"

void print_help()
{
    cout << "wermz [args]" << endl;
    cout << "-h    Help" << endl;
    cout << "-d    Debug" << endl;
    exit(0);
}

int main(int argc, char *argv[])
{
    bool d = false;
    if (argc == 1)
    {
        d = false;
    }
    else
    {
        int i;
        for (i = 1; i < argc; i++)
        {
            if (string(argv[i]) == "-h" or string(argv[i]) == "--help")
            {
                print_help();
            }
            else if (string(argv[i]) == "-d" or string(argv[i]) == "--debug")
            {
                d = true;
            }
            else
            {
                cout << "Flag " << argv[i] << " has been ignored because it does not mean anything." << endl;
            }
        }
    }
    Wermz game(d);
    game.init();
    game.run();
    game.quit();
}
