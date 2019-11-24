#include "tejido.h"

using namespace std;

Tejido::Tejido() {
    indice = 0;                              // TODO: Esto va a volar...
    for (int i = 0; i < MAX_ELEMENTOS; i++)  // TODO: Esto va a volar...
        elementos[i] = 0;                    // TODO: Esto va a volar...
    grafo = new Grafo();
}

void Tejido::agregar_elemento(Elemento *e) {
    elementos[indice] = e; // TODO: Esto va a volar...
    indice++;              // TODO: Esto va a volar...
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
            agregar_elemento(obtener_dosis_desde_string(tipo_dosis, cantidad_dosis));
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

void Tejido::mostrar_elemento(int pos) {
    cout << elementos[pos-1]->detalles_datos() << endl << endl;
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

Lista<CoordenadasRelacion*>* Tejido::obtener_coordenadas_relaciones(){
    // TODO: Implementar el recorrido del grafo y armar una lista con las coordenadas de inicio y de fin de cada linea...
    //       ...esto es solo para probar que esta dibujando bien las lineas en pantalla.
    Lista<CoordenadasRelacion*>* resultado = new Lista<CoordenadasRelacion*>();
    CoordenadasRelacion* coordenadas_relacion;
    coordenadas_relacion = new CoordenadasRelacion(100,100,200,200);
    resultado->agregar(coordenadas_relacion);
    coordenadas_relacion = new CoordenadasRelacion(200,200,300,100);
    resultado->agregar(coordenadas_relacion);
    coordenadas_relacion = new CoordenadasRelacion(300,100,100,100);
    resultado->agregar(coordenadas_relacion);
    return resultado;
}

Tejido::~Tejido() {
    for(int i=0;i<indice;i++) // TODO: Esto va a volar...
        delete elementos[i];  // TODO: Esto va a volar...
    delete grafo;
}
