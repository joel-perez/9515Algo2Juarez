#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include "Texto.h"

class Grafo {

private:
	Lista<Vertice*>* vertices;
	unsigned int tam;
	Texto texto;

public:
	/*
	 * PRE: ---
	 * POST: grafo generado y vacio.
	 */
	Grafo();
	/*
	 *
	 */
	unsigned int obtener_tam();
	/*
	 *
	 */
	Lista<Vertice*>* obtener_vertices();
	/*
	 * PRE: que el grafo exista  y que el nodo no este previamente.
	 * POST: el grafo queda modificado por el agregado del nuevo nodo.
	 */
	void insertar_nodo(std::string nombre);

	/*
	 * PRE: que el grafo exista , que la arista no este previamente y que existan en el grafo los
	 * nodos origen y destino de la arista.
	 * POST: el grafo queda modificado por el agregado de la nueva arista.
	 */
	void insertar_arista(std::string origen, std::string destino,
			unsigned int peso, unsigned int precio, std::string cultivo);

	/*
	 * PRE: que el grafo exista  y que el nodo a eliminar este en el y no tenga aristas incidentes en el.
	 * POST: el grafo queda modificado por la eliminacion del nodo.
	 */
	void eliminar_nodo(std::string nombre);

	/*
	 * PRE: que el grafo exista  y la arista esten el.
	 * POST: el grafo queda modificado por la eliminacion de la arista.
	 */
	void Eliminar_arista(Vertice* origen, Vertice* destino);

	/*
	 * PRE: que el grafo exista.
	 * POST: ---�
	 */
	bool existe_arista(Vertice* origen, Vertice* destino);

	/*
	 * PRE: que el grafo exista.
	 * POST: devuelve el nodo con el nombre que se paso por referencia. Si no existe devuelve NULL
	 */
	Vertice* existe_nodo(std::string nombre);

	/*
	 * PRE: que el grafo exista.
	 * POST: libera los recursos utilizados por el grafo
	 */
	~Grafo();

};
#endif /* GRAFOS_H_ */
