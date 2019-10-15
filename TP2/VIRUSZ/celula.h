#ifndef CELULA_H
#define CELULA_H

#include "elemento.h"


class Celula : public Elemento {
    public:
        Celula();
        std::string resumen_datos();
        std::string detalles_datos();
        virtual ~Celula();

    protected:

    private:
        int tamanio_x;
        int tamanio_y;
        int cantidad_enzimas;
        int cantidad_proteinas;
        bool material_genetico_es_adn;
        bool es_pluricelular;
};

#endif // CELULA_H
