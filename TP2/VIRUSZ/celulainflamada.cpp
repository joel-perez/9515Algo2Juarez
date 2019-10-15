#include "celulainflamada.h"

using namespace std;

CelulaInflamada::CelulaInflamada()/*:Celula() */{
    porcentajeInflamacion = 0;
}

string Elemento::resumen_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + posicion_x +
            "\nPosicion Y: " + posicion_y +
            "\n"
}

string Elemento::detalles_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + posicion_x +
            "\nPosicion Y: " + posicion_y +
            "\n"
}

CelulaInflamada::~CelulaInflamada() {
    //dtor
}
