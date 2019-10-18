#ifndef ANTICUERPO_H
#define ANTICUERPO_H

#include <string>
#include "elemento.h"

class Anticuerpo : public Elemento {
    public:
        Anticuerpo();
        Anticuerpo(std::string tipo, float posicion_x, float posicion_y);
        std::string resumen_datos();
        std::string detalles_datos();
};

#endif // ANTICUERPO_H
