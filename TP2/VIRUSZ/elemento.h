#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <string>

class Elemento
{
    private:
        int posicionX;
        int posicionY;

    public:
        Elemento();
        virtual ~Elemento();
        std::string resumen_datos();
        std::string detalles_datos();

    protected:
        //TODO: Ver si aca van las variables que pusimos en private.
};

#endif // ELEMENTO_H
