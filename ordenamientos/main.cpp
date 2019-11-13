#include "lista.h"
#include <random>

const int MAX = 10;

using namespace std;

int main()
{
    Lista* l1 = new Lista;

    for (int i=1; i<=MAX; i++) {
        int nuevo = rand() % 127 + 1;
        l1->agregar(nuevo);
    }

    cout << "Lista sin ordenar: " << endl;
    l1->mostrar();

    l1->mergesort();

    cout << "Lista ordenada: " << endl;
    l1->mostrar();
}
