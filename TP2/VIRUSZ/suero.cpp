#include "suero.h"

using namespace std;

Suero::Suero() {
    cantidad_dosis = 0;
}

Suero::Suero(string tipo, float posicion_x, float posicion_y, TipoDosis tipo_dosis, int cantidad_dosis):
Elemento(tipo, posicion_x, posicion_y) {
    this->tipo_dosis = tipo_dosis;
    this->cantidad_dosis = cantidad_dosis;
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
