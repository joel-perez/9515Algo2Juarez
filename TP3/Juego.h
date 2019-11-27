#ifndef JUEGO_H
#define JUEGO_H

#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>

#include "FPSManager.h"
#include "Textura.h"
#include "InputManager.h"
#include "Entorno.h"
#include "tejido.h"
#include "resultadojuego.h"

using namespace std;

class Juego {
private:
    bool running;
    Entorno entorno;

public:
    Juego();
    ~Juego();
    bool iniciar(const char* titulo, int xPos, int yPos, int flags);
    void correr();
    void renderizar();
    void manejar_eventos();
    void limpiar();
    resultado_juego obtener_resultado_juego();
};

#endif //JUEGO_H
