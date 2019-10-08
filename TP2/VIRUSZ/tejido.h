#ifndef TEJIDO_H
#define TEJIDO_H
#include <string>

using namespace std;

class Tejido {

  private:
    int cantidad_celula_X;
    int cantidad_celula_Y;
    int cantidad_celula_Z;
    int cantidad_celula_S;
    int cantidad_anticuerpos;
    int cantidad_dosis_A;
    int cantidad_dosis_B;
//    Elemento *elementos[];

  public:
    Tejido ();
    Tejido (int x, int y, int z, int s, int anticuerpos, int a, int b);

    void asignar_cantidad_X ();
    void asignar_cantidad_Y ();
    void asignar_cantidad_Z ();
    void asignar_cantidad_S ();
    void asignar_cantidad_anticuerpos ();
    void asignar_cant_dosis_A ();
    void asignar_cant_dosis_B ();

    int obtener_cantidad_X ();
    int obtener_cantidad_Y ();
    int obtener_cantidad_Z ();
    int obtener_cantidad_S ();
    int obtener_cantidad_anticuerpos ();
    int obtener_cant_dosis_A ();
    int obtener_cant_dosis_B ();

    int contar_celulas (string str);
    int sumar_dosis (string str);
};
#endif
