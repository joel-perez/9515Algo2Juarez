#ifndef ARISTA_H
#define ARISTA_H_

#include <iostream>

class Vertice;

class Arista {
private:
	Vertice* destino;

public:
    //PRE: -
	// POST: Arista con un destino fijado.
	Arista(Vertice* destino);
    //PRE: -
	// POST: Devuelve el destino asociado a la arista.
	Vertice* obtener_destino();
    //PRE: -
	// POST: Libera memoria.
	~Arista();
};

#endif /* ARISTA_H_ */
