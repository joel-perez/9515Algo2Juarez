#ifndef ARISTA_H
#define ARISTA_H_
#include <iostream>

class Vertice;

class Arista {
private:
	unsigned int peso;
	Vertice* destino;
	std::string nombreCultivo;

public:
	/*
	 * post: Arista con un peso determinado, sin un destino fijo
	 */
	Arista(unsigned int peso);
	/*
	 *post: Arista con peso determinado y con un destino fijado.
	 */
	Arista(Vertice* destino, unsigned int peso, std::string nombreCultivo);
	/*
	 *post: devuelve el valor peso de la arista.
	 */
	unsigned int obtenerPeso();
	/*
	 * POST: Devuelve el destino asociado a la arista.
	 */
	Vertice* obtenerDestino();

	/*
	 * POST: Devuelve el cultivo asociado a la arista.
	 */
	std::string obtenerCultivo();
	/*
	 *post: -
	 */
	~Arista();
};

#endif /* ARISTA_H_ */
