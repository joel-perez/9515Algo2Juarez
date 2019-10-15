#include "celula.h"

<<<<<<< HEAD
using namespace std;

Celula::Celula()
{
=======
Celula::Celula() {
>>>>>>> d7b957c2f43eb8aa054b0134ce4ca4162215b1e3
    tamanio_x = 0;
    tamanio_y = 0;
    cantidad_enzimas = 0;
    cantidad_proteinas = 0;
    material_genetico_es_adn = false;
    es_pluricelular = false;
}

<<<<<<< HEAD
string Elemento::resumen_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + posicion_x +
            "\nPosicion Y: " + posicion_y +
            "\n"
}

string Elemento::detalles_datos(){
    string
    string
    return "Tipo: " + tipo +
            "\nPosicion X: " + posicion_x +
            "\nPosicion Y: " + posicion_y +
            "\nAncho: " + tamanio_x +
            "\nAlto: " + tamanio_y +
            "\nCantidad de enzimas: " + cantidad_enzimas +
            "\nCantidad de proteinas: " + cantidad_proteinas +
            ""
}

Celula::~Celula()
{
=======
Celula::~Celula() {
>>>>>>> d7b957c2f43eb8aa054b0134ce4ca4162215b1e3
    //dtor
}
