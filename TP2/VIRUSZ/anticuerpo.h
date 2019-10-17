#ifndef ANTICUERPO_H
#define ANTICUERPO_H

#include "elemento.h"

class Anticuerpo : public Elemento {
    public:
        Anticuerpo();
        Anticuerpo::Anticuerpo(string tipo, float posicion_x, float posicion_y):
        Elemento(tipo, posicion_x, posicion_y);
        std::string resumen_datos();
        std::string detalles_datos();
};

#endif // ANTICUERPO_H
