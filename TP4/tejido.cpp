#include "tejido.h"

using namespace std;

Tejido::Tejido() {
    grafo = new Grafo();
    lista = new Lista<Anticuerpo*>();
    cargador_dosis = new Lista<Suero*>();
}

Grafo* Tejido::obtener_grafo() {
    return grafo;
}

Lista<Suero*>* Tejido::obtener_cargador_dosis() {
    return cargador_dosis;
}

void Tejido::asignar_dosis() {
    dosis_a_disponibles = 0;
    dosis_b_disponibles = 0;
    obtener_cargador_dosis()->iniciar_cursor();
    while (obtener_cargador_dosis()->avanzar_cursor()) {
        TipoDosis tipo = obtener_cargador_dosis()->obtener_cursor()->obtener_tipo_dosis();
        int cant_dosis = obtener_cargador_dosis()->obtener_cursor()->obtener_cantidad_dosis();
        if (tipo == A)
            dosis_a_disponibles += cant_dosis;
        else
            dosis_b_disponibles += cant_dosis;
    }
}

void Tejido::agregar_celula(Elemento *e, unsigned int indice_celula) {
    grafo->insertar_nodo(e, indice_celula);
}

void Tejido::agregar_filamento(unsigned int indice_vertice_origen, unsigned int indice_vertice_destino, unsigned int peso) {
    grafo->insertar_arista(indice_vertice_origen, indice_vertice_destino, peso);
}

void Tejido::agregar_anticuerpo(Anticuerpo* a) {
    lista->agregar(a);
}

void Tejido::agregar_dosis(Suero *s) {
    cargador_dosis->agregar(s);
}

void Tejido::cargar_archivo() {
    ifstream entrada;
    entrada.open(ARCHIVO_DATOS.c_str());

    string linea;
    while (getline(entrada, linea)) {
        stringstream ss(linea);
        string tipo_elemento;
        string tipo_celula;
        string tipo_dosis;
        float posicion_x;
        float posicion_y;
        int cantidad_dosis;
        int indice_celula;
        int filamento_origen;
        int filamento_destino;
        int filamento_peso;
        getline(ss, tipo_elemento, CARACTER_SEPARADOR);

        if (tipo_elemento == TIPO_ELEMENTO_CELULA) {
            ss >> indice_celula;
            ss >> tipo_celula;
            ss >> posicion_x;
            ss >> posicion_y;
            agregar_celula(obtener_celula_desde_string(tipo_celula, posicion_x, posicion_y, indice_celula), indice_celula);
        }
        else if (tipo_elemento == TIPO_ELEMENTO_ANTICUERPO) {
            ss >> posicion_x;
            ss >> posicion_y;
            agregar_anticuerpo(obtener_anticuerpo_desde_string(tipo_elemento,posicion_x, posicion_y));
        }
        else if (tipo_elemento == TIPO_ELEMENTO_DOSIS) {
            ss >> tipo_dosis;
            ss >> cantidad_dosis;
            agregar_dosis(obtener_dosis_desde_string(tipo_dosis, cantidad_dosis));
        }
        else if (tipo_elemento == TIPO_ELEMENTO_FILAMENTO) {
            ss >> filamento_origen;
            ss >> filamento_destino;
            ss >> filamento_peso;
            agregar_filamento(filamento_origen, filamento_destino, filamento_peso);
        }
    }
    entrada.close();
}

void Tejido::duplicar(Vertice* original) {
    Elemento* nuevo = NULL;
    if (original->obtener_elemento()->obtener_tipo() == TIPO_CELULA_S)
        nuevo = new Celula(original->obtener_elemento()->obtener_tipo(),
                           original->obtener_elemento()->obtener_posicion_x() + CORRIMIENTO,
                           original->obtener_elemento()->obtener_posicion_y());
    else if (original->obtener_elemento()->obtener_tipo() == TIPO_CELULA_Z)
        nuevo = new CelulaMutada(original->obtener_elemento()->obtener_tipo(),
                                 original->obtener_elemento()->obtener_posicion_x() + CORRIMIENTO,
                                 original->obtener_elemento()->obtener_posicion_y());
    if (nuevo != NULL) {
        grafo->insertar_nodo(nuevo, 0);
        grafo->insertar_arista(nuevo, original->obtener_elemento(), 0); // TODO: Revisar si esta bien este peso nulo...
    }
}

void Tejido::impacto_destructivo(Vertice* vertice_actual) {
    if (vertice_actual != NULL && dosis_a_disponibles > 0) {
        Elemento* elemento_actual = vertice_actual->obtener_elemento();
        if (elemento_actual != NULL) {
            if (elemento_actual->obtener_tipo() == TIPO_CELULA_Y) {
                Elemento* nuevo = new CelulaInflamada(TIPO_CELULA_X,
                                                      elemento_actual->obtener_posicion_x(),
                                                      elemento_actual->obtener_posicion_y());
                vertice_actual->cambiar_elemento(nuevo);
                delete elemento_actual;
            }
            else if (elemento_actual->obtener_tipo() == TIPO_CELULA_Z) {
                Elemento* nuevo = new CelulaInflamada(TIPO_CELULA_Y,
                                                      elemento_actual->obtener_posicion_x(),
                                                      elemento_actual->obtener_posicion_y());
                vertice_actual->cambiar_elemento(nuevo);
                delete elemento_actual;
            }
            else {
                grafo->eliminar_nodo(vertice_actual);
            }
        }
        dosis_a_disponibles--;
    }
}

void Tejido::impacto_constructivo(Vertice* vertice_actual) {
    if (vertice_actual != NULL && dosis_b_disponibles > 0) {
        Elemento* elemento_actual = vertice_actual->obtener_elemento();
        if (elemento_actual->obtener_tipo() == TIPO_CELULA_X) {
            Elemento* nuevo = new CelulaInflamada(TIPO_CELULA_Y,
                                                  elemento_actual->obtener_posicion_x(),
                                                  elemento_actual->obtener_posicion_y());
            vertice_actual->cambiar_elemento(nuevo);
            delete elemento_actual;
        }
        else if (elemento_actual->obtener_tipo() == TIPO_CELULA_Y) {
            Elemento* nuevo = new CelulaMutada(TIPO_CELULA_Z,
                                               elemento_actual->obtener_posicion_x(),
                                               elemento_actual->obtener_posicion_y());
            vertice_actual->cambiar_elemento(nuevo);
            delete elemento_actual;
        }
        else
            duplicar(vertice_actual);
        dosis_b_disponibles--;
    }
}

void Tejido::empeorar_estado(Vertice* vertice_actual) {
    if (vertice_actual != NULL) {
	    Elemento* elemento_actual = vertice_actual->obtener_elemento();
        if (elemento_actual->obtener_tipo() == TIPO_CELULA_S) {
            Elemento* nuevo = new CelulaInflamada(TIPO_CELULA_X,
                                                  elemento_actual->obtener_posicion_x(),
                                                  elemento_actual->obtener_posicion_y());
            vertice_actual->cambiar_elemento(nuevo);
            delete elemento_actual;
        }
        else if (elemento_actual->obtener_tipo() == TIPO_CELULA_X) {
            Elemento* nuevo = new CelulaInflamada(TIPO_CELULA_Y,
                                                  elemento_actual->obtener_posicion_x(),
                                                  elemento_actual->obtener_posicion_y());
            vertice_actual->cambiar_elemento(nuevo);
            delete elemento_actual;
        }
        else if (elemento_actual->obtener_tipo() == TIPO_CELULA_Y) {
            Elemento* nuevo = new CelulaMutada(TIPO_CELULA_Z,
                                                  elemento_actual->obtener_posicion_x(),
                                                  elemento_actual->obtener_posicion_y());
            vertice_actual->cambiar_elemento(nuevo);
            delete elemento_actual;
        }
    }
}

void Tejido::generar_anticuerpo() {
    float pos_x = rand() % SCREEN_WIDTH;
    float pos_y = rand() % SCREEN_HEIGHT;
    Anticuerpo* nuevo_anticuerpo = new Anticuerpo(TIPO_ELEMENTO_ANTICUERPO, pos_x, pos_y);
    agregar_anticuerpo(nuevo_anticuerpo);
}

Lista<Anticuerpo*>* Tejido::obtener_lista_anticuerpos(){
    return lista;
}

Celula* Tejido::obtener_celula_desde_string(string tipo_celula, float posicion_x, float posicion_y, int indice_celula) {
    if (tipo_celula == TIPO_CELULA_S)
        return new Celula(tipo_celula, posicion_x, posicion_y); // TODO: Agregar el parametro indice_celula...
    else if (tipo_celula == TIPO_CELULA_X)
        return new CelulaInflamada(tipo_celula, posicion_x, posicion_y); // TODO: Agregar el parametro indice_celula...
    else if (tipo_celula == TIPO_CELULA_Y)
        return new CelulaInflamada(tipo_celula, posicion_x, posicion_y); // TODO: Agregar el parametro indice_celula...
    else if (tipo_celula == TIPO_CELULA_Z)
        return new CelulaMutada(tipo_celula, posicion_x, posicion_y); // TODO: Agregar el parametro indice_celula...
    else
        return new Celula();
}

Anticuerpo* Tejido::obtener_anticuerpo_desde_string(string anticuerpo, float posicion_x, float posicion_y) {
    return new Anticuerpo(anticuerpo, posicion_x, posicion_y);
}

Suero* Tejido::obtener_dosis_desde_string(string tipo_dosis, int cantidad_dosis) {
    return new Suero(TIPO_ELEMENTO_DOSIS, 0, 0, obtener_tipo_dosis_desde_string(tipo_dosis), cantidad_dosis);
}

Lista<CoordenadasRelacion*>* Tejido::obtener_coordenadas_relaciones(){
    Lista<CoordenadasRelacion*>* resultado = new Lista<CoordenadasRelacion*>();
    CoordenadasRelacion* coordenadas_relacion;
    Lista<Vertice*>* vertices = grafo->obtener_vertices();
    if (vertices != NULL) {
        vertices->iniciar_cursor();
        while (vertices->avanzar_cursor()) {
            Vertice* vertice_actual = vertices->obtener_cursor();
            if (vertice_actual != NULL) {
                Elemento* elemento_actual = vertice_actual->obtener_elemento();
                if (elemento_actual != NULL) {
                    float inicio_x = elemento_actual->obtener_posicion_x();
                    float inicio_y = elemento_actual->obtener_posicion_y();
                    Lista<Arista*>* aristas = vertice_actual->obtener_adyacentes();
                    if (aristas != NULL) {
                        aristas->iniciar_cursor();
                        while (aristas->avanzar_cursor()) {
                            Arista* arista_actual = aristas->obtener_cursor();
                            if (arista_actual != NULL) {
                                Vertice* vertice_destino = arista_actual->obtener_destino();
                                if (vertice_destino != NULL) {
                                    Elemento* elemento_destino = vertice_destino->obtener_elemento();
                                    if (elemento_destino != NULL) {
                                        float destino_x = elemento_destino->obtener_posicion_x();
                                        float destino_y = elemento_destino->obtener_posicion_y();
                                        coordenadas_relacion = new CoordenadasRelacion(inicio_x, inicio_y, destino_x, destino_y);
                                        resultado->agregar(coordenadas_relacion);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return resultado;
}

Lista<CoordenadasElemento*>* Tejido::obtener_coordenadas_celulas(){
    Lista<CoordenadasElemento*>* resultado = new Lista<CoordenadasElemento*>();
    CoordenadasElemento* coordenadas_elemento;
    Lista<Vertice*>* vertices = grafo->obtener_vertices();
    vertices->iniciar_cursor();
    while (vertices->avanzar_cursor()) {
        Vertice* vertice_actual = vertices->obtener_cursor();
        Elemento* elemento_actual = vertice_actual->obtener_elemento();
        float pos_x = elemento_actual->obtener_posicion_x();
        float pos_y = elemento_actual->obtener_posicion_y();
        imagenes tipo = obtener_tipo_imagenes_desde_string(elemento_actual->obtener_tipo());
        int indice = vertice_actual->obtener_indice();
        coordenadas_elemento = new CoordenadasElemento(pos_x, pos_y, tipo, indice);
        resultado->agregar(coordenadas_elemento);
    }
    return resultado;
}

Lista<CoordenadasElemento*>* Tejido::obtener_coordenadas_anticuerpos(){
    Lista<CoordenadasElemento*>* resultado = new Lista<CoordenadasElemento*>();
    CoordenadasElemento* coordenadas_anticuerpo;
    lista->iniciar_cursor();
    while (lista->avanzar_cursor()) {
        Anticuerpo* anticuerpo_actual = lista->obtener_cursor();
        float pos_x = anticuerpo_actual->obtener_posicion_x();
        float pos_y = anticuerpo_actual->obtener_posicion_y();
        imagenes tipo = obtener_tipo_imagenes_desde_string(anticuerpo_actual->obtener_tipo());
        coordenadas_anticuerpo = new CoordenadasElemento(pos_x, pos_y, tipo, 0);
        resultado->agregar(coordenadas_anticuerpo);
    }
    return resultado;
}

unsigned int Tejido::obtener_cantidad_celulas(string tipo_celula){
    int contador = 0;
    Lista<Vertice*>* celulas = grafo->obtener_vertices();
    celulas->iniciar_cursor();
    while (celulas->avanzar_cursor()) {
        Elemento* celula_actual = celulas->obtener_cursor()->obtener_elemento();
        if (celula_actual->obtener_tipo() == tipo_celula)
            contador++;
    }
    return contador;
}

unsigned int Tejido::obtener_cantidad_total_celulas(){
    return grafo->obtener_tam();
}

int Tejido::obtener_dosis_a_disponibles() {
    return dosis_a_disponibles;
}

int Tejido::obtener_dosis_b_disponibles() {
    return dosis_b_disponibles;
}

Vertice* Tejido::obtener_vertice_segun_id_celula(unsigned int id) {
    Lista<Vertice*>* vertices = this->grafo->obtener_vertices();
    vertices->iniciar_cursor();
    while (vertices->avanzar_cursor()) {
        Celula* celula_actual = (Celula*)vertices->obtener_cursor()->obtener_elemento();
        if (celula_actual->obtener_id_celula() == id)
            return vertices->obtener_cursor();
    }
    return NULL;
}

Tejido::~Tejido() {
    delete grafo;
    delete lista;
    delete cargador_dosis;
}
