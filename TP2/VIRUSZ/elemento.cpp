#include "elemento.h"
using namespace std;

Elemento::Elemento() {
    tipo = "";
    posicion_x = 0;
    posicion_y = 0;
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

Elemento::~Elemento() {
    //dtor
}
