#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <string>
#include "texto.h"

class Elemento {
    protected:
        std::string tipo;
        float posicion_x;
        float posicion_y;

    public:
        Elemento();
        virtual std::string resumen_datos();
        virtual std::string detalles_datos();
        virtual ~Elemento();
};

#endif // ELEMENTO_H
