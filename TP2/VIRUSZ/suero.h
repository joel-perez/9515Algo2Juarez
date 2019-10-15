#ifndef SUERO_H
#define SUERO_H

#include "elemento.h"


class Suero : public Elemento
{

    private:
        int cantidadDosis;
        //TipoDosis tipoDosis; // enum

    public:
        Suero();
        std::string resumen_datos();
        std::string detalles_datos();
        virtual ~Suero();

    protected:
};

#endif // SUERO_H
