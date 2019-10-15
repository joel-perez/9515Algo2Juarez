#include "celula.h"

Celula::Celula() {
    tamanio_x = 0;
    tamanio_y = 0;
    cantidad_enzimas = 0;
    cantidad_proteinas = 0;
    material_genetico_es_adn = false;
    es_pluricelular = false;
}

Celula::~Celula() {
    //dtor
}
