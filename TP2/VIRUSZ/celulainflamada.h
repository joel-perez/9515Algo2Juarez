#ifndef CELULAINFLAMADA_H
#define CELULAINFLAMADA_H

#include "celula.h"


class CelulaInflamada : public Celula {
    protected:
        float porcentaje_inflamacion;
    public:
        CelulaInflamada();
        std::string resumen_datos();
        std::string detalles_datos();
        virtual ~CelulaInflamada();
};

#endif // CELULAINFLAMADA_H
