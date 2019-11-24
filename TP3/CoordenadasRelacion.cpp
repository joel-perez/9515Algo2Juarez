#include "CoordenadasRelacion.h"

CoordenadasRelacion::CoordenadasRelacion(int inicio_x, int inicio_y, int destino_x, int destino_y)
{
    this->inicio_x = inicio_x;
    this->inicio_y = inicio_y;
    this->destino_x = destino_x;
    this->destino_y = destino_y;
}

int CoordenadasRelacion::obtener_inicio_x()
{
    return inicio_x;
}

int CoordenadasRelacion::obtener_inicio_y()
{
    return inicio_y;
}

int CoordenadasRelacion::obtener_destino_x()
{
    return destino_x;
}

int CoordenadasRelacion::obtener_destino_y()
{
    return destino_y;
}
