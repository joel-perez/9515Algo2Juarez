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
            nuevo_indice = this->tam + 1;
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

Lista<Vertice*>* Grafo::obtener_camino_minimo(Vertice* origen, Vertice* destino) {
    Lista<Vertice*>* resultado = new Lista<Vertice*>();
    if (origen != NULL && destino != NULL) {
        int* parent = this->inicializar_vector_rutas();
        unsigned int* costos = this->inicializar_vector(origen);
        ColaPrioridad<Vertice*>* cola = this->inicializar_cola(origen, costos);
        while (!cola->esta_vacia()) {
            Vertice* actual = cola->desacolar();
            if (actual != NULL) {
                Lista<Arista*>* adyacentes = actual->obtener_adyacentes();
                adyacentes->iniciar_cursor();
                while (adyacentes->avanzar_cursor()) {
                    Arista* analizada = adyacentes->obtener_cursor();
                    if (analizada != NULL) {
                        unsigned int temporal = costos[actual->obtener_indice()] + analizada->obtener_peso();
                        Vertice* actualiza = analizada->obtener_destino();
                        if (actualiza != NULL) {
                            unsigned int actualiza_indice = actualiza->obtener_indice();
                            if (costos[actualiza_indice] > temporal) {
                                costos[actualiza_indice] = temporal;
                                cola->actualizar_valor(actualiza, temporal);         // Esto solo devuelve el menor peso total.
                                parent[actualiza_indice] = actual->obtener_indice(); // Esto devuelve la ruta detallada.
                            }
                        }
                    }
                }
            }
        }
        //imprimir_solucion(costos, tam, parent);
        construir_path(parent, destino->obtener_indice(), resultado);
        delete[] costos;
        delete cola;
    }
    return resultado;
}

void Grafo::construir_path(int parent[], int j, Lista<Vertice*>* &vertices) {
    if (parent[j] == - 1)
        return;
    construir_path(parent, parent[j], vertices);
    vertices->agregar(this->obtener_vertice_por_indice(j));
}

void Grafo::imprimir_path(int parent[], int j) {
    // Caso Base: si j es origen
    if (parent[j] == - 1)
        return;
    imprimir_path(parent, parent[j]);
    cout << j << " ";
}

void Grafo::imprimir_solucion(unsigned int* dist, int n, int parent[]) {
    int src = 0;
    cout << "Vertex\t Distance\tPath" << endl;
    for (unsigned int i = 1; i <= tam; i++)
    {
        cout << endl << src << " -> " << i << " \t\t " << dist[i] << " \t\t " << src << " [ ";
        imprimir_path(parent, i);
        cout << " ]" << endl;
    }
}

int* Grafo::inicializar_vector_rutas() {
    // Vector 'Parent' para almacenar detalladamente el camino mas corto.
    int* parent = new int[this->obtener_tam()];
    parent[0] = -1;
    for (unsigned int i = 1; i <= tam; i++) {
        parent[i] = 0;
    }
    return parent;
}

unsigned int* Grafo::inicializar_vector(Vertice* origen) {
    unsigned int* costos = new unsigned int[this->obtener_tam()];
    for (unsigned int i = 0; i < this->obtener_tam(); i++) {
        costos[i] = INFINITO;
    }
    if (origen != NULL) {
        Lista<Arista*>* adyacentes = origen->obtener_adyacentes();
        adyacentes->iniciar_cursor();
        while (adyacentes->avanzar_cursor()) {
            Arista* analizada = adyacentes->obtener_cursor();
            if (analizada != NULL) {
                Vertice* analizada_destino = analizada->obtener_destino();
                if (analizada_destino != NULL) {
                    unsigned int analizada_peso = analizada->obtener_peso();
                    unsigned int analizada_destino_indice = analizada_destino->obtener_indice();
                    costos[analizada_destino_indice] = analizada_peso;
                }
            }
        }
        costos[origen->obtener_indice()] = 0;
    }
    return costos;
}

ColaPrioridad<Vertice*>* Grafo::inicializar_cola(Vertice* origen, unsigned int* costos) {
    ColaPrioridad<Vertice*>* cola = new ColaPrioridad<Vertice*>();
    this->vertices->iniciar_cursor();
    while (this->vertices->avanzar_cursor()) {
        Vertice* actual = this->vertices->obtener_cursor();
        if (actual != NULL && origen != NULL) {
            if (actual->obtener_indice() != origen->obtener_indice()) {
                cola->acolar(actual, costos[actual->obtener_indice()]);
            }
        }
    }
    return cola;
}
