#include "Vertice.h"

using namespace std;

Vertice::Vertice(Elemento* elemento, unsigned int indice) {
	if (elemento != NULL && indice >= 0) {
		this->elemento = elemento;
		this->adyacentes = new Lista<Arista*>();
		this->indice = indice;
	}
}

Lista<Arista*>* Vertice::obtenerAdyacentes() {
	return this->adyacentes;
}

Elemento* Vertice::obtenerElemento() {
	return this->elemento;
}

unsigned int Vertice::obtenerIndice() {
	return this->indice;
}

void Vertice::agregarArista(Arista* nuevaArista) {
	if (nuevaArista != NULL)
		this->adyacentes->agregar(nuevaArista);
}

Vertice::~Vertice() {
	this->adyacentes->iniciar_cursor();
	while (this->adyacentes->avanzar_cursor()) {
		delete this->adyacentes->obtener_cursor();
	}
	delete adyacentes;
}
