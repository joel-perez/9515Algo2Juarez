#ifndef CELULAINFLAMADA_H
#define CELULAINFLAMADA_H

#include "celula.h"


class CelulaInflamada : public Celula {
private:
    float porcentaje_inflamacion;
public:
    CelulaInflamada();
    std::string resumen_datos();
    std::string detalles_datos();
    virtual ~CelulaInflamada();

protected:
};

#endif // CELULAINFLAMADA_H
