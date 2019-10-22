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
        Suero();
        Suero(std::string tipo, float posicion_x, float posicion_y, TipoDosis tipo_dosis, int cantidad_dosis);
        Suero(TipoDosis tipo_dosis, int cantidad_dosis);
        std::string resumen_datos();
        std::string detalles_datos();
        virtual ~Suero();

    protected:
};

#endif // SUERO_H
