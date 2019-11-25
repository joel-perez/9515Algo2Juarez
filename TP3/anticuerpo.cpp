#include "anticuerpo.h"

using namespace std;

Anticuerpo::Anticuerpo() {
    tipo = "";
    posicion_x = 0;
    posicion_y = 0;
    tendencia_x = 5;
    tendencia_y = 5;
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

void Anticuerpo::posicion_aleatoria() {
    if (posicion_x <= 0)
        tendencia_x = 2;
    if (posicion_x >= SCREEN_WIDTH)
        tendencia_x = 5;
    if (posicion_y <= 0)
        tendencia_y = 2;
    if (posicion_y >= SCREEN_HEIGHT)
        tendencia_y = 5;
    posicion_x += (rand() % 10) - tendencia_x;
    posicion_y += (rand() % 10) - tendencia_y;
}
