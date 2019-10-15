#include "suero.h"

using namespace std;

Suero::Suero() {
    cantidad_dosis = 0;
}

string Suero::resumen_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\n";
}

string Suero::detalles_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\nCantidad de dosis: " + int_to_string(cantidad_dosis);
}

Suero::~Suero() {
    //dtor
}
