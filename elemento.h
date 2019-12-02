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
        //PRE:-
        //POST: genera el elemento
        Elemento();
        //PRE:-
        //POST: genera el elemento
        Elemento(std::string tipo, float posicion_x, float posicion_y);
        //PRE: -
        //POST: retorna en un string los datos del elemento
        virtual std::string resumen_datos();
        //PRE: -
        //POST: retorna en un string los detalle de los datos del elemento
        virtual std::string detalles_datos();
        //PRE: -
        //POST: retorna la posicion x del elemento
        virtual float obtener_posicion_x();
        //PRE: -
        //POST: retorna la posicion y del elemento
        virtual float obtener_posicion_y();
        //PRE: -
        //POST: retorna en un string el tipo de elemento
        virtual std::string obtener_tipo();
        virtual ~Elemento();
};

#endif // ELEMENTO_H
