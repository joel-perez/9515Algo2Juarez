#ifndef SUERO_H
#define SUERO_H

#include "elemento.h"


class Suero : public Elemento {

    private:
        int cantidadDosis;
        //TipoDosis tipoDosis; // enum

    public:
        Suero();
        virtual ~Suero();

    protected:
};

#endif // SUERO_H
