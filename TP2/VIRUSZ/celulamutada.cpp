#include "celulamutada.h"

using namespace std;

CelulaMutada::CelulaMutada(){
    porcentaje_mutacion = 0;
}

CelulaMutada :: CelulaMutada (float porcentaje_mutacion){
    this -> porcentaje_mutacion = porcentaje_mutacion;
}

string CelulaMutada::resumen_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\n";
}

string CelulaMutada::detalles_datos(){
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
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\nAncho: " + int_to_string(tamanio_x) +
            "\nAlto: " + int_to_string(tamanio_y) +
            "\nCantidad de enzimas: " + int_to_string(cantidad_enzimas) +
            "\nCantidad de proteinas: " + int_to_string(cantidad_proteinas) +
            "\nTipo de material genetico: " + material_genetico +
            "\nPluricelularidad: " + pluricelularidad +
            "\nPorcentaje de inflamacion: " + float_to_string(porcentaje_inflamacion) + "%" +
            "\nPorcentaje de mutacion: " + float_to_string(porcentaje_mutacion) + "%\n";
}

CelulaMutada::~CelulaMutada(){
    //dtor
}
