#include "elemento.h"

using namespace std;

Elemento::Elemento() {
    tipo = "";
    posicion_x = 0;
    posicion_y = 0;
}

Elemento::Elemento(string tipo, float posicion_x, float posicion_y) {
    this->tipo = tipo;
    this->posicion_x = posicion_x;
    this->posicion_y = posicion_y;
}

string Elemento::resumen_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\n";
}

string Elemento::detalles_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\n";
}

float Elemento::obtener_posicion_x() {
    return this->posicion_x;
}

float Elemento::obtener_posicion_y() {
    return this->posicion_y;
}

string Elemento::obtener_tipo() {
    return this->tipo;
}

Elemento::~Elemento() {
}
