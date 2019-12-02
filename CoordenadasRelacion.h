#ifndef COORDENADASRELACION_H_INCLUDED
#define COORDENADASRELACION_H_INCLUDED

class CoordenadasRelacion {
private:
    int inicio_x;
    int inicio_y;
    int destino_x;
    int destino_y;
public:
    //PRE: -
    //POST: genera las coordenadas de relacion
    CoordenadasRelacion(int inicio_x, int inicio_y, int destino_x, int destino_y);
    //PRE:-
    //POST: genera las coordenadas de relacion
    ~CoordenadasRelacion();
    //PRE:-
    //POST: retorna la coordenada inicial en x
    int obtener_inicio_x();
    //PRE: -
    //POST: retorna la coordenada inicial en y
    int obtener_inicio_y();
    //PRE:-
    //POST: retorna la coordenada de destino en x
    int obtener_destino_x();
    //PRE: -
    //POST: retorna la coordenada de destino en y
    int obtener_destino_y();
};

#endif // COORDENADASRELACION_H_INCLUDED
