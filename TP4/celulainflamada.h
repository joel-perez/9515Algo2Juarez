#ifndef CELULAINFLAMADA_H
#define CELULAINFLAMADA_H

#include <string>
#include "celula.h"

class CelulaInflamada : public Celula {
    protected:
        float porcentaje_inflamacion;
    public:
        //PRE: -
        //POST: genera una celula inflamada
        CelulaInflamada();
        //PRE: -
        //POST: genera una celula inflamada
        CelulaInflamada(std::string tipo, float posicion_x, float posicion_y,
               unsigned int indice_celula, int cantidad_enzimas, int cantidad_proteinas,
               bool material_genetico_es_adn, bool es_pluricelular,
               float porcentaje_inflamacion);
        //PRE: -
        //POST: genera una celula inflamada
        CelulaInflamada(std::string tipo, float posicion_x, float posicion_y, unsigned int indice_celula);
        //PRE: -
        //POST: genera una celula inflamada
        CelulaInflamada(float porcentaje_inflamacion);
        // PRE: -
        // POST: imprime por pantalla un resumen de sus datos
        std::string resumen_datos();
        // PRE: -
        // POST: imprime por pantalla detalles de sus datos
        std::string detalles_datos();
};

#endif // CELULAINFLAMADA_H
