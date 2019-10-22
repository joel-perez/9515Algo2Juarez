#ifndef TEJIDO_H
#define TEJIDO_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "anticuerpo.h"
#include "celula.h"
#include "celulainflamada.h"
#include "celulamutada.h"
#include "constantes.h"
#include "elemento.h"

class Tejido {
    //Atributos
    private:
        int indice;
        Elemento *elementos[MAX_ELEMENTOS];
    //Metodos
    public:
        // Constructor
        // PRE: -
        // POST: crea un tejido vacío
        Tejido();
        // Agregar elemento
        // PRE: vector no esta lleno
        // POST: agrega e al tejido e incrementa el indice
        void agregar_elemento(Elemento *e);
        // Cargar vector
        // PRE: -
        // POST: llena el vector con los elementos extraidos
        //       del archivo
        void cargar_vector();
        // Obtener celula desde string
        // PRE: -
        // POST: Devuelve una celula en base al string recibido
        Celula* obtener_celula_desde_string(std::string tipo_celula, float posicion_x, float posicion_y);
        // Obtener anticuerpo desde string
        // PRE: -
        // POST: Devuelve un anticuerpo en base al string recibido
        Anticuerpo* obtener_anticuerpo_desde_string(std::string tipo, float posicion_x, float posicion_y);
        // Mostrar elemento
        // PRE: 1 <= i <= indice
        // POST: imprime por pantalla todos los detalles del elemento
        //       en la posicion pos (la primera es la 1)
        void mostrar_elemento(int pos);
        // Mostrar todos los elementos
        // PRE: -
        // POST: recorre el vector e imprime los datos basicos
        //       (nombre y posicion) de todos los elementos
        void mostrar_todos();
        // Obtener Cantidad Elementos
        // PRE: -
        // POST: Devuelve la cantidad de elementos que hay cargados en el vector.
        int obtener_cantidad_elementos();
        // Destructor
        // PRE: -
        // POST: elimina el Tejido
        ~Tejido();
};

#endif
