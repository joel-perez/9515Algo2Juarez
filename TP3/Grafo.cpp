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
	this->vertices->iniciar_cursor();
	while (this->vertices->avanzar_cursor() && !encontrado) {
		//encontrado = (texto.mayusculas(this->vertices->obtenerCursor()->obtenerNombre()) == texto.mayusculas(nombre));
		encontrado = (this->vertices->obtener_cursor()->obtenerNombre() == nombre);
		if (encontrado) {
			vertice = vertices->obtener_cursor();
		}
	}
	return vertice;
}

void Grafo::insertar_arista(string nombre_origen, string nombre_destino) {
	Vertice* origen = this->existe_nodo(nombre_origen);
	Vertice* destino = this->existe_nodo(nombre_destino);

	if (origen != NULL && destino != NULL) {
		Arista* nueva_arista = new Arista(destino);
		origen->agregarArista(nueva_arista);
	}
}

void Grafo::eliminar_nodo(string nombre) {
	Vertice* eliminar = this->existe_nodo(nombre);
	if (eliminar != NULL)
		delete eliminar;
}

Grafo::~Grafo() {
	this->vertices->iniciar_cursor();
	while (vertices->avanzar_cursor()) {
		delete this->vertices->obtener_cursor();
	}
	delete vertices;
}
