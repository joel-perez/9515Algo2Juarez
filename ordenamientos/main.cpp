
#include<iostream>
using namespace std;

//funcion que consigue el elemento con valor maximo del vector
int obtener_maximo(int vector[], int n)
{
    int max = vector[0];
    for (int i = 1; i < n; i++)
        if (vector[i] > max)
            max = vector[i];
    return max;
}

//Funcion que hace el conteo del ordenamiento del vector de acuerdo al digito representado por exp.
void conteo_ordenamiento(int vector[], int n, int exp)
{
    int salida[n];
    int i, contar[10] = {0};

    // FUNCION QUE NO SE QUE HACE
    //
    for (i = 0; i < n; i++)
        contar[ (vector[i]/exp)%10 ]++;

    //cambia contar[i] para que ahora contenga las posiciones actuales de los digitos en salida[]
    for (i = 1; i < 10; i++)
        contar[i] += contar[i - 1];

    // crea el vector salida
    for (i = n - 1; i >= 0; i--)
    {
        salida[contar[ (vector[i]/exp)%10 ] - 1] = vector[i];
        contar[ (vector[i]/exp)%10 ]--;
    }

    //copia el vector salida en el vector,
    //asi el vector ahora contiene los numeros ordenados por su digito
    for (i = 0; i < n; i++)
        vector[i] = salida[i];
}

//funcion que crea el vector de valor n
void radixsort(int vector[], int n)
{
    //encuentra el maximo numero con mayor digitos
    int m = obtener_maximo(vector, n);

    //Hace el conteo de cada digito. En vez de pasar el valor del digito, se pasa el valor de exp.
    //Exp es 10^i donde i es el digito
    for (int exp = 1; m/exp > 0; exp *= 10)
        conteo_ordenamiento(vector, n, exp);
}

//imprime el vector
void imprimir(int vector[], int n)
{
    for (int i = 0; i < n; i++)
        cout << vector[i] << " ";
}

int main()
{
    int vector[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(vector)/sizeof(vector[0]);
    cout<<"Vector sin ordenar:"<<endl;
    imprimir(vector, n);
    radixsort(vector, n);
    cout<<"\n\nVector ordenado:"<<endl;
    imprimir(vector, n);
    return 0;
}
