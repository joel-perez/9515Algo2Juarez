#include "lista.h"
#include <random>

const int MAX = 10;

using namespace std;

int main()
{
    Lista l1;

    for (int i=1; i<=MAX; i++) {
        int nuevo = rand() % 127 + 1;
        l1.agregar(nuevo);
    }

    Nodo *primero = l1.obtener_primero();

    cout << "Lista sin ordenar: " << endl;
    l1.mostrar();

    l1.mergesort(&primero);

    cout << "Lista ordenada: " << endl;
    l1.mostrar();

}
