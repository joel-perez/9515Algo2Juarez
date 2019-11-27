#include <iostream>
using namespace std;

//FUNCION PARA IMPRIMIR EL ARREGLO
void imprimirarreglo(int [], int);

//FUNCION PRINCIPAL QUE IMPLEMENTA QuickSort
void quicksort(int [],int, int);

int main()
{
    int arreglo[] = {11,8,2,6,9,1,5,4};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    cout << "arreglo sin ordenar: \n";
    imprimirarreglo(arreglo, n);
    quicksort(arreglo, 0, n-1);    //APLICAMOS QUICKSORT
    cout << "arreglo ordenado: \n";
    imprimirarreglo(arreglo, n);
    return 0;
}


void quicksort(int arreglo[],int primero, int ultimo )
{
    int i, j, central, pivote;
    i = primero;
    j = ultimo;
    central = ((primero + ultimo) /2);
    pivote = arreglo[central];
    do
    {
        //SEPARA EN DOS EL ARRAY
        while (arreglo[i] < pivote) //VALORES MENORES QUE EL PIVOTE
        {
            i++;
        }

        while (pivote < arreglo[j]) //VALORES MAYORES QUE EL PIVOTE
        {
            j--;
        }

        if( i <= j )
        {
            int aux;
            //INTERCAMBIO DE VALORES
            aux = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = aux;
            i++;
            j--;
        }

    } while ( i <= j );

    if (primero < j )
        quicksort( arreglo, primero, j ); //LA PRIMERA POSICION ASUME EL VALOR DE primero,  Y LA SEGUNDA DE j
    if (i < ultimo)
        quicksort( arreglo, i, ultimo ); //LA PRIMERA POSICION ES i, Y LA ULTIMA ultimo
}


void imprimirarreglo(int arreglo[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arreglo[i] << " ";
    cout << endl;
}

