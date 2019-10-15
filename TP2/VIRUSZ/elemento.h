#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <string>
#include "texto.h"

class Elemento {
    protected:
        int posicion_x;
        int posicion_y;
        std::string tipo;

    public:
        Elemento();
        virtual std::string resumen_datos();
        virtual std::string detalles_datos();
        virtual ~Elemento();
};

#endif // ELEMENTO_H
