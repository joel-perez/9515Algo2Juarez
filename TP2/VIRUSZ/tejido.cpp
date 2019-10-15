#include <iostream>
#include <fstream>
#include <string>
#include "tejido.h"

using namespace std;

Tejido::Tejido() {
    indice = 0;
    for (int i = 0; i < MAX_ELEMENTOS; i++)
        elementos[i] = 0;
}

void Tejido::agregar_elemento(Elemento *e) {
    elementos[indice] = e;
    indice++;
}

void Tejido::

void Tejido::cargar_vector() {
    Elemento* nuevo = new Elemento;
    ifstream entrada;
    entrada.open(ARCHIVO_DATOS.c_str());

    string linea;
    while (getline(entrada, linea)) {
        stringstream ss(linea);
        string tipoElemento;
        string tipoCelula;
        string tipoDosis;
        int cantidadDosis;
        getline(ss, tipoElemento, CARACTER_SEPARADOR);

        if (tipoElemento == TIPO_ELEMENTO_CELULA) {
            ss >> tipoCelula;
            agregar_elemento(nuevo); // TODO: Esto lo tenemos que completar...
        }
        else if (tipoElemento == TIPO_ELEMENTO_ANTICUERPO) {
            agregar_elemento(nuevo); // TODO: Esto lo tenemos que completar...
        }
        else if (tipoElemento == TIPO_ELEMENTO_DOSIS) {
            ss >> tipoDosis;
            ss >> cantidadDosis;
            agregar_elemento(nuevo); // TODO: Esto lo tenemos que completar...
        }
    }
    entrada.close();
}

void Tejido::mostrar_elemento(int pos) {
    cout << elementos[pos-1]->resumen_datos() << endl;
}

void Tejido::mostrar_todos() {
    for (int i=0; i<indice; i++) {
        cout << elementos[i]->detalles_datos() << endl;
    }
}

Tejido::~Tejido() {
    for(int i=0;i<indice;i++)
        delete elementos[i];
}
