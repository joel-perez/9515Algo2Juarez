#ifndef CoordenadasElemento_H_INCLUDED
#define CoordenadasElemento_H_INCLUDED

#include "imagenes.h"

class CoordenadasElemento {
private:
    int pos_x;
    int pos_y;
    imagenes tipo;
public:
    CoordenadasElemento(int pos_x, int pos_y, imagenes tipo);
    ~CoordenadasElemento();
    int obtener_pos_x();
    int obtener_pos_y();
    imagenes obtener_tipo();
};

#endif // CoordenadasElemento_H_INCLUDED
