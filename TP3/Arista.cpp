#include "Arista.h"

using namespace std;

Arista::Arista(Vertice* destino, unsigned int peso, string nombreCultivo) {
	if (peso >= 0 && destino != NULL && nombreCultivo != "") {
		this->peso = peso;
		this->destino = destino;
		this->nombreCultivo = nombreCultivo;
	}
}
Arista::Arista(unsigned int peso) {
	if (peso >= 0) {
		this->peso = peso;
		this->destino = NULL;
		this->nombreCultivo = "";
	}
}
Vertice* Arista::obtenerDestino() {
	return this->destino;
}
unsigned int Arista::obtenerPeso() {
	return this->peso;
}
string Arista::obtenerCultivo() {
	return this->nombreCultivo;
}
Arista::~Arista() {

}
