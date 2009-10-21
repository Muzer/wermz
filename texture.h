#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"
#include "SDL_svg.h"

#include <cmath>
#include <iostream>

using namespace std;

class Texture
{
public:
    Texture(string path, int type); // 0 = image, 1 = vector
    ~Texture();
    void draw(int x = 0, int y = 0, int scale = 1, int x_origin = 0, int y_origin = 0, float rotation = 0.0);

private:
    int type;
    GLuint texture;
    int width;
    int height;
    int po2width;
    int po2height;
    int width_ratio;
    int height_ratio;
};

#endif
