#include "celulamutada.h"

using namespace std;

CelulaMutada::CelulaMutada(){
    porcentaje_mutacion = 0;
}

CelulaMutada::CelulaMutada(string tipo, float posicion_x, float posicion_y,
               int cantidad_enzimas, int cantidad_proteinas,
               bool material_genetico_es_adn, bool es_pluricelular,
               float porcentaje_inflamacion, float porcentaje_mutacion)
:CelulaInflamada::CelulaInflamada(tipo, posicion_x, posicion_y, cantidad_enzimas,
        cantidad_proteinas, material_genetico_es_adn, es_pluricelular, porcentaje_inflamacion) {
    this->porcentaje_mutacion = porcentaje_mutacion;
}

CelulaMutada::CelulaMutada(string tipo, float posicion_x, float posicion_y)
:CelulaInflamada::CelulaInflamada(tipo, posicion_x, posicion_y) {
    this->cantidad_enzimas = 0;
    this->cantidad_proteinas = 0;
    this->material_genetico_es_adn = false;
    this->es_pluricelular = false;
    this->porcentaje_inflamacion = 0;
    this->porcentaje_mutacion = 0;
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
            "\nAncho: " + int_to_string(TAMANIO_CELULA) +
            "\nAlto: " + int_to_string(TAMANIO_CELULA) +
            "\nCantidad de enzimas: " + int_to_string(cantidad_enzimas) +
            "\nCantidad de proteinas: " + int_to_string(cantidad_proteinas) +
            "\nTipo de material genetico: " + material_genetico +
            "\nPluricelularidad: " + pluricelularidad +
            "\nPorcentaje de inflamacion: " + float_to_string(porcentaje_inflamacion) + "%" +
            "\nPorcentaje de mutacion: " + float_to_string(porcentaje_mutacion) + "%\n";
}
