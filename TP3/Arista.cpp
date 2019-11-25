#include "Arista.h"

using namespace std;

Arista::Arista(Vertice* destino) {
	if (destino != NULL)
		this->destino = destino;
}

Vertice* Arista::obtener_destino() {
	return this->destino;
}

Arista::~Arista() {
}
