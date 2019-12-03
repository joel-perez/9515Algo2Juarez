#ifndef CELULAMUTADA_H
#define CELULAMUTADA_H

#include <string>
#include "celulainflamada.h"

class CelulaMutada : public CelulaInflamada {
    private:
        float porcentaje_mutacion;
    public:
        //PRE: -
        //POST: genera una celula mutada
        CelulaMutada();
        //PRE: -
        //POST: genera una celula mutada
        CelulaMutada(float porcentaje_mutacion);
        //PRE: -
        //POST: genera una celula mutada
        CelulaMutada(std::string tipo, float posicion_x, float posicion_y,
               unsigned int indice_celula, int cantidad_enzimas, int cantidad_proteinas,
               bool material_genetico_es_adn, bool es_pluricelular,
               float porcentaje_inflamacion, float porcentaje_mutacion);
        //PRE: -
        //POST: genera una celula mutada
        CelulaMutada(std::string tipo, float posicion_x, float posicion_y, unsigned int indice_celula);
        // PRE: -
        // POST: imprime por pantalla un resumen de sus datos
        std::string resumen_datos();
        // PRE: -
        // POST: imprime por pantalla detalles de los datos
        std::string detalles_datos();
};

#endif // CELULAMUTADA_H
