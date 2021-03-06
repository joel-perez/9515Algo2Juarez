#include "celula.h"

using namespace std;

Celula::Celula() {
    tipo = TIPO_CELULA_DESCONOCIDO;
    posicion_x = 0;
    posicion_y = 0;
    cantidad_enzimas = 0;
    cantidad_proteinas = 0;
    material_genetico_es_adn = false;
    es_pluricelular = false;
}

Celula::Celula(string tipo, float posicion_x, float posicion_y,
               int cantidad_enzimas, int cantidad_proteinas,
               bool material_genetico_es_adn, bool es_pluricelular)
:Elemento::Elemento(tipo, posicion_x, posicion_y) {
    this->cantidad_enzimas = cantidad_enzimas;
    this->cantidad_proteinas = cantidad_proteinas;
    this->material_genetico_es_adn = material_genetico_es_adn;
    this->es_pluricelular = es_pluricelular;
}

Celula::Celula(string tipo, float posicion_x, float posicion_y)
:Elemento::Elemento(tipo, posicion_x, posicion_y) {
    this->cantidad_enzimas = 0;
    this->cantidad_proteinas = 0;
    this->material_genetico_es_adn = false;
    this->es_pluricelular = false;
}

unsigned int Celula::obtener_id_celula() {
    return id_celula;
}

string Celula::resumen_datos(){
    return "Tipo: " + TIPO_ELEMENTO_CELULA + CARACTER_SEPARADOR + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\n";
}

string Celula::detalles_datos(){
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
    return "Tipo: " + TIPO_ELEMENTO_CELULA + CARACTER_SEPARADOR + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\nAncho: " + int_to_string(TAMANIO_CELULA) +
            "\nAlto: " + int_to_string(TAMANIO_CELULA) +
            "\nCantidad de enzimas: " + int_to_string(cantidad_enzimas) +
            "\nCantidad de proteinas: " + int_to_string(cantidad_proteinas) +
            "\nTipo de material genetico: " + material_genetico +
            "\nPluricelularidad: " + pluricelularidad + "\n";
}
