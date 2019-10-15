#ifndef ANTICUERPO_H
#define ANTICUERPO_H

#include "elemento.h"

class Anticuerpo : public Elemento {
    public:
        Anticuerpo();
        std::string resumen_datos();
        std::string detalles_datos();
        virtual ~Anticuerpo();

    protected:

    private:
};

#endif // ANTICUERPO_H
