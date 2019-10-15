#include "celula.h"

using namespace std;

Celula::Celula() {
    tamanio_x = 0;
    tamanio_y = 0;
    cantidad_enzimas = 0;
    cantidad_proteinas = 0;
    material_genetico_es_adn = false;
    es_pluricelular = false;
}

string Elemento::resumen_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + posicion_x +
            "\nPosicion Y: " + posicion_y +
            "\n"
}

string Elemento::detalles_datos(){
    //string
    //string
    return "Tipo: " + tipo +
            "\nPosicion X: " + posicion_x +
            "\nPosicion Y: " + posicion_y +
            "\nAncho: " + tamanio_x +
            "\nAlto: " + tamanio_y +
            "\nCantidad de enzimas: " + cantidad_enzimas +
            "\nCantidad de proteinas: " + cantidad_proteinas +
            ""
}

Celula::~Celula() {
    //dtor
}
