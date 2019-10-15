#ifndef SUERO_H
#define SUERO_H

#include "elemento.h"


class Suero : public Elemento {

    private:
        int cantidad_dosis;

    public:
        Suero();
        std::string resumen_datos();
        std::string detalles_datos();
        virtual ~Suero();

    protected:
};

#endif // SUERO_H
