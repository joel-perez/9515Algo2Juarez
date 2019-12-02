#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <string>
#include "lista.h"
#include "Vertice.h"
#include "constantes.h"
#include "celulamutada.h"

class Grafo {

private:
	Lista<Vertice*>* vertices;
	unsigned int tam;

public:
	// PRE:  ---
	// POST: grafo generado y vacio.
	Grafo();

	// POST: Devuelve el tamaño del grafo (cuantos vertices tiene)
	unsigned int obtener_tam();

	// POST: Devuelve la lista de vertices del grafo.
	Lista<Vertice*>* obtener_vertices();

	// PRE:  Que el grafo exista y que el nodo no este previamente.
	// POST: El grafo queda modificado por el agregado del nuevo nodo.
	void insertar_nodo(Elemento* elemento);

	// PRE:  Que el grafo exista, que la arista no este previamente y que existan en el grafo los
	//       nodos origen y destino de la arista.
	// POST: El grafo queda modificado por el agregado de la nueva arista.
	void insertar_arista(Elemento* elemento_origen, Elemento* elemento_destino);

	// PRE:  Que el grafo exista y que el nodo a eliminar este en el y no tenga aristas incidentes en el.
	// POST: El grafo queda modificado por la eliminacion del nodo.
    void eliminar_nodo(Vertice* eliminar);

	// PRE:  Que el grafo exista y la arista esten el.
	// POST: El grafo queda modificado por la eliminacion de la arista.
	void Eliminar_arista(Vertice* origen, Vertice* destino);

	// PRE:  Que el grafo exista.
	// POST: Indica si hay una arista entre los vertices origen y destino.
	bool existe_arista(Vertice* origen, Vertice* destino);

	// PRE:  Que el grafo exista.
	// POST: Devuelve el nodo con el nombre que se paso por referencia. Si no existe devuelve NULL.
	Vertice* existe_nodo(Elemento* elemento);

	// PRE:  Los elementos deben existir.
	// POST: Indica si los elementos a comparar son iguales por tipo y por ubicacion.
	bool elementos_son_iguales(Elemento* primer_elemento, Elemento* segundo_elemento);

	// POST: Devuelve, en caso de existir, el vertice cuyo indice es el pasado como parametro.
	Vertice* obtener_vertice_por_indice(unsigned int indice);

	// PRE:  Que el grafo exista.
	// POST: Libera los recursos utilizados por el grafo.
	~Grafo();

};
#endif /* GRAFOS_H_ */
