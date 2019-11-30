#ifndef ARISTA_H
#define ARISTA_H_
#include "elemento.h"
#include <iostream>

class Vertice;

class Arista {
private:
	Vertice* destino;
	Elemento* celula;
	unsigned int peso;

public:

	// POST: Arista con un destino fijado.
	Arista(Vertice* destino);

	// POST: Devuelve el destino asociado a la arista.
	Vertice* obtener_destino();

	// POST: devuelve el valor peso de la arista.
	unsigned int obtener_peso();

	//POST: Devuelve el cultivo asociado a la arista.
	Elemento* obtener_celula();

	// POST: ---
	~Arista();
};

#endif /* ARISTA_H_ */