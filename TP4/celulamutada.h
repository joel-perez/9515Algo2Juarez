#ifndef CELULAMUTADA_H
#define CELULAMUTADA_H

#include <string>
#include "celulainflamada.h"

class CelulaMutada : public CelulaInflamada {
    private:
        float porcentaje_mutacion;
    public:
        CelulaMutada();
        CelulaMutada(float porcentaje_mutacion);
        CelulaMutada(std::string tipo, float posicion_x, float posicion_y,
               int cantidad_enzimas, int cantidad_proteinas,
               bool material_genetico_es_adn, bool es_pluricelular,
               float porcentaje_inflamacion, float porcentaje_mutacion);
        CelulaMutada(std::string tipo, float posicion_x, float posicion_y);
        std::string resumen_datos();
        std::string detalles_datos();
};

#endif // CELULAMUTADA_H
