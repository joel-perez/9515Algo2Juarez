#ifndef VERTICE_H_
#define VERTICE_H_

#include <iostream>
#include <string>
#include "Arista.h"
#include "Lista.h"

class Vertice {
private:
	std::string nombre;
	Lista<Arista*>* adyacentes;
	unsigned int indice;

public:
	/*
	 * pre: Indice debe ser mayor que cero y el nombre no debe estar vacio
	 * post: Vertice listo para utilizar con un nombre y un indice dado. Si no cumple las precondiciones
	 * no hace nada.
	 */
	Vertice(std::string nombre, unsigned int indice);
	/*
	 * post: devuelve el nombre del vertice
	 */
	std::string obtenerNombre();
	/*
	 * post: devuelve la lista de adyacentes
	 */
	Lista<Arista*>* obtenerAdyacentes();
	/*
	 *post: devuelve el indice
	 */
	unsigned int obtenerIndice();
	/*
	 *pre: La arista no debe ser nula.
	 *post: Agrega una arista a la lista de adyacentes
	 */
	void agregarArista(Arista* nuevaArista);
	/*
	 * post: libera los recursos utilizados en vertice.
	 */
	~Vertice();
};

#endif /* VERTICE_H_ */
