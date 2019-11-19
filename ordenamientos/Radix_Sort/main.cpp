#include<iostream>
using namespace std;
#include <math.h>
#define NUMELTS 20

void radixsort(int x[], int n)
{
    int anterior[10], posterior[10];

    struct {
        int info;
        int next;
    } node[NUMELTS];

    int exp, first, i, j, k, p, q, y;

  /* Inicializar una lista vinculada */
    for (i = 0; i < n-1; i++)
    {
        node[i].info = x[i];
        node[i].next = i+1;
    } /* fin del for */

    node[n-1].info = x[n-1];
    node[n-1].next = -1;
    first = 0; /* first es la cabeza de la lista vinculada */

    for (k = 1; k < 5; k++)
    {
    /* Suponer que tenemos números de cuatro dígitos */
        for (i = 0; i < 10; i++)
        {
        /*Inicializar colas */
            posterior[i] = -1;
            anterior[i] = -1;
        } /*fin del for */

        /* Procesar cada elemento en la lista */
        while (first != -1)
        {
            p = first;
            first = node[first].next;
            y = node[p].info;
            /* Extraer el kâsimo dÁgito */
            exp = pow(10, k-1); /* elevar 10 a la (k-1)ésima potencia */
            j = (y/exp) % 10;
            /* Insertar y en queue[j] */
            q = posterior[j];
            if (q == -1)
                anterior[j] = p;
            else
                node[q].next = p;
            posterior[j] = p;
        } /*fin del while */

        /* En este punto, cada registro está en su cola basándose en el dígito k
           Ahora formar una lista única de todos los elementos de la cola.
           Encontrar el primer elemento. */
        for (j = 0; j < 10 && anterior[j] == -1; j++);
            ;
        first = anterior[j];

        /* Vincular las colas restantes */
        while (j <= 9)
        {   /* Verificar si se ha terminado */
            /*Encontrar el elemento siguiente */
            for (i = j+1; i < 10 && anterior[i] == -1; i++);
                ;
            if (i <= 9)
            {
                p = i;
                node[posterior[j]].next = anterior[i];
            } /* fin del if */
            j = i;
        } /* fin del while */
        node[posterior[p]].next = -1;
    } /* fin del for */

    /* Copiar de regreso al archivo original */
    for (i = 0; i < n; i++)
    {
            x[i] = node[first].info;
            first = node[first].next;
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

int main(void)
{

    int x[] = {987, 943, 854, 100, 123, 534, 578};
    int n = sizeof(x) / sizeof(x[0]);
    cout<<"Arreglo sin ordenar: \n";
    imprimirarreglo(x,n);
    radixsort (x, n);
    cout<<"Arreglo ordenado: \n";
    imprimirarreglo(x,n);

    return 0;
}
