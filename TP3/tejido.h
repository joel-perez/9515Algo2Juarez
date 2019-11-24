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
#include "CoordenadasElemento.h"
#include "elemento.h"
#include "Grafo.h"
#include "imagenes.h"
#include "lista.h"
#include "suero.h"

class Tejido {
    //Atributos
    private:
        Grafo* grafo;
        Anticuerpo* anticuerpo;
        Lista<Elemento*>* lista;
        Lista<Elemento*>* cargador_dosis;

    //Metodos
    public:
        // Constructor
        // PRE: -
        // POST: crea un Tejido vacío
        Tejido();
        // Agregar celula
        // PRE: el grafo esta inicializado
        // POST: agrega e al Tejido
        void agregar_celula(Elemento *e, unsigned int acumulador);
        // Agregar anticuerpo
        // PRE: lista esta inicializada
        // POST: agrega e al Tejido
        void agregar_anticuerpo(Elemento* e);
        Lista <Anticuerpo*>* mover_anticuerpos (Elemento* e);
        // Agregar anticuerpo
        // PRE: cargador_dosis esta inicializado
        // POST: agrega e al Tejido
        void agregar_dosis(Elemento* e);
        // Cargar archivo
        // PRE: -
        // POST: llena el Tejido con los elementos extraidos
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
        // Obtener Coordenadas Celulas
        // PRE:  El grafo debe estar cargado.
        // POST: Devuelve una lista de CoordenadasElemento indicando donde esta ubicada y que tipo de celula es.
        Lista<CoordenadasElemento*>* obtener_coordenadas_celulas();
        // Destructor
        // PRE: -
        // POST: elimina el Tejido
        ~Tejido();
};

#endif
