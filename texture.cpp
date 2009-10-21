#include "texture.h"

Texture::Texture(string path, int type)
{
    if (type == 0)
    {
        SDL_Surface *surface;

        if ((surface = IMG_Load(path.c_str())))
        {
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
        height = surface->h;
        width = surface->w;

        if (surface)
        {
            SDL_FreeSurface(surface);
        }
    }
    else if (type == 1)
    {
    }
    else
    {
        cout << "Could not create texture " << path << " because type is not 0 or 1" << endl;
    }
    po2width = pow(2, ceil(log(width) / log(2)));
    po2height = pow(2, ceil(log(height) / log(2)));

    width_ratio = (width / po2width);
    height_ratio = 1 - (height / po2height);
}

Texture::~Texture()
{
    glDeleteTextures(1, &texture);
}

void Texture::draw(int x, int y, int scale, int x_origin, int y_origin, float rotation)
{
    int texwidth = width * scale;
    int texheight = height * scale;

    if (x_origin == 0 && y_origin == 0)
    {
        x_origin = (texwidth / 2) * scale;
        y_origin = (texheight / 2) * scale;
        glLoadIdentity();
        glTranslatef(x, y, 0);

        if (rotation != 0.0)
        {
            glRotatef(rotation, 0, 0, 1);
        }
        glBindTexture(GL_TEXTURE_2D, texture);

        glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0, height_ratio);
        glVertex3f(-x_origin, texheight - y_origin, 0);
        glTexCoord2f(width_ratio, height_ratio);
        glVertex3f(texwidth - x_origin, texheight - y_origin, 0);
        glTexCoord2f(0, 1);
        glVertex3f(-x_origin, -y_origin, 0);
        glTexCoord2f(width_ratio, 1);
        glVertex3f(texwidth -x_origin, -y_origin, 0);
        glEnd();
    }
}
