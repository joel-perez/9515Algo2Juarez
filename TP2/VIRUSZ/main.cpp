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

    tejido->mostrar_todos();

    delete tejido;

    return 0;
}
