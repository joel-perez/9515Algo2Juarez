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
        int cantidad_dosis;
        getline(ss, tipo_elemento, CARACTER_SEPARADOR);

        if (tipo_elemento == TIPO_ELEMENTO_CELULA) {
            ss >> tipo_celula;
            agregar_elemento(obtener_celula_desde_string(tipo_celula));
        }
        else if (tipo_elemento == TIPO_ELEMENTO_ANTICUERPO) {
            agregar_elemento(nuevo); // TODO: Esto lo tenemos que completar...
        }
        else if (tipo_elemento == TIPO_ELEMENTO_DOSIS) {
            ss >> tipo_dosis;
            ss >> cantidad_dosis;
            agregar_elemento(nuevo); // TODO: Esto lo tenemos que completar...
        }
    }
    entrada.close();
}

Celula* Tejido::obtener_celula_desde_string(string tipo_celula) {
    if (tipo_celula == TIPO_CELULA_S)
        return new Celula();
    else if (tipo_celula == TIPO_CELULA_X)
        return new CelulaInflamada();
    else if (tipo_celula == TIPO_CELULA_Y)
        return new CelulaInflamada();
    else if (tipo_celula == TIPO_CELULA_Z)
        return new CelulaMutada();
    else
        return new Celula(); // Los demas casos van a ir con un constructor con parametros, este va a ir vacio...
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
