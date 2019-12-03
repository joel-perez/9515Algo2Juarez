#ifndef CELULA_H
#define CELULA_H

#include <string>
#include "constantes.h"
#include "elemento.h"

class Celula : public Elemento {
    public:
        //PRE: -
        //POST: genera una celula
        Celula();
        //PRE: -
        //POST: genera una celula
        Celula(std::string tipo, float posicion_x, float posicion_y,
               unsigned int indice_celula, int cantidad_enzimas, int cantidad_proteinas,
               bool material_genetico_es_adn, bool es_pluricelular);
        //PRE: -
        //POST: genera una celula
        Celula(std::string tipo, float posicion_x, float posicion_y, unsigned int indice_celula);
        // PRE -
        // POST: devuelve indice_celula
        unsigned int obtener_indice_celula();
        // PRE: -
        // POST: imprime por pantalla un resumen de sus datos
        std::string resumen_datos();
        // PRE: -
        // POST: imprime por pantalla detalles de los datos
        std::string detalles_datos();

    protected:
        unsigned int indice_celula;
        int cantidad_enzimas;
        int cantidad_proteinas;
        bool material_genetico_es_adn;
        bool es_pluricelular;
};

#endif // CELULA_H
