#ifndef CoordenadasElemento_H_INCLUDED
#define CoordenadasElemento_H_INCLUDED

#include "imagenes.h"

class CoordenadasElemento
{
private:
    int pos_x;
    int pos_y;
    imagenes tipo;
public:
    //PRE: -
    //POST: genera las coordenadas del elemento
    CoordenadasElemento(int pos_x, int pos_y, imagenes tipo);
    //PRE:-
    //POST: genera las coordenadas del elemento
    ~CoordenadasElemento();
    //PRE: -
    //POST: retorna la posicion del elemnto en el eje x
    int obtener_pos_x();
    //PRE: -
    //POST: retorna la posicion del elemnto en el eje y
    int obtener_pos_y();
    //PRE: -
    //POST: retorna el tipo de celula de la clase imagenes
    imagenes obtener_tipo();
};

#endif // CoordenadasElemento_H_INCLUDED
