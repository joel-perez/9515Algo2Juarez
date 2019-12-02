#ifndef SUERO_H
#define SUERO_H

#include <string>
#include "conversiones.h"
#include "elemento.h"
#include "tipodosis.h"

class Suero : public Elemento {

    private:
        TipoDosis tipo_dosis;
        int cantidad_dosis;

    public:
        //PRE: -
        //POST: genera el suero
        Suero();
        //PRE: -
        //POST: genera el suero
        Suero(std::string tipo, float posicion_x, float posicion_y, TipoDosis tipo_dosis, int cantidad_dosis);
        //PRE: -
        //POST: genera el suero
        Suero(TipoDosis tipo_dosis, int cantidad_dosis);
        // PRE  
        // POST: Devuelve un tipo enumerado indicando que tipo de dosis es.
        TipoDosis obtener_tipo_dosis();
        // PRE:  
        // POST: Devuelve la cantidad total de dosis.
        int obtener_cantidad_dosis();
        // PRE: -
        // POST: imprime por pantalla un resumen de sus datos
        std::string resumen_datos();
        // PRE: -
        // POST: imprime por pantalla un detalle de sus datos
        std::string detalles_datos();
        // PRE: -
        // POST: elimina el suero y libera la memoria.
        virtual ~Suero();

    protected:
};

#endif // SUERO_H
