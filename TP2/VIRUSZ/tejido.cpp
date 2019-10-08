#include "tejido.h"
#include <fstream>
#include <string>

using namespace std;

Tejido :: Tejido () {
  cantidad_celula_X = 0;
  cantidad_celula_Y = 0;
  cantidad_celula_Z = 0;
  cantidad_celula_S = 0;
  cantidad_anticuerpos = 0;
  cantidad_dosis_A = 0;
  cantidad_dosis_B = 0;
}

Tejido :: Tejido (int x, int y, int z, int s, int anticuerpos, int a, int b){
  x = cantidad_celula_X;
  y = cantidad_celula_Y;
  z = cantidad_celula_Z;
  s = cantidad_celula_S;
  anticuerpos = cantidad_anticuerpos;
  a = cantidad_dosis_A;
  b = cantidad_dosis_B;
}

int Tejido :: contar_celulas (string str) {
    int contador = 0;
    string dato;
	  ifstream archivo("estado.txt");
	  while (archivo >> dato) {
	     if (dato == str)
          contador++;
    }
    archivo.close();
    return contador;
}

int Tejido :: sumar_dosis (string str) {
    int sumador = 0;
    bool flag;
    string dato;

	  ifstream archivo("estado.txt");

	  while (archivo >> dato) {
	     if (flag == true)
        sumador += stoi(dato);
	     flag = false;
	     if (dato == str)
        flag = true;
	  }
    archivo.close();
    return sumador;
}


void Tejido :: asignar_cantidad_X (){
  cantidad_celula_X = contar_celulas("X");
}
void Tejido :: asignar_cantidad_Y (){
  cantidad_celula_Y = contar_celulas("Y");
}
void Tejido :: asignar_cantidad_Z (){
  cantidad_celula_Z = contar_celulas("Z");
}
void Tejido :: asignar_cantidad_S (){
  cantidad_celula_S = contar_celulas("S");
}
void Tejido :: asignar_cantidad_anticuerpos (){
  cantidad_anticuerpos = contar_celulas("anticuerpo");
}
void Tejido :: asignar_cant_dosis_A (){
  cantidad_dosis_A = contar_celulas("A");
}
void Tejido :: asignar_cant_dosis_B (){
  cantidad_dosis_B = contar_celulas("B");
}

int Tejido :: obtener_cantidad_X (){
  return cantidad_celula_X;
}
int Tejido :: obtener_cantidad_Y (){
  return cantidad_celula_Y;
}
int Tejido :: obtener_cantidad_Z (){
  return cantidad_celula_Z;
}
int Tejido :: obtener_cantidad_S (){
  return cantidad_celula_S;
}
int Tejido :: obtener_cantidad_anticuerpos (){
  return cantidad_anticuerpos;
}
int Tejido :: obtener_cant_dosis_A (){
  return cantidad_dosis_A;
}
int Tejido :: obtener_cant_dosis_B (){
  return cantidad_dosis_B;
}
