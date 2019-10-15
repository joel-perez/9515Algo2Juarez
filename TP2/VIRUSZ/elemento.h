#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <string>
#include "texto.h"

class Elemento
{
    private:
        int posicion_x;
        int posicion_y;
        std::string tipo;

    public:
        Elemento();
        virtual std::string resumen_datos();
        virtual std::string detalles_datos();
        virtual ~Elemento();

    protected:
        //TODO: Ver si aca van las variables que pusimos en private.
};

#endif // ELEMENTO_H
