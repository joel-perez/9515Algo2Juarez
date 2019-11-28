#include <iostream>

using namespace std;

// Convierte a heap un subarbol dado representado por vec.
// raiz es un indice en vec. n es el tamaño del vector/arbol
void convertir_a_heap(int vec[], int n, int raiz)
{
    int maximo = raiz;
    int izquierdo = 2*i + 1;
    int derecho = 2*i + 2;

    // Si el hijo izquierdo es mayor que la raiz
    if (izquierdo < n && vec[izquierdo] > vec[maximo])
        maximo = izquierdo;

    // Si el hijo derecho es mayor que el maximo actual
    if (derecho < n && vec[derecho] > vec[maximo])
        maximo = derecho;

    // Si la raiz ya no es el maximo
    if (maximo != raiz)
    {
        swap(vec[raiz], vec[maximo]);

        // Convierte a heap el nuevo subarbol recursivamente
        convertir_a_heap(vec, n, maximo);
    }
}

// Realiza el ordenamiento
void heapsort(int vec[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        convertir_a_heap(vec, n, i);

    // Extrae el elemento maximo en cada iteracion
    // y vuelve a convertir en heap al subarbol resultante 
    for (int i = n - 1; i >= 0; i--)
    {
        swap(vec[0], vec[i]);

        convertir_a_heap(vec, i, 0);
    }
}

// Imprime el vector
void imprimir_vector(int vec[], int n)
{
    for (int i=0; i<n; ++i)
        cout << vec[i] << " ";
    cout << "\n";
}

int main()
{
    int vec[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(vec)/sizeof(vec[0]);

    cout << "Arreglo sin ordenar:" << endl;
    imprimir_vector(vec, n);

    heapsort(vec, n);

    cout << "Arreglo ordenado:" << endl;
    imprimir_vector(vec, n);
}
