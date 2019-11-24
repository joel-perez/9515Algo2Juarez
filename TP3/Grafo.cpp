#include "Grafo.h"

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

void Grafo::insertar_nodo(Elemento* elemento) {
	if (this->existe_nodo(elemento) == NULL) {
		Vertice* nuevoVertice = new Vertice(elemento, this->obtener_tam());
		this->vertices->agregar(nuevoVertice);
		this->tam++;
	}
}

Vertice* Grafo::existe_nodo(Elemento* elemento) {
	Vertice* vertice = NULL;
	bool encontrado = false;
	this->vertices->iniciar_cursor();
	while (this->vertices->avanzar_cursor() && !encontrado) {
        encontrado = elementos_son_iguales(this->vertices->obtener_cursor()->obtenerElemento(), elemento);
		if (encontrado) {
			vertice = vertices->obtener_cursor();
		}
	}
	return vertice;
}

bool Grafo::elementos_son_iguales(Elemento* primer_elemento, Elemento* segundo_elemento) {
    return primer_elemento->obtener_posicion_x() == segundo_elemento->obtener_posicion_x() &&
           primer_elemento->obtener_posicion_y() == segundo_elemento->obtener_posicion_y() &&
           primer_elemento->obtener_tipo() == segundo_elemento->obtener_tipo();
}

void Grafo::insertar_arista(Elemento* elemento_origen, Elemento* elemento_destino) {
	Vertice* origen = this->existe_nodo(elemento_origen);
	Vertice* destino = this->existe_nodo(elemento_destino);

	if (origen != NULL && destino != NULL) {
		Arista* nueva_arista = new Arista(destino);
		origen->agregarArista(nueva_arista);
	}
}

void Grafo::eliminar_nodo(Elemento* elemento) {
	Vertice* eliminar = this->existe_nodo(elemento);
	if (eliminar != NULL)
		delete eliminar;
}

Vertice* Grafo::obtener_vertice_por_indice(unsigned int indice) {
    Vertice* actual;
    this->vertices->iniciar_cursor();
    while (vertices->avanzar_cursor()) {
        actual = this->vertices->obtener_cursor();
        if (actual->obtenerIndice() == indice)
            return actual;
    }
    return NULL;
}

Grafo::~Grafo() {
	this->vertices->iniciar_cursor();
	while (vertices->avanzar_cursor()) {
		delete this->vertices->obtener_cursor();
	}
	delete vertices;
}
