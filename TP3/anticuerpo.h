#ifndef ANTICUERPO_H
#define ANTICUERPO_H

#include <string>
#include <stdlib.h>
#include <time.h>
#include "elemento.h"

class Anticuerpo : public Elemento {
    public:
        Anticuerpo();
        Anticuerpo(std::string tipo, float posicion_x, float posicion_y);
        std::string resumen_datos();
        std::string detalles_datos();
        float posicion_aleatoria_x ();
        float posicion_aleatoria_y ();
};

#endif // ANTICUERPO_H
