#include "tejido.h"

using namespace std;

Tejido::Tejido() {
    grafo = new Grafo();
    anticuerpo = new Anticuerpo ();
    lista = new Lista<Elemento*>();
    cargador_dosis = new Lista<Elemento*>();
}

void Tejido::agregar_celula(Elemento *e, unsigned int acumulador) {
    grafo->insertar_nodo(e);
    if (acumulador > 1) {
        if (acumulador % 2 == 0)
            grafo->insertar_arista(e, grafo->obtener_vertice_por_indice(acumulador-1)->obtenerElemento());
        else {
            grafo->insertar_arista(e, grafo->obtener_vertice_por_indice(acumulador-1)->obtenerElemento());
            grafo->insertar_arista(e, grafo->obtener_vertice_por_indice(acumulador-2)->obtenerElemento());
        }
    }
}

void Tejido::agregar_anticuerpo(Elemento* e) {
    lista->agregar(e);
}

Lista <Anticuerpo*>* Tejido:: mover_anticuerpos(Elemento* e){
  while (!lista->esta_vacia()){
    anticuerpo -> posicion_aleatoria ();
  }
}

void Tejido::agregar_dosis(Elemento *e) {
    cargador_dosis->agregar(e);
}

void Tejido::cargar_archivo() {
    ifstream entrada;
    entrada.open(ARCHIVO_DATOS.c_str());

    int acumulador = 1;
    string linea;
    while (getline(entrada, linea)) {
        stringstream ss(linea);
        string tipo_elemento;
        string tipo_celula;
        string tipo_dosis;
        float posicion_x;
        float posicion_y;
        int cantidad_dosis;
        getline(ss, tipo_elemento, CARACTER_SEPARADOR);

        if (tipo_elemento == TIPO_ELEMENTO_CELULA) {
            ss >> tipo_celula;
            ss >> posicion_x;
            ss >> posicion_y;
            agregar_celula(obtener_celula_desde_string(tipo_celula, posicion_x, posicion_y), acumulador);
            acumulador++;
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
    }
    entrada.close();
}

Celula* Tejido::obtener_celula_desde_string(string tipo_celula, float posicion_x, float posicion_y) {
    if (tipo_celula == TIPO_CELULA_S)
        return new Celula(tipo_celula, posicion_x, posicion_y);
    else if (tipo_celula == TIPO_CELULA_X)
        return new CelulaInflamada(tipo_celula, posicion_x, posicion_y);
    else if (tipo_celula == TIPO_CELULA_Y)
        return new CelulaInflamada(tipo_celula, posicion_x, posicion_y);
    else if (tipo_celula == TIPO_CELULA_Z)
        return new CelulaMutada(tipo_celula, posicion_x, posicion_y);
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
    vertices->iniciar_cursor();
    while (vertices->avanzar_cursor()) {
        Vertice* vertice_actual = vertices->obtener_cursor();
        Elemento* elemento_actual = vertice_actual->obtenerElemento();
        float inicio_x = elemento_actual->obtener_posicion_x();
        float inicio_y = elemento_actual->obtener_posicion_y();
        Lista<Arista*>* aristas = vertice_actual->obtenerAdyacentes();
        aristas->iniciar_cursor();
        while (aristas->avanzar_cursor()) {
            Arista* arista_actual = aristas->obtener_cursor();
            Vertice* vertice_destino = arista_actual->obtenerDestino();
            Elemento* elemento_destino = vertice_destino->obtenerElemento();
            float destino_x = elemento_destino->obtener_posicion_x();
            float destino_y = elemento_destino->obtener_posicion_y();
            coordenadas_relacion = new CoordenadasRelacion(inicio_x, inicio_y, destino_x, destino_y);
            resultado->agregar(coordenadas_relacion);
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
        Elemento* elemento_actual = vertice_actual->obtenerElemento();
        float pos_x = elemento_actual->obtener_posicion_x();
        float pos_y = elemento_actual->obtener_posicion_y();
        imagenes tipo = obtener_tipo_imagenes_desde_string(elemento_actual->obtener_tipo());
        coordenadas_elemento = new CoordenadasElemento(pos_x, pos_y, tipo);
        resultado->agregar(coordenadas_elemento);
    }
    return resultado;
}

Tejido::~Tejido() {
    delete grafo;
}
