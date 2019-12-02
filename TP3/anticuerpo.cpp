#include "anticuerpo.h"

using namespace std;

Anticuerpo::Anticuerpo() {
    tipo = "";
    posicion_x = 0;
    posicion_y = 0;
    tendencia_x = 5;
    tendencia_y = 5;
}

void Anticuerpo::establecer_posiciones(float posicion_x, float posicion_y) {
    this -> posicion_x =  posicion_x;
    this -> posicion_y = posicion_y;
}

Anticuerpo::Anticuerpo(string tipo, float posicion_x, float posicion_y):
Elemento(tipo, posicion_x, posicion_y) {
    tendencia_x = 5;
    tendencia_y = 5;
}

string Anticuerpo::resumen_datos() {
    return "Tipo: " + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\n";
}

string Anticuerpo::detalles_datos() {
    return "Tipo: " + tipo +
            "\nPosicion X: " + float_to_string(posicion_x) +
            "\nPosicion Y: " + float_to_string(posicion_y) +
            "\n";
}

bool Anticuerpo::obtener_esta_atrapado() {
    return esta_atrapado;
}

bool Anticuerpo::obtener_esta_siendo_disparado() {
    return esta_siendo_disparado;
}

void Anticuerpo::cambiar_esta_atrapado(bool esta_atrapado) {
    this->esta_atrapado = esta_atrapado;
}

void Anticuerpo::cambiar_esta_siendo_disparado(bool esta_siendo_disparado) {
    this->esta_siendo_disparado = esta_siendo_disparado;
}

void Anticuerpo::posicion_aleatoria() {
    if (esta_atrapado != true){
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
}
