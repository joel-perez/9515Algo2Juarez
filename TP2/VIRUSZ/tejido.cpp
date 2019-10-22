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

//void Tejido::

void Tejido::cargar_vector() {
    Elemento* nuevo = new Elemento; //Esta linea va a volar cuando terminemos los casos de anticuerpo y dosis...
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
        getline(ss, tipo_elemento, CARACTER_SEPARADOR);

        if (tipo_elemento == TIPO_ELEMENTO_CELULA) {
            ss >> tipo_celula;
            ss >> posicion_x;
            ss >> posicion_y;
            agregar_elemento(obtener_celula_desde_string(tipo_celula, posicion_x, posicion_y));
        }
        else if (tipo_elemento == TIPO_ELEMENTO_ANTICUERPO) {
            ss >> posicion_x;
            ss >> posicion_y;
            agregar_elemento(obtener_anticuerpo_desde_string(tipo_elemento,posicion_x, posicion_y));
        }
        else if (tipo_elemento == TIPO_ELEMENTO_DOSIS) {
            ss >> tipo_dosis;
            ss >> cantidad_dosis;
            agregar_elemento(nuevo); // TODO: Esto lo tenemos que completar...
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

void Tejido::mostrar_elemento(int pos) {
    cout << elementos[pos-1]->detalles_datos() << endl;
}

void Tejido::mostrar_todos() {
    for (int i=0; i<indice; i++) {
        cout << "Numero: " << i + 1 << endl
             << elementos[i]->resumen_datos() << endl;
    }
}

int Tejido::obtener_cantidad_elementos() {
    return indice;
}

Tejido::~Tejido() {
    for(int i=0;i<indice;i++)
        delete elementos[i];
}
