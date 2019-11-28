#include <iostream>

using namespace std;

// Mezcla dos subvectores de vec
// siendo el primero vec[primero...central]
// y el segundo vec[central+1...ultimo]
void mezclar(int vec[], int primero, int central, int ultimo) {

    int i, j, k;
    int n1 = central - primero + 1;
    int n2 = ultimo - central;

    // Crea vectores temporales izq y der
    int izq[n1], der[n2];

    // Copia datos a los vectores temporales
    for (i = 0; i < n1; i++)
        izq[i] = vec[primero + i];
    for (j = 0; j < n2; j++)
        der[j] = vec[central + 1 + j];

    i = 0;
    j = 0;
    k = primero;

    //Junta los vectores temporales en vec[primero...ultimo]
    while (i < n1 && j < n2) {
        if (izq[i] <= der[j]) {
            vec[k] = izq[i];
            i++;
        }
        else {
            vec[k] = der[j];
            j++;
        }
        k++;
    }

    // Copia, de existir, los elementos restantes de izq
    while (i < n1) {
        vec[k] = izq[i];
        i++;
        k++;
    }

    // Copia, de existir, los elementos restantes de der
    while (j < n2) {
        vec[k] = der[j];
        j++;
        k++;
    }
}

// Ordena el subvector de vec delimitado a la izquierda por
// primero y a la derecha por ultimo
void mergesort(int vec[], int primero, int ultimo) {

    if (primero < ultimo) {
        int central = primero + (ultimo - primero) / 2;

        // Ordena las dos mitades
        mergesort(vec, primero, central);
        mergesort(vec, central + 1, ultimo);

        // Junta las mitades ordenadas
        mezclar(vec, primero, central, ultimo);
    }
}

void imprimir_vector(int vec[], int n) {
    for (int i=0; i < n; i++)
        cout << vec[i] << " ";
    cout << "\n";
}

int main() {

    int vec[] = {5, 12, 3, 1, 26, 7, 18};
    int n = sizeof(vec)/sizeof(vec[0]);

    cout << "Vector sin ordenar:" << endl;
    imprimir_vector(vec, n);

    mergesort(vec, 0, n - 1);

    cout << "\nVector ordenado:" << endl;
    imprimir_vector(vec, n);

    return 0;
}
