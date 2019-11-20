#include "quicksort.h"
#include <iostream>
using namespace std;
// MAIN
int main()
{
    int arreglo[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    quickSort(arreglo, 0, n-1);
    cout << "arreglo ordenado: \n";
    imprimirarreglo(arreglo, n);
    return 0;
}

