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

	/*
	 */
	Vertice();

	/*
	 * pre: Indice debe ser mayor que cero y el nombre no debe estar vacio
	 * post: Vertice listo para utilizar con un nombre y un indice dado. Si no cumple las precondiciones
	 * no hace nada.
	 */
	Vertice(Elemento* elemento, unsigned int indice);
	/*
	 * post: devuelve el elemento del vertice
	 */
	Elemento* obtener_elemento();
	/*
	 * post: devuelve la lista de adyacentes
	 */
	Lista<Arista*>* obtener_adyacentes();
	/*
	 *post: devuelve el indice
	 */
	unsigned int obtener_indice();
	/*
	 *pre: La arista no debe ser nula.
	 *post: Agrega una arista a la lista de adyacentes
	 */
	void agregar_arista(Arista* nueva_arista);
	/*
	 *pre: el elemento no debe ser nulo
     *post: cambia el elemento del vertice por nuevo_elemento
	 */
	void cambiar_elemento(Elemento* nuevo_elemento);
	/*
	 * post: libera los recursos utilizados en vertice.
	 */
	~Vertice();
};

#endif /* VERTICE_H_ */
