#include<iostream>
using namespace std;
#include <math.h>

void radixsort(int x[], int n)
{
    int anterior[10], posterior[10];

    struct {
        int info;
        int siguiente;
    } node[10];

    int exp, primero, i, j, k, p, q, y;

  /* Inicializar una lista vinculada */
    for (i = 0; i < n-1; i++)
    {
        node[i].info = x[i];
        node[i].siguiente = i+1;
    } /* fin del for */

    node[n-1].info = x[n-1];
    node[n-1].siguiente = -1;
    primero = 0; /* primero es la cabeza de la lista vinculada */

    for (k = 1; k < 5; k++)
    {
    /* Suponer que tenemos números de cuatro dígitos como maximo */
        for (i = 0; i < 10; i++)
        {
        /*Inicializar colas */
            posterior[i] = -1;
            anterior[i] = -1;
        } /*fin del for */

        /* Procesar cada elemento en la lista */
        while (primero != -1)
        {
            p = primero;
            primero = node[primero].siguiente;
            y = node[p].info;
            /* Extraer el k-asimo digito */
            exp = pow(10, k-1); /* elevar 10 a la (k-1)ésima potencia */
            j = (y/exp) % 10;
            /* Insertar en cola[j] */
            q = posterior[j];
            if (q == -1)
                anterior[j] = p;
            else
                node[q].siguiente = p;
            posterior[j] = p;
        } /*fin del while */

        /* En este punto, cada registro está en su cola basándose en el dígito k
           Ahora se forma una lista única de todos los elementos de la cola.
           Se encuetra el primer elemento. */
        for (j = 0; j < 10 && anterior[j] == -1; j++);
            ;
        primero = anterior[j];


        /* Vincular las colas restantes */
        while (j <= 9)
        {   /* Verificar si se ha terminado */
            /*Encontrar el elemento siguiente */
            for (i = j+1; i < 10 && anterior[i] == -1; i++);
                ;
            if (i <= 9)
            {
                p = i;
                node[posterior[j]].siguiente = anterior[i];
            } /* fin del if */
            j = i;
        } /* fin del while */
        node[posterior[p]].siguiente = -1;
    } /* fin del for */

    /* Copiar de regreso al archivo original */
    for (i = 0; i < n; i++)
    {
            x[i] = node[primero].info;
            primero = node[primero].siguiente;
    } /*fin del for */
} /* fin de radixsort*/

/* Funcion para imprimir el arreglo */
void imprimirarreglo(int arreglo[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arreglo[i] << " ";
    cout << endl;
}

int main()
{

    int x[] = {1987, 943, 854, 1010, 123, 5341, 578};
    int n = sizeof(x) / sizeof(x[0]);
    cout<<"Arreglo sin ordenar: \n";
    imprimirarreglo(x,n);
    radixsort (x, n);
    cout<<"\nArreglo ordenado: \n";
    imprimirarreglo(x,n);

    return 0;
}
