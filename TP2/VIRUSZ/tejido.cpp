#include <iostream>
#include <fstream>
#include <string>
#include "tejido.h"

using namespace std;

Tejido::Tejido() {
    indice = 0;
    elementos = 0;
}

void Tejido::agregar_elemento(Elemento *e) {
    elementos[indice] = e;
    indice++;
}

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
            resultado->AgregarCelula(ObtenerTipoCelulaDesdeString(tipoCelula));
        }
        else if (tipoElemento == TIPO_ELEMENTO_ANTICUERPO) {
            resultado->AgregarAnticuerpo();
        }
        else if (tipoElemento == TIPO_ELEMENTO_DOSIS) {
            ss >> tipoDosis;
            ss >> cantidadDosis;
            resultado->AgregarDosis(ObtenerTipoDosisDesdeString(tipoDosis), cantidadDosis);
        }
    }
    entrada.close();
    return resultado;
}

void Tejido::mostrar_elemento(int pos) {
    cout << elementos[pos-1]->resumen_datos() << endl;
}

void Tejido::mostrar_todos() {
    for (int i=0; i<indice; i++) {
        cout << elementos[i]->detalles_datos() << endl;
    }
}
