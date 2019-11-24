#ifndef ENTORNO_H
#define ENTORNO_H

#include <iostream>
#include "Constants.h"
#include "Textura.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "ImageLoader.h"
#include "tejido.h"

enum imagenes {FONDO, NANOBOT, CELULA_S, CELULA_X, CELULA_Y, CELULA_Z, ANTICUERPO, DOSIS_A, DOSIS_B };
enum dosis { DosisA, DosisB };

class Entorno
{
    private:

    SDL_Window* window;
    SDL_Renderer* renderer;
    ImageLoader* loaderA;
    ImageLoader* loaderB;
    Textura texturas[9];
    int estadoDosisA,estadoDosisB;
    Tejido* tejido;
    Lista<CoordenadasRelacion*>* coordenadas_relaciones;

    public:
        Entorno();
        ~Entorno();
        void cargarTexturas();
        void renderizar(imagenes imagen,float x, float y);
        bool iniciar(const char *titulo, int xPos, int yPos, int flags);
        void renderizarTodo();
        void limpiar();
        void explotarDosis(dosis dosis);
        bool dosisAExplotando();
        bool dosisBExplotando();
        void dibujar_lineas_entre_celulas();
        void dibujar_celulas();
        void dibujar_dosis();

    float nanobot_pos_x = 0;                              // TODO: Mejorar esto...
    float nanobot_pos_y = SCREEN_HEIGHT - NANOBOT_HEIGHT; // TODO: Mejorar esto...

};

#endif // ENTORNO_H
