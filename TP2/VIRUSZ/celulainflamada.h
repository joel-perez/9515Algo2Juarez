#ifndef CELULAINFLAMADA_H
#define CELULAINFLAMADA_H

#include "celula.h"


class CelulaInflamada : public Celula {
    protected:
        float porcentaje_inflamacion;
    public:
        CelulaInflamada();
        CelulaInflamada(string tipo, float posicion_x, float posicion_y,
               int cantidad_enzimas, int cantidad_proteinas,
               bool material_genetico_es_adn, bool es_pluricelular,
               float porcentaje_inflamacion)
        :Celula(tipo, posicion_x, posicion_y, cantidad_enzimas,
                cantidad_proteinas, material_genetico_es_adn, es_pluricelular);
        CelulaInflamada(string tipo, float posicion_x, float posicion_y)
        :Celula(tipo, posicion_x, posicion_y);
        CelulaInflamada(float porcentaje_inflamacion);
        std::string resumen_datos();
        std::string detalles_datos();
};

#endif // CELULAINFLAMADA_H
