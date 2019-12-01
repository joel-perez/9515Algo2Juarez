#ifndef ARISTA_H
#define ARISTA_H_

#include <iostream>

class Vertice;

class Arista {
private:
	Vertice* destino;

public:
	// POST: Arista con un destino fijado.
	Arista(Vertice* destino);

	// POST: Devuelve el destino asociado a la arista.
	Vertice* obtener_destino();

	// POST: Libera memoria.
	~Arista();
};

#endif /* ARISTA_H_ */
