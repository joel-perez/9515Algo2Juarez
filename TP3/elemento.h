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
        Elemento(std::string tipo, float posicion_x, float posicion_y);
        virtual std::string resumen_datos();
        virtual std::string detalles_datos();
        virtual float obtener_posicion_x();
        virtual float obtener_posicion_y();
        virtual std::string obtener_tipo();
        virtual void cambiar_tipo(std::string nuevo);
        virtual ~Elemento();
};

#endif // ELEMENTO_H
