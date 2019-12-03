#include "CoordenadasElemento.h"

CoordenadasElemento::CoordenadasElemento(int pos_x, int pos_y, imagenes tipo, int indice) {
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->tipo = tipo;
    this->indice = indice;
}

int CoordenadasElemento::obtener_pos_x() {
    return pos_x;
}

int CoordenadasElemento::obtener_pos_y() {
    return pos_y;
}

imagenes CoordenadasElemento::obtener_tipo() {
    return tipo;
}

int CoordenadasElemento::obtener_indice() {
    return indice;
}
