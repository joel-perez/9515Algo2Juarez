#include "main.h"

using namespace std;

/*
void leer_archivo () {
    ifstream estado;
    estado.open ("estado.txt");
    if (!estado)
    {
        cout << "ERROR! no se pudo abrir el archivo" << endl;
        return;
    }
}
*/

int main() {
    //leer_archivo();
    Tejido* tejido = new Tejido;
    tejido->cargar_vector();
    cout << "Seleccione una opcion:" << endl
         << "1 - Mostrar listado de todos los elementos cargados." << endl
         << "2 - Mostrar detalle de un elemento en particular." << endl
         << "3 - Salir." << endl << endl;
    tejido->mostrar_todos();

    delete tejido;

    return 0;
}
