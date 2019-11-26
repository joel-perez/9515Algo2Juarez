#include <iostream>
using namespace std;


/* FUNCION PRINCIPAL QUE IMPLEMENTA QuickSort*/
void quicksort(int arreglo[],int primero, int ultimo )
{
    int i, j, x, aux;
    i = primero;
    j = ultimo;
    x = arreglo[ (primero + ultimo) /2 ]; //PIVOTE
    do
    {
        while( (arreglo[i] < x) && (j <= ultimo) )
        {
            i++;
        }

        while( (x < arreglo[j]) && (j > primero) )
        {
            j--;
        }

        if( i <= j )
        {
            aux = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = aux;
            i++;
            j--;
        }

    }
    while( i <= j );

    if( primero < j )
        quicksort( arreglo, primero, j );
    if( i < ultimo )
        quicksort( arreglo, i, ultimo );
}

//FUNCION PARA IMPRIMIR EL ARREGLO
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
    quicksort(arreglo, 0, n-1);    //APLICAMOS QUICKSORT
    cout << "arreglo ordenado: \n";
    imprimirarreglo(arreglo, n);
    return 0;
}

