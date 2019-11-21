#include <iostream>
using namespace std;

// Funcion para intercambiar dos elementos
void intercambiar(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/*Función que toma el último elemento como pivote, situa
el elemento pivote en su posición correcta en el arreglo
ordenado y coloca todos los elementos más pequeños que el
a su izquierda, y todos los elementos mayores a su derecha
*/
int dividir (int arreglo[], int primero, int ultimo)
{
    int pivote = arreglo[ultimo]; // pivote
    int i = (primero - 1); // indice del elemento menor

    for (int j = primero; j <= ultimo - 1; j++)
    {
        // Si el elemento es menor que el pivotee
        if (arreglo[j] < pivote)
        {
            i++; // incrementa el indice del elemento menor
            intercambiar(&arreglo[i], &arreglo[j]);
        }
    }
    intercambiar(&arreglo[i + 1], &arreglo[ultimo]);
    return (i + 1);
}

/* FUNCION PRINCIPAL QUE IMPLEMENTA QuickSort
arreglo[] --> arreglo a ser ordenado,
primero --> Indice del comienzo
ultimo --> Indice del final */
void quickSort(int arreglo[], int primero, int ultimo)
{
    if (primero < ultimo)
    {
        /* pi divide el indice, arreglo[p] ahora esta
        en el lugar correcto */
        int pi = dividir(arreglo, primero, ultimo);

        // Separar elementos antes separados
        // dividir y despues dividir
        quickSort(arreglo, primero, pi - 1);
        quickSort(arreglo, pi + 1, ultimo);
    }
}

/* Funcion para imprimir el arreglo */
void imprimirarreglo(int arreglo[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arreglo[i] << " ";
    cout << endl;
}

// MAIN
int main()
{
    int arreglo[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    cout << "arreglo sin ordenar: \n";
    imprimirarreglo(arreglo, n);
    quickSort(arreglo, 0, n-1);
    cout << "arreglo ordenado: \n";
    imprimirarreglo(arreglo, n);
    return 0;
}

