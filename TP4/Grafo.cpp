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

unsigned int* Grafo::inicializar_vector(Vertice* origen,Elemento* celula) {
	unsigned int* costos = new unsigned int[this->obtener_tam()];
	for (unsigned int i = 0; i < this->obtener_tam(); i++) {
		costos[i] = VALOR_GRANDE;
	}
	origen->obtener_adyacentes()->iniciar_cursor();
	while (origen->obtener_adyacentes()->avanzar_cursor()) {
		Arista* analizada = origen->obtener_adyacentes()->obtener_cursor();
		if (analizada->obtener_celula() == texto.mayusculas(celula)) {
			unsigned int costo = analizada->obtener_peso();
			costos[analizada->obtener_destino()->obtener_indice()] = costo;
		}
	}
	costos[origen->obtener_indice()] = 0;
	return costos;
}
ColaPrioridad<Vertice*>* Grafo::inicializar_cola(Vertice* origen, unsigned int* costos) {
	ColaPrioridad<Vertice*>* cola = new ColaPrioridad<Vertice*>();

	this->vertices->iniciar_cursor();
	while (this->vertices->avanzar_cursor()) {
		Vertice* actual = this->vertices->obtener_cursor();
		if (actual->obtener_elemento() != origen->obtener_elemento()) {
			cola->acolar(actual, costos[actual->obtener_indice()]);
		}
	}
	return cola;
}

unsigned int Grafo::buscar_camino_minimo(Vertice* origen, Vertice* destino, Elemento* celula) {
	unsigned int resultado = -1;
	unsigned int* costos = this->inicializar_vector(origen,celula);
	ColaPrioridad<Vertice*>* cola = this->inicializar_cola(origen, costos);

	while (!cola->esta_vacia()) {
		Vertice* actual = cola->desacolar();
		actual->obtener_adyacentes()->iniciar_cursor();
		while (actual->obtener_adyacentes()->avanzar_cursor()) {
			Arista* analizada = actual->obtener_adyacentes()->obtener_cursor();
			if (analizada->obtener_celula() == texto.mayusculas(celula)) {
				unsigned int temporal = costos[actual->obtener_indice()] + analizada->obtener_peso();
				Vertice* actualiza = analizada->obtener_destino();
				if (costos[analizada->obtener_destino()->obtener_indice()] > temporal) {
					costos[analizada->obtener_destino()->obtener_indice()] = temporal;
					cola->actualizar_valor(actualiza, temporal);
				}
			}
		}
	}
	resultado = costos[destino->obtener_indice()];

	delete[] costos;
	delete cola;
	return resultado;
}

/*unsigned int Grafo::costoDeEnvio(Vertice* destino, Elemento* celula) {
	unsigned int costoPrecioDelCultivo = destino->obtenerCostoDelCultivo(
			celula);
	unsigned int kilometros = this->buscarElCaminoMinimo(
			this->existeNodo("ALMACEN"), destino, celula);
	if(kilometros == VALOR_GRANDE){
		cout<<"No se encontro camino hacia el destino seleccionado."<<endl;
		return 0;
	}
	cout << "Costo: " << costoPrecioDelCultivo * kilometros << endl;
	return (costoPrecioDelCultivo * kilometros);
}*/

Grafo::~Grafo() {
	this->vertices->iniciar_cursor();
	while (vertices->avanzar_cursor()) {
		delete this->vertices->obtener_cursor();
	}
	delete vertices;
}
