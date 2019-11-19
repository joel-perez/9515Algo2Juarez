#include<iostream>
#include "radixsort.h"
using namespace std;

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Arreglo sin ordenar: ";
    imprimirArreglo(arr,n);
    cout<<"\n";
    radixsort(arr, n);
    cout<<"Arreglo ordenado: ";
    imprimirArreglo(arr, n);
    return 0;
}
