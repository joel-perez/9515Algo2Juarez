#ifndef CELULA_H
#define CELULA_H

#include "elemento.h"


class Celula : public Elemento {
    public:
        Celula();
        Celula(string tipo, float posicion_x, float posicion_y,
               int cantidad_enzimas, int cantidad_proteinas,
               bool material_genetico_es_adn, bool es_pluricelular)
        :Elemento(tipo, posicion_x, posicion_y);
        Celula(string tipo, float posicion_x, float posicion_y)
        :Elemento(tipo, posicion_x, posicion_y);
        std::string resumen_datos();
        std::string detalles_datos();

    protected:
        // int tamanio;
        int cantidad_enzimas;
        int cantidad_proteinas;
        bool material_genetico_es_adn;
        bool es_pluricelular;
};

#endif // CELULA_H
