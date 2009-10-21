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
    delete screen;
}

bool Wermz::init()
{
    bool result = true;
    logger->print("Running init()");
    logger->print("Parsing constants.ini...");
    parse_constants_init();
    logger->print("Initialising SDl and OpenGL...");
    init_sdl();
    return result;
}

bool Wermz::run()
{
    bool result = true;
    logger->print("Running run()");
    while (result)
    {
        if (!main_menu())
        {
            result = false;
        }
    }
    return result;
}

bool Wermz::main_menu()
{
    bool running = true;
    GLuint logo = get_texture("data/misc/logo.svg");
    while (running)
    {
        SDL_GL_SwapBuffers();
    }
    glDeleteTextures(1, &logo);
    return true;
}

bool Wermz::quit()
{
    bool result = true;
    logger->print("Running quit()");
    SDL_Quit();
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

void Wermz::init_sdl()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cout << "Unable to initialise SDL: " << SDL_GetError() << endl;
        exit(1);
    }
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    screen = SDL_SetVideoMode(800, 600, 16, SDL_OPENGL | SDL_DOUBLEBUF );
    if (!screen)
    {
        cout << "Unable to set video mode: " << SDL_GetError() << endl;;
        exit(1);
    }
    glClearColor(0, 0, 0, 0);
    glEnable(GL_TEXTURE_2D);

    glViewport(0, 0, 800, 600);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, 800, 600, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

GLuint Wermz::get_texture(string path)
{
    GLuint texture;
    SDL_Surface *surface;

    if ((surface = SDL_LoadBMP(path.c_str())))
    {
        if ((surface->w & (surface->w - 1)) != 0)
        {
            logger->print(path + "'s width is not a power of 2");
        }
        if ((surface->h & (surface->h - 1)) != 0)
        {
            logger->print(path + "'s height is not a power of 2");
        }
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, surface->w, surface->h, 0, GL_BGR, GL_UNSIGNED_BYTE, surface->pixels);
    }
    else
    {
        cout << "Could not load image " << path << ": " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (surface)
    {
        SDL_FreeSurface(surface);
    }
    return texture;
}
/*

    // Clear the screen before drawing
        glClear( GL_COLOR_BUFFER_BIT );

    // Bind the texture to which subsequent calls refer to
    glBindTexture( GL_TEXTURE_2D, texture );

    glBegin( GL_QUADS );
        // Top-left vertex (corner)
        glTexCoord2i( 0, 0 );
        glVertex3f( 100, 100, 0 );

        // Bottom-left vertex (corner)
        glTexCoord2i( 1, 0 );
        glVertex3f( 228, 100, 0 );

        // Bottom-right vertex (corner)
        glTexCoord2i( 1, 1 );
        glVertex3f( 228, 228, 0 );

        // Top-right vertex (corner)
        glTexCoord2i( 0, 1 );
        glVertex3f( 100, 228, 0 );
    glEnd();


    // Wait for 3 seconds to give us a chance to see the image
    // Now we can delete the OpenGL texture and close down SDL
    */

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
