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
    Wermz *game;
    if (argc == 1)
    {
        game = new Wermz(false);
    }
    else if (argc == 2)
    {
        if (string(argv[1]) == "-h")
        {
            print_help();
        }
        else if (string(argv[1]) == "-d")
        {
            game = new Wermz(true);
        }
        else
        {
            cout << "Flag " << argv[1] << " has been ignored because it does not mean anything." << endl;
            game = new Wermz(false);
        }
    }
    else
    {
        cout << "Some flags have been ignored because they did not mean anything." << endl;
        game = new Wermz(false);
    }
    game->init();
    game->run();
    game->quit();
    delete game;
}
