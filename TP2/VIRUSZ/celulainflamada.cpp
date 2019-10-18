#include "celulainflamada.h"

using namespace std;

CelulaInflamada::CelulaInflamada(){
    porcentaje_inflamacion = 0;
}

CelulaInflamada::CelulaInflamada(string tipo, float posicion_x, float posicion_y,
               int cantidad_enzimas, int cantidad_proteinas,
               bool material_genetico_es_adn, bool es_pluricelular,
               float porcentaje_inflamacion)
:Celula::Celula(tipo, posicion_x, posicion_y, cantidad_enzimas,
        cantidad_proteinas, material_genetico_es_adn, es_pluricelular) {
    this->porcentaje_inflamacion = porcentaje_inflamacion;
}

CelulaInflamada::CelulaInflamada(string tipo, float posicion_x, float posicion_y)
:Celula::Celula(tipo, posicion_x, posicion_y) {
    this->cantidad_enzimas = 0;
    this->cantidad_proteinas = 0;
    this->material_genetico_es_adn = false;
    this->es_pluricelular = false;
    this->porcentaje_inflamacion = 0;
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
