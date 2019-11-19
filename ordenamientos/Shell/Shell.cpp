#include <iostream>

using namespace std;

int OrdenamientoShell(int vector[], int n) {
    //comienza con la mitad mas grande y la va reduciendo hasta que sea igual a 0
    for (int mitad = n/2; mitad > 0; mitad /= 2)  {
        /*Luego de asignar el valor a mitad, asigna a i ese valor el cual debe ser menor que la cantidad de elementos
        y recorre el vector hasta que i sea igual a n.*/
        for (int i = mitad; i < n; i += 1) {
            // el elemento que esta dentro de la posicion i
            //(que es igual a mitad) es asignada a la variable aux
            int aux = vector[i];
            //mientras j sea menor o igual a la mitad y el elemento en posiciones menores a mitad sea mayor al elemento
            // auxiliar, el elemento de j sera igual al elemento en posiciones menores a mitad
            int j;
            for (j = i; j >= mitad && vector[j-mitad] > aux; j -= mitad)
              vector[j] = vector[j-mitad];

            //le asigna el elemento aux a la posicion j del vector
            vector[j] = aux;
        }
    }
    return 0;
}

void imprimirVector(int vector[], int n)
{
    for (int i=0; i<n; i++)
        cout << vector[i] << " ";
}

int main()
{
    int vector[] = {12, 34, 54, 2, 3}, i;
    int n = sizeof(vector)/sizeof(vector[0]);

    cout << "Vector antes del ordenamiento: \n";
    imprimirVector(vector, n);

    OrdenamientoShell(vector, n);

    cout << "\nVector despues del ordenamiento: \n";
    imprimirVector(vector, n);

    return 0;
}
