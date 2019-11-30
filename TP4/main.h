#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

// En SDL_main.h se define la funcion SDL_SetMainReady(), junto con la regla
// del preprocesador que redefine main() como SDL_main().
// Por lo tanto, para garantizar que nuestra función main() no va a cambiar,
// es necesario definir SDL_MAIN_HANDLED antes de incluir SDL.h.
#ifdef _WIN32
#define SDL_MAIN_HANDLED
#endif

#include <iostream>
#include "Juego.h"

#endif // MAIN_H_INCLUDED
