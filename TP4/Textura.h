#ifndef TEXTURA_H
#define TEXTURA_H

#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

class Textura {
public:
    // Inicializa variables
    Textura();

    // Libera memoria.
    ~Textura();

    // Carga una imagen de la ruta especificada.
    bool cargar_desde_archivo(std::string path, SDL_Renderer *renderer);

    // Libera la textura de la memoria.
    void free();

    // Renderiza la textura en el punto dado.
    void render(int x, int y, int renderWidth, int renderHeight, SDL_Renderer *renderer, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    // Devuelve el ancho de la imagen.
    int getWidth();

    // Devuelve el alto de la imagen.
    int getHeight();

    // Establece modulación de color.
    void setColor(Uint8 red, Uint8 green, Uint8 blue);

private:
    //The actual hardware texture
    SDL_Texture *textura;

    // Ancho de la imagen
    int width;
    
    // Alto de la imagen.
    int height;
};

#endif //TEXTURA_H
