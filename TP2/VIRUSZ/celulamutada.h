#ifndef CELULAMUTADA_H
#define CELULAMUTADA_H

#include "celulainflamada.h"


class CelulaMutada : public CelulaInflamada {
    private:
        float porcentaje_mutacion;
    public:
        CelulaMutada();
        std::string resumen_datos();
        std::string detalles_datos();
        virtual ~CelulaMutada();
};

#endif // CELULAMUTADA_H
