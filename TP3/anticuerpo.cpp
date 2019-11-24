#include "anticuerpo.h"

using namespace std;

Anticuerpo::Anticuerpo() {
    tipo = "";
    posicion_x = 0;
    posicion_y = 0;
}

Anticuerpo::Anticuerpo(string tipo, float posicion_x, float posicion_y):
Elemento(tipo, posicion_x, posicion_y) {
    // TODO: agregar posibles atributos futuros
}

string Anticuerpo::resumen_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\n";
}

string Anticuerpo::detalles_datos(){
    return "Tipo: " + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\n";
}
float Anticuerpo :: posicion_aleatoria_x (){
    posicion_x = rand () % 10;
    return posicion_x;
}
float Anticuerpo :: posicion_aleatoria_y (){
    posicion_y = rand () % 10;
    return posicion_y;
}
