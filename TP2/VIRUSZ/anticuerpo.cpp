#include "anticuerpo.h"

using namespace std;

Anticuerpo::Anticuerpo() {
    //ctor
}

string Anticuerpo::resumen_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\n";
}

string Anticuerpo::detalles_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\n";
}

Anticuerpo::~Anticuerpo() {
    //dtor
}
