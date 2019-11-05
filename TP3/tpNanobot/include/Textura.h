//
// Created by caropistillo
//

#ifndef TEXTURA_H
#define TEXTURA_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

class Textura {
public:
    //Initializes variables
    Textura();

    //Deallocates memory
    ~Textura();

    //Loads image at specified path
    bool cargarDesdeArchivo(std::string path, SDL_Renderer *renderer);

    //Deallocates texture
    void free();

    //Renders texture at given point
    void render(int x, int y, int renderWidth, int renderHeight, SDL_Renderer *renderer, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    //Gets image dimensions
    int getWidth();

    int getHeight();

    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );

private:
    //The actual hardware texture
    SDL_Texture *textura;

    //Image dimensions
    int width;
    int height;
};


#endif //TEXTURA_H
