#include <iostream>
#include "radixsort.h"
using namespace std;

//Funcion para obtener el maximo valor del arreglo
int maxValorDelArreglo(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

//Funcion que cuenta elementos del arreglo acorde a un digito
//representado por exp
void conteo(int arr[], int n, int exp)
{
    int vectorDeSalida[n]; // vector de salida
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in vectorDeSalida[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    //Construye el vector de salida
    for (i = n-1; i >= 0; i--)
    {
        vectorDeSalida[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    //Copia el vector de salida a arr[],
    //arr[] ahora contiene elementos ordenados acorde al digito actual
    for (i = 0; i < n; i++)
        arr[i] = vectorDeSalida[i];
}


//Funcion principal que ordena un arreglo de tamanio n
//usando Radix Sort
void radixsort(int arr[], int n)
{
    //Encuentra el valor maximo para saber cuantos digitos tiene
    int m = maxValorDelArreglo(arr, n);

    //Realiza el conteo para cada digito. exp es pasado como parametro
    //exp es 10^i
    //i es el digito actual
    for (int exp = 1; m/exp > 0; exp *= 10)
        conteo(arr, n, exp);
}

//Funcion para imprimir un arreglo
void imprimirArreglo(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
