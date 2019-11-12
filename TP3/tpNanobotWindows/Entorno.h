#ifndef ENTORNO_H
#define ENTORNO_H

#include "Textura.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "ImageLoader.h"

enum imagenes{FONDO,NANOBOT,CELULA_S,CELULA_X,CELULA_Y,CELULA_Z,ANTICUERPO,DOSIS_A,DOSIS_B};
enum dosis{A,B};

class Entorno
{
    private:

    SDL_Window* window;
    SDL_Renderer* renderer;
    ImageLoader* loaderA;
    ImageLoader* loaderB;
    Textura texturas[9];
    int estadoDosisA,estadoDosisB;

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

};

#endif // ENTORNO_H
