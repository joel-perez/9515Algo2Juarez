#ifndef CELULAINFLAMADA_H
#define CELULAINFLAMADA_H

#include <string>
#include "celula.h"

class CelulaInflamada : public Celula {
    protected:
        float porcentaje_inflamacion;
    public:
        CelulaInflamada();
        CelulaInflamada(std::string tipo, float posicion_x, float posicion_y,
               int cantidad_enzimas, int cantidad_proteinas,
               bool material_genetico_es_adn, bool es_pluricelular,
               float porcentaje_inflamacion);
        CelulaInflamada(std::string tipo, float posicion_x, float posicion_y);
        CelulaInflamada(float porcentaje_inflamacion);
        std::string resumen_datos();
        std::string detalles_datos();
};

#endif // CELULAINFLAMADA_H
