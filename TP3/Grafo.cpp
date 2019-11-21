#include "Grafo.h"
#include "Constantes.h"
using namespace std;

Grafo::Grafo() {
	this->vertices = new Lista<Vertice*>();
	this->tam = 0;
}
Lista<Vertice*>* Grafo::obtener_vertices() {
	return this->vertices;
}
unsigned int Grafo::obtener_tam() {
	return this->tam;
}

void Grafo::insertar_nodo(string nombreVertice) {
	if (this->existe_nodo(nombreVertice) == NULL) {
		Vertice* nuevoVertice = new Vertice(nombreVertice, this->obtener_tam());
		this->vertices->agregar(nuevoVertice);
		this->tam++;
	}
}

Vertice* Grafo::existe_nodo(string nombre) {
	Vertice* vertice = NULL;
	bool encontrado = false;
	this->vertices->iniciarCursor();
	while (this->vertices->avanzarCursor() && !encontrado) {
		encontrado = (texto.mayusculas(
				this->vertices->obtenerCursor()->obtenerNombre())
				== texto.mayusculas(nombre));
		if (encontrado) {
			vertice = vertices->obtenerCursor();
		}
	}
	return vertice;
}

void Grafo::insertar_arista(string nombreOrigen, string nombreDestino,
		unsigned int peso, unsigned int precio, string cultivo) {
	Vertice* origen = this->existe_nodo(nombreOrigen);
	Vertice* destino = this->existe_nodo(nombreDestino);

	if (origen != NULL && destino != NULL) {
		Arista* nuevaArista = new Arista(destino, peso, cultivo);
		origen->agregarArista(nuevaArista);
		destino->ingresarDatosEnvio(precio, cultivo);
	}
}

void Grafo::eliminar_nodo(string nombre) {
	Vertice* eliminar = this->existe_nodo(nombre);
	if (eliminar != NULL) {
		delete eliminar;
	}
}

Grafo::~Grafo() {
	this->vertices->iniciarCursor();
	while (vertices->avanzarCursor()) {
		delete this->vertices->obtenerCursor();
	}
	delete vertices;
}
