#include "Vertice.h"

using namespace std;

Vertice::Vertice(string nombre, unsigned int indice) {
	if (nombre != "" && indice >= 0) {
		this->nombre = nombre;
		this->adyacentes = new Lista<Arista*>();
		this->indice = indice;
	}
}

Lista<Arista*>* Vertice::obtenerAdyacentes() {
	return this->adyacentes;
}

string Vertice::obtenerNombre() {
	return this->nombre;
}

unsigned int Vertice::obtenerIndice() {
	return this->indice;
}

void Vertice::agregarArista(Arista* nuevaArista) {
	if (nuevaArista != NULL)
		this->adyacentes->agregar(nuevaArista);
}

Vertice::~Vertice() {
	this->adyacentes->iniciarCursor();
	while (this->adyacentes->avanzarCursor()) {
		delete this->adyacentes->obtenerCursor();
	}
	delete adyacentes;
}
