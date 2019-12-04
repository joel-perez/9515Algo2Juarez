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

void Grafo::insertar_nodo(Elemento* elemento, unsigned int indice) {
	if (this->existe_nodo(elemento) == NULL) {
        unsigned int nuevo_indice = indice;
        if (indice == 0)
            nuevo_indice = this->tam;
		Vertice* nuevo_vertice = new Vertice(elemento, nuevo_indice);
		this->vertices->agregar(nuevo_vertice);
		this->tam++;
	}
}

Vertice* Grafo::existe_nodo(Elemento* elemento) {
	Vertice* vertice = NULL;
	bool encontrado = false;
	this->vertices->iniciar_cursor();
	while (this->vertices->avanzar_cursor() && !encontrado) {
        encontrado = elementos_son_iguales(this->vertices->obtener_cursor()->obtener_elemento(), elemento);
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

void Grafo::insertar_arista(Elemento* elemento_origen, Elemento* elemento_destino, unsigned int peso) {
	Vertice* origen = this->existe_nodo(elemento_origen);
	Vertice* destino = this->existe_nodo(elemento_destino);

	if (origen != NULL && destino != NULL) {
		Arista* nueva_arista = new Arista(destino, peso);
		origen->agregar_arista(nueva_arista);
	}
}

void Grafo::insertar_arista(unsigned int indice_vertice_origen, unsigned int indice_vertice_destino, unsigned int peso) {
	Vertice* origen = this->obtener_vertice_por_indice(indice_vertice_origen);
	Vertice* destino = this->obtener_vertice_por_indice(indice_vertice_destino);

	if (origen != NULL && destino != NULL) {
		Arista* nueva_arista = new Arista(destino, peso);
		origen->agregar_arista(nueva_arista);
	}
}

void Grafo::eliminar_nodo(Vertice* eliminar) {
    if (eliminar != NULL) {
        delete eliminar->obtener_adyacentes();
        this->vertices->remover(eliminar);
    }
}

Vertice* Grafo::obtener_vertice_por_indice(unsigned int indice) {
    Vertice* actual;
    this->vertices->iniciar_cursor();
    while (vertices->avanzar_cursor()) {
        actual = this->vertices->obtener_cursor();
        if (actual->obtener_indice() == indice)
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
