#include "CoordenadasElemento.h"

CoordenadasElemento::CoordenadasElemento(int pos_x, int pos_y, imagenes tipo) {
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->tipo = tipo;
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
