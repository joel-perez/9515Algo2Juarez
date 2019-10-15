#include "celulamutada.h"

CelulaMutada::CelulaMutada()//:CelulaInflamada(porcentajeInflamacion)
{
    porcentajeMutacion = 0;
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

CelulaMutada::~CelulaMutada()
{
    //dtor
}
