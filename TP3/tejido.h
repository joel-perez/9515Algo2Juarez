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
#include "conversiones.h"
#include "CoordenadasRelacion.h"
#include "elemento.h"
#include "Grafo.h"
#include "lista.h"
#include "suero.h"

class Tejido {
    //Atributos
    private:
        Grafo* grafo;

    //Metodos
    public:
        // Constructor
        // PRE: -
        // POST: crea un tejido vacío
        Tejido();
        // Agregar elemento
        // PRE: vector no esta lleno
        // POST: agrega e al tejido e incrementa el indice
        void agregar_elemento(Elemento *e, int acumulador);
        // Cargar vector
        // PRE: -
        // POST: llena el vector con los elementos extraidos
        //       del archivo
        void cargar_archivo();
        // Obtener celula desde string
        // PRE: -
        // POST: Devuelve una celula en base al string recibido
        Celula* obtener_celula_desde_string(std::string tipo_celula, float posicion_x, float posicion_y);
        // Obtener anticuerpo desde string
        // PRE: -
        // POST: Devuelve un anticuerpo en base al string recibido
        Anticuerpo* obtener_anticuerpo_desde_string(std::string tipo, float posicion_x, float posicion_y);
        // Obtener Dosis desde String
        // PRE: -
        // POST: Devuelve una dosis en base al tipo_dosis recibido y su cantidad correspondiente.
        Suero* obtener_dosis_desde_string(std::string tipo_dosis, int cantidad_dosis);
        // Obtener Coordenadas Relaciones
        // PRE:  El grafo debe estar cargado.
        // POST: Devuelve una lista de CoordenadasRelacion indicando donde empieza y donde termina una linea.
        Lista<CoordenadasRelacion*>* obtener_coordenadas_relaciones();
        // Destructor
        // PRE: -
        // POST: elimina el Tejido
        ~Tejido();
};

#endif
