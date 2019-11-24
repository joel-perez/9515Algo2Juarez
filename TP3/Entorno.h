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
    float nanobot_pos_x;
    float nanobot_pos_y;
    Tejido* tejido;
    Lista<CoordenadasRelacion*>* coordenadas_relaciones;

    public:
        Entorno();
        ~Entorno();
        void cargarTexturas();
        void renderizar(imagenes imagen, float x, float y);
        bool iniciar(const char *titulo, int xPos, int yPos, int flags);
        void renderizarTodo();
        void limpiar();
        void explotarDosis(dosis dosis);
        bool dosisAExplotando();
        bool dosisBExplotando();
        void dibujar_lineas_entre_celulas();
        void dibujar_celulas();
        void dibujar_dosis();
        float obtener_nanobot_pos_x();
        float obtener_nanobot_pos_y();
        void cambiar_nanobot_pos_x(int x);
        void cambiar_nanobot_pos_y(int y);
};

#endif // ENTORNO_H
