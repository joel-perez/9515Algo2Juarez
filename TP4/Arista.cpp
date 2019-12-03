#include "Arista.h"

using namespace std;

Arista::Arista(Vertice* destino) {
	if (destino != NULL)
		this->destino = destino;
}

Vertice* Arista::obtener_destino() {
	return this->destino;
}

unsigned int Arista::obtener_peso() {
	return this->peso;
}

Elemento* Arista::obtener_celula() {
	return this->celula;
}

Arista::~Arista() {
}
