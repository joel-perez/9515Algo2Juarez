#ifndef CELULAINFLAMADA_H
#define CELULAINFLAMADA_H

#include "celula.h"


class CelulaInflamada : public Celula {
private:
    float porcentajeInflamacion;
public:
    CelulaInflamada();
    virtual ~CelulaInflamada();

protected:
};

#endif // CELULAINFLAMADA_H
