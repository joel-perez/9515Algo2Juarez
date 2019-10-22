#include "main.h"

using namespace std;

int main() {
    mostrar_bienvenida();
    Tejido* tejido = new Tejido;
    tejido->cargar_vector();
    menu_principal(tejido);
    delete tejido;
    return 0;
}

void mostrar_bienvenida() {
    cout << "Algoritmos y Programacion II" << endl
         << "Trabajo Practico Grupal Nro 2: Virus Z" << endl
         << "Grupo: Sobrecargados!" << endl
         << endl;
}

void menu_principal(Tejido* tejido) {
    int accion_seleccionada = 0;
	while (accion_seleccionada != 3) {
    cout << "Seleccione una opcion:" << endl
         << "1 - Mostrar listado de todos los elementos cargados." << endl
         << "2 - Mostrar detalle de un elemento en particular." << endl
         << "3 - Salir." << endl << endl;
         accion_seleccionada = solicitar_valor(1, 3);
         switch (accion_seleccionada){
            case 1:
                tejido->mostrar_todos();
            break;
            case 2:
                int cantidad_elementos = tejido->obtener_cantidad_elementos();
                cout << "Ingrese un numero de elemento entre 1 y " << cantidad_elementos << endl;
                int indice_elemento_seleccionado = solicitar_valor(1, cantidad_elementos);
                tejido->mostrar_elemento(indice_elemento_seleccionado);
            break;
         }
	}
}

unsigned int solicitar_valor(unsigned int min_valor, unsigned int max_valor) {
    unsigned int numero = 0;
    bool es_valido = false;
    while (!es_valido) {
        if (!(cin >> numero)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Debe ingresar un numero valido." << endl;
        } else {
            es_valido = (numero >= min_valor && numero <= max_valor);
            if (!es_valido) {
                cout << "Debe ingresar un numero entre " << min_valor << " y " << max_valor << endl;
            }
        }
    }
    return numero;
}
