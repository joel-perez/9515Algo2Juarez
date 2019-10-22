#include "main.h"

using namespace std;

int main() {
    mostrarBienvenida();
    Tejido* tejido = new Tejido;
    tejido->cargar_vector();
    menu_principal(tejido);
    delete tejido;
    return 0;
}

void mostrarBienvenida() {
    cout << "Algoritmos y Programacion II" << endl
         << "Trabajo Practico Grupal Nro 2: Virus Z" << endl
         << "Grupo: Sobrecargados!" << endl
         << endl;
}

void menu_principal(Tejido* tejido) {
    cout << "Seleccione una opcion:" << endl
         << "1 - Mostrar listado de todos los elementos cargados." << endl
         << "2 - Mostrar detalle de un elemento en particular." << endl
         << "3 - Salir." << endl << endl;
    tejido->mostrar_todos();
}
