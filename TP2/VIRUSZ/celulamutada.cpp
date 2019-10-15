#include "celulamutada.h"

using namespace std;

CelulaMutada::CelulaMutada(){
    porcentaje_mutacion = 0;
}

string Elemento::resumen_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + int_to_string(posicion_x) +
            "\nPosicion Y: " + int_to_string(posicion_y) +
            "\n";
}

string Elemento::detalles_datos(){
    string material_genetico;
    string pluricelularidad;
    if (material_genetico_es_adn)
        material_genetico = "ADN";
    else
        material_genetico = "ARN";
    if (es_pluricelular)
        pluricelularidad = "Pluricelular";
    else
        pluricelularidad = "Unicelular";
    return "Tipo: " + tipo +
            "\nPosicion X: " + int_to_string(posicion_x) +
            "\nPosicion Y: " + int_to_string(posicion_y) +
            "\nAncho: " + int_to_string(tamanio_x) +
            "\nAlto: " + int_to_string(tamanio_y) +
            "\nCantidad de enzimas: " + int_to_string(cantidad_enzimas) +
            "\nCantidad de proteinas: " + int_to_string(cantidad_proteinas) +
            "\nTipo de material genetico: " + material_genetico +
            "\nPluricelularidad: " + pluricelularidad +
            "\nPorcentaje de inflamacion: " + porcentaje_inflamacion + "%" +
            "\nPorcentaje de mutacion: " + porcentaje_mutacion + "%\n";
}

CelulaMutada::~CelulaMutada(){
    //dtor
}
