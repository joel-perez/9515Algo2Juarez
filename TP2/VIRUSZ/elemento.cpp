#include "elemento.h"

Elemento::Elemento()
{
    //ctor
}

Elemento::~Elemento()
{
    //dtor
}

std::string Elemento::resumen_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + posicion_x +
            "\nPosicion Y: " + posicion_y +
            "\n"
}

std::string Elemento::detalles_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + posicion_x +
            "\nPosicion Y: " + posicion_y +
            "\n"
}
