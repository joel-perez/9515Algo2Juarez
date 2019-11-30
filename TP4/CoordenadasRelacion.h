#ifndef COORDENADASRELACION_H_INCLUDED
#define COORDENADASRELACION_H_INCLUDED

class CoordenadasRelacion
{
private:
    int inicio_x;
    int inicio_y;
    int destino_x;
    int destino_y;
public:
    CoordenadasRelacion(int inicio_x, int inicio_y, int destino_x, int destino_y);
    ~CoordenadasRelacion();
    int obtener_inicio_x();
    int obtener_inicio_y();
    int obtener_destino_x();
    int obtener_destino_y();
};

#endif // COORDENADASRELACION_H_INCLUDED
