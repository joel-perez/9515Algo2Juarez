#ifndef VERTICE_H_
#define VERTICE_H_

#include <iostream>
#include <string>
#include "elemento.h"
#include "Arista.h"
#include "lista.h"

class Vertice {
private:
	Elemento* elemento;
	Lista<Arista*>* adyacentes;
	unsigned int indice;

public:

	// PRE:  --
	// POST: --
	Vertice();

	// PRE:  Indice debe ser mayor que cero y el nombre no debe estar vacio
	// POST: Vertice listo para utilizar con un nombre y un indice dado.
    //       Si no cumple las precondiciones no hace nada.
	Vertice(Elemento* elemento, unsigned int indice);
	
	// POST: Devuelve el elemento del vertice.
	Elemento* obtener_elemento();

	// POST: Devuelve la lista de adyacentes.
	Lista<Arista*>* obtener_adyacentes();

	// POST: Devuelve el indice.
	unsigned int obtener_indice();

	// PRE:  La arista no debe ser nula.
	// POST: Agrega una arista a la lista de adyacentes
	void agregar_arista(Arista* nueva_arista);

    // PRE:  El elemento no debe ser nulo.
    // POST: Cambia el elemento del vertice por nuevo_elemento.
	void cambiar_elemento(Elemento* nuevo_elemento);

	// POST: Libera los recursos utilizados en vertice.
	~Vertice();
};

#endif /* VERTICE_H_ */
