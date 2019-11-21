#include "Arista.h"

using namespace std;

Arista::Arista(Vertice* destino) {
	if (destino != NULL)
		this->destino = destino;
}

Vertice* Arista::obtenerDestino() {
	return this->destino;
}

Arista::~Arista() {
}
