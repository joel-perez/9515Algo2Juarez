#ifndef ANTICUERPO_H
#define ANTICUERPO_H

#include <string>
#include <stdlib.h>
#include <time.h>
#include "elemento.h"
#include "constantes.h"

class Anticuerpo : public Elemento {
private:
    float tendencia_x;
    float tendencia_y;
    bool esta_atrapado;
    bool esta_siendo_disparado;

public:
    // PRE: -
    // POST: genera Anticuerpo
    Anticuerpo();
    // PRE: -
    // POST: genera Anticuerpo
    Anticuerpo(std::string tipo, float posicion_x, float posicion_y);
    // PRE: -
    // POST: establece las posiciones
    void establecer_posiciones (float posicion_x, float posicion_y);
    // PRE: -
    // POST: imprime por pantalla un resumen de sus datos
    std::string resumen_datos();
    // PRE: -
    // POST: imprime por pantalla detalles de los datos
    std::string detalles_datos();
    // PRE: existe y esta en una posicion
    // POST: genera posicion aleatoria
    void posicion_aleatoria();
    bool obtener_esta_atrapado();
    bool obtener_esta_siendo_disparado();
    // PRE: el anticuerpo no esta atrapado
    // POST: cambia su estado a esta_atrapado
    void cambiar_esta_atrapado(bool esta_atrapado);
    // PRE:
    // POST:
    void cambiar_esta_siendo_disparado(bool esta_siendo_disparado);
};

#endif // ANTICUERPO_H
