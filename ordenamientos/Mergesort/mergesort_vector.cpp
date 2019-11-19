void unir(int vec[], int p, int m, int u) {

    int i, j, k;
    int n1 = m - p + 1;
    int n2 = u - m;

    int izq[n1], der[n2];

    for (i = 0; i<n1; i++)
        izq[i] = vec[p + i];
    for (j = 0; j < n2; j++)
        der[j] = vec[m + 1 + j];

    i = 0;
    j = 0;
    k = p;

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

    while (i < n1) {
        vec[k] = izq[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = der[j];
        j++;
        k++;
    }
}

void mergeSort(int vec[], int p, int u) {

    if (p < u) {
        int m = p + (u - p) / 2;
        mergeSort(vec, p, m);
        mergeSort(vec, m + 1, u);
        unir(vec, p, m, u);
    }
}

int main () {

    int arreglo[] = {5, 12, 3, 0, 26, 7, 18}

    cout << "Vector sin ordenar:" << endl;
    for (int i = 0; i < 7; i++)
        cout << arreglo[i] << " ";
    cout << endl;

    mergeSort(arreglo, arreglo[0], arreglo[6])

    cout << "Vector ordenado:" << endl;
    for (int i = 0; i < 7; i++)
        cout << arreglo[i] << " ";
    cout << endl;

    return 0;
}
