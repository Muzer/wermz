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

/*    GLuint texture; // Texture object handle
    SDL_Surface *surface; // Gives us the information to make the texture

    if ( (surface = SDL_LoadBMP("image.bmp")) ) {

        // Check that the image's width is a power of 2
        if ( (surface->w & (surface->w - 1)) != 0 ) {
            printf("warning: image.bmp's width is not a power of 2\n");
        }

        // Also check if the height is a power of 2
        if ( (surface->h & (surface->h - 1)) != 0 ) {
            printf("warning: image.bmp's height is not a power of 2\n");
        }

        // Have OpenGL generate a texture object handle for us
        glGenTextures( 1, &texture );

        // Bind the texture object
        glBindTexture( GL_TEXTURE_2D, texture );

        // Set the texture's stretching properties
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

        // Edit the texture object's image data using the information SDL_Surface gives us
        glTexImage2D( GL_TEXTURE_2D, 0, 3, surface->w, surface->h, 0,
                      GL_BGR, GL_UNSIGNED_BYTE, surface->pixels );
    }
    else {
        printf("SDL could not load image.bmp: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Free the SDL_Surface only if it was successfully created
    if ( surface ) {
        SDL_FreeSurface( surface );
    }

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
*/
    SDL_GL_SwapBuffers();

    // Wait for 3 seconds to give us a chance to see the image
    SDL_Delay(3000);

    // Now we can delete the OpenGL texture and close down SDL
    //glDeleteTextures( 1, &texture );

    SDL_Quit();
}

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
