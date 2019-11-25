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
		Vertice* nuevo_vertice = new Vertice(elemento, this->obtener_tam());
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

void Grafo::insertar_arista(Elemento* elemento_origen, Elemento* elemento_destino) {
	Vertice* origen = this->existe_nodo(elemento_origen);
	Vertice* destino = this->existe_nodo(elemento_destino);

	if (origen != NULL && destino != NULL) {
		Arista* nueva_arista = new Arista(destino);
		origen->agregar_arista(nueva_arista);
	}
}

void Grafo::eliminar_nodo(Elemento* elemento) {
	Vertice* eliminar = this->existe_nodo(elemento);
	if (eliminar != NULL)
		delete eliminar;
}

void Grafo::duplicar(Vertice* original) {
    Vertice* copia = original;
    // TODO: añadir offset

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

void Grafo::impacto_constructivo(unsigned int indice) {
    Vertice* v = obtener_vertice_por_indice(indice);
    if (v != NULL) {
        if (v->obtener_elemento()->obtener_tipo() == TIPO_CELULA_Y) {
            v->obtener_elemento()->cambiar_tipo(TIPO_CELULA_X);
        }
        else if (v->obtener_elemento()->obtener_tipo() == TIPO_CELULA_Z) {
            Elemento* nuevo = new CelulaInflamada(TIPO_CELULA_Y,
                                                  v->obtener_elemento()->obtener_posicion_x(),
                                                  v->obtener_elemento()->obtener_posicion_y());
            v->cambiar_elemento(nuevo);
        }
        else
            delete v;
    }
}

void Grafo::impacto_destructivo(unsigned int indice){
    Vertice* v = obtener_vertice_por_indice(indice);
    if (v != NULL) {
        if (v->obtener_elemento()->obtener_tipo() == TIPO_CELULA_X) {
            v->obtener_elemento()->cambiar_tipo(TIPO_CELULA_Y);
        }
        else if (v->obtener_elemento()->obtener_tipo() == TIPO_CELULA_Y) {
            Elemento* nuevo = new CelulaMutada(TIPO_CELULA_Z,
                                               v->obtener_elemento()->obtener_posicion_x(),
                                               v->obtener_elemento()->obtener_posicion_y());
            v->cambiar_elemento(nuevo);
        }
        else
            duplicar(v);
    }
}

void Grafo::empeorar_estado(unsigned int indice) {
    Vertice* v = obtener_vertice_por_indice(indice);
    if (v != NULL) {
        if (v->obtener_elemento()->obtener_tipo() == TIPO_CELULA_S) {
            Elemento* nuevo = new CelulaInflamada(TIPO_CELULA_X,
                                                  v->obtener_elemento()->obtener_posicion_x(),
                                                  v->obtener_elemento()->obtener_posicion_y());
            v->cambiar_elemento(nuevo);
        }
        else if (v->obtener_elemento()->obtener_tipo() == TIPO_CELULA_X) {
            v->obtener_elemento()->cambiar_tipo(TIPO_CELULA_Y);
        }
        else if (v->obtener_elemento()->obtener_tipo() == TIPO_CELULA_Y) {
            Elemento* nuevo = new CelulaMutada(TIPO_CELULA_Z,
                                               v->obtener_elemento()->obtener_posicion_x(),
                                               v->obtener_elemento()->obtener_posicion_y());
            v->cambiar_elemento(nuevo);
        }
    }
}

Grafo::~Grafo() {
	this->vertices->iniciar_cursor();
	while (vertices->avanzar_cursor()) {
		delete this->vertices->obtener_cursor();
	}
	delete vertices;
}
