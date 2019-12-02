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
        Lista<Anticuerpo*>* lista;
        Lista<Suero*>* cargador_dosis;
        int dosis_a_disponibles;
        int dosis_b_disponibles;

    //Metodos
    public:
        // Constructor
        // PRE: -
        // POST: crea un Tejido vacío
        Tejido();

        // Obtener grafo
        // PRE: -
        // POST: devuelve el grafo de celulas
        Grafo* obtener_grafo();

        Lista<Suero*>* obtener_cargador_dosis();

        void asignar_dosis();

        // Agregar celula
        // PRE: el grafo esta inicializado
        // POST: agrega e al Tejido
        void agregar_celula(Elemento *e, unsigned int acumulador);

        // Agregar anticuerpo
        // PRE: lista esta inicializada
        // POST: agrega e al Tejido
        void agregar_anticuerpo(Anticuerpo* e);

        // Mover Anticuerpos
        // PRE: lista esta inicializada
        // POST: invoca al metodo posicion_aleatoria que tiene cada anticuerpo
        void mover_anticuerpos();

        // Agregar anticuerpo
        // PRE: cargador_dosis esta inicializado
        // POST: agrega s al Tejido
        void agregar_dosis(Suero* s);

        // Cargar archivo
        // PRE: -
        // POST: llena el Tejido con los elementos extraidos del archivo.
        void cargar_archivo();

		// Duplicar
		// PRE:
		// POST:
        void duplicar(Vertice* original);

		// Impacto Constructivo
		// PRE:
		// POST:
        void impacto_constructivo(Vertice* vertice_actual);

		// Impacto Destructivo
		// PRE:
		// POST:
        void impacto_destructivo(Vertice* vertice_actual);

        // Empeorar estado
		// PRE:
		// POST:
        void empeorar_estado(Vertice* vertice_actual);

		// Generar Anticuerpo
		// PRE:
		// POST:
        void generar_anticuerpo();

		// Obtener Lista Anticuerpos
		// PRE:
		// POST:
        Lista<Anticuerpo*>* obtener_lista_anticuerpos();

		// Obtener cantidad total celulas
		// PRE:
		// POST:
        unsigned int obtener_cantidad_total_celulas();

		// Obtener cantidad celulas
		// PRE:
		// POST:
        unsigned int obtener_cantidad_celulas(std::string tipo_celula);

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

        // Obtener Coordenadas Anticuerpos
        // PRE:  La lista de anticuerpos debe estar cargada.
        // POST: Devuelve una lista de CoordenadasElemento indicando donde esta ubicado y que tipo de anticuerpo es.
        Lista<CoordenadasElemento*>* obtener_coordenadas_anticuerpos();

        // Destructor
        // PRE: -
        // POST: elimina el Tejido y libera la memoria.
        ~Tejido();
};

#endif
