#include "Vertice.h"

using namespace std;

Vertice::Vertice(string nombre, unsigned int indice) {
	if (nombre != "" && indice >= 0) {
		this->nombre = nombre;
		this->adyacentes = new Lista<Arista*>();
		this->indice = indice;
		this->envios = NULL;
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
	if (nuevaArista != NULL) {
		this->adyacentes->agregar(nuevaArista);
	}
}
Vertice::~Vertice() {
	if (this->envios != NULL) {
		this->envios->iniciarCursor();
		while (this->envios->avanzarCursor()) {
			delete this->envios->obtenerCursor();
		}
		delete envios;
	}
	this->adyacentes->iniciarCursor();
	while (this->adyacentes->avanzarCursor()) {
		delete this->adyacentes->obtenerCursor();
	}
	delete adyacentes;
}
