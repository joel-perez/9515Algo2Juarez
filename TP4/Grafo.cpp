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

unsigned int Grafo::obtener_camino_minimo(Vertice* origen, Vertice* destino) {
    unsigned int resultado = -1;
    unsigned int* costos = this->inicializar_vector(origen);
    ColaPrioridad<Vertice*>* cola = this->inicializar_cola(origen, costos);

    while (!cola->esta_vacia()) {
        Vertice* actual = cola->desacolar();
        cout << "vertice actual: " << actual->obtener_indice() << endl;
        actual->obtener_adyacentes()->iniciar_cursor();
        while (actual->obtener_adyacentes()->avanzar_cursor()) {
            Arista* analizada = actual->obtener_adyacentes()->obtener_cursor();
            cout << "arista analizada destino: " << analizada->obtener_destino()->obtener_indice() << endl;
            unsigned int temporal = costos[actual->obtener_indice()] + analizada->obtener_peso();
            Vertice* actualiza = analizada->obtener_destino();
            cout << "vertice actualiza: " << actualiza->obtener_indice() << endl;
            if (costos[analizada->obtener_destino()->obtener_indice()] > temporal) {
                costos[analizada->obtener_destino()->obtener_indice()] = temporal;
                cola->actualizar_valor(actualiza, temporal);
                cout << "actualiza " << actualiza->obtener_indice() << " temporal " << temporal << " - ";
            }
        }
    }
    cout << endl;
    resultado = costos[destino->obtener_indice()];

    delete[] costos;
    delete cola;
    return resultado;
}

unsigned int* Grafo::inicializar_vector(Vertice* origen) {
    unsigned int* costos = new unsigned int[this->obtener_tam()];
    for (unsigned int i = 0; i < this->obtener_tam(); i++) {
        costos[i] = INFINITO;
    }
    origen->obtener_adyacentes()->iniciar_cursor();
    while (origen->obtener_adyacentes()->avanzar_cursor()) {
        Arista* analizada = origen->obtener_adyacentes()->obtener_cursor();
        unsigned int costo = analizada->obtener_peso();
        costos[analizada->obtener_destino()->obtener_indice()] = costo;
    }
    costos[origen->obtener_indice()] = 0;
    return costos;
}

ColaPrioridad<Vertice*>* Grafo::inicializar_cola(Vertice* origen, unsigned int* costos) {
    ColaPrioridad<Vertice*>* cola = new ColaPrioridad<Vertice*>();
    this->vertices->iniciar_cursor();
    while (this->vertices->avanzar_cursor()) {
        Vertice* actual = this->vertices->obtener_cursor();
        //if (actual->obtener_nombre() != origen->obtener_nombre()) {
        if (actual->obtener_indice() != origen->obtener_indice()) {
            cola->acolar(actual, costos[actual->obtener_indice()]);
        }
    }
    return cola;
}
