#include "celulainflamada.h"

using namespace std;

CelulaInflamada::CelulaInflamada(){
    porcentaje_inflamacion = 0;
}

CelulaInflamada :: CelulaInflamada (float porcentaje_inflamacion){
    this -> porcentaje_inflamacion = porcentaje_inflamacion;
}

string CelulaInflamada::resumen_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\n";
}

string CelulaInflamada::detalles_datos(){
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
            "\nAncho: " + int_to_string(TAMANIO_CELULA) +
            "\nAlto: " + int_to_string(TAMANIO_CELULA) +
            "\nCantidad de enzimas: " + int_to_string(cantidad_enzimas) +
            "\nCantidad de proteinas: " + int_to_string(cantidad_proteinas) +
            "\nTipo de material genetico: " + material_genetico +
            "\nPluricelularidad: " + pluricelularidad +
            "\nPorcentaje de inflamacion: " + float_to_string(porcentaje_inflamacion) + "%\n";
}

CelulaInflamada::~CelulaInflamada() {
    //dtor
}
