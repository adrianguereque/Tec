// Implementación de las funciones de ordenamiento (sorts)

#include <iostream>
#include <vector>

using namespace std;

// intercambia dos elementos en un vector
void swap(vector<int> &v, int pos1, int pos2) {
    int temp = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = temp;
}

// despliega los elementos de un vector en un renglón
void display(const vector<int> &v) {
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
}

// ordena un vector ascendentemente por el sort de intercambio
// Complejidad: mejor O(n^2) peor O(n^2) 
void exchangeSort(vector<int> &v, int &comps, int &swaps) {
    int n = v.size();
    comps = swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            comps++;
            if (v[j] < v[i]) {
                swaps++;
                swap(v, i, j);
            }
        }
    }
} 

// ordena un vector ascendentemente por el sort de burbuja
// Complejidad: mejor O(n) peor O(n^2)
void bubbleSort(vector<int> &v, int &comps, int &swaps) {
    int n = v.size(); 
    comps = swaps = 0;
    bool ordered = false;
    for (int j = n - 1; j > 0 && ! ordered; j--) {
        ordered = true;
        for (int i = 0; i < j; i++) {
            comps++;
            if (v[i+1] < v[i]) {
                swaps++;
                ordered = false;
                swap(v, i, i+1);
            }
        }
    }
}

// ordena un vector ascendentemente por el sort de selección directa
// Complejidad: mejor O(n^2) peor O(n^2) 
void selectionSort(vector<int> &v, int &comps, int &swaps) {
    int n = v.size();
    comps = swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            comps++;
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        if (i != menor) {
            swaps++;
            swap(v, i, menor);
        }
    }
}

// ordena un vector ascendentemente por el sort de inserción
// Complejidad: mejor O(n) peor O(n^2) 
void insertionSort(vector<int> &v, int &comps, int &swaps) {
    int n = v.size();
    comps = swaps = 0;
    for (int j = 1; j < n; j++) {
        int val = v[j];
        int i = j;
        for (; i > 0; i--) {
            comps++;
            if (v[i-1] <= val) break;
            swaps++;
            v[i] = v[i-1];
        }
        v[i] = val;
    }
}

// mezcla las dos mitades ordenadas
void merge(vector<int> &v, int start, int middle, int end, int &comps, int &swaps) {
    int n = end - start + 1;
    vector<int> ordered(n);
    int i = start, j = middle + 1, k = 0;
    while (i <= middle && j <= end) {
        comps++;
        if (v[j] < v[i]) {
            swaps++;
            ordered[k] = v[j];
            j++;
        }
        else {
            ordered[k] = v[i];
            i++;
        }
        k++;
    }
    if (i <= middle)
        while (i <= middle) {
            comps++;
            ordered[k] = v[i];
            i++;
            k++;
        }
    else
        while (j <= end) {
            comps++;
            ordered[k] = v[j];
            j++;
            k++;
        }
    for (int r = 0; r < n; r++) 
        v[start + r] = ordered[r];
}

// implementa recursivamente el sort por mezcla
void mergeAux(vector<int> &v, int start, int end, int &calls, int &comps, int &swaps) {
    calls++;
    if (end - start + 1 > 1) {
        int middle = (start + end) / 2;
        mergeAux(v, start, middle, calls, comps, swaps);
        mergeAux(v, middle + 1, end, calls, comps, swaps);
        merge(v, start, middle, end, comps, swaps);
    }
}

// ordena un vector ascendentemente por el sort por mezcla
// Complejidad: mejor O(n log n) peor O(n log n)
void mergeSort(vector<int> &v, int &calls, int &comps, int &swaps) {
    int n = v.size();
    calls = comps = swaps = 0;
    mergeAux(v, 0, n - 1, calls, comps, swaps);
}

// divide el segmento del vector a ordenar en 2 particiones a partir de un pivote
int split(vector<int> &v, int start, int end, int &comps, int &swaps) {
    int pivot = v[start];
    int j = start;
    for (int i = start + 1; i <= end; i++) {
        comps++;
        if (v[i] < pivot) {
            j++;
            if (i > j) {
                swaps++;
                swap(v, i, j);
            }
        }
    }
    if (j > start) {
        swaps++;
        swap(v, start, j);
    }
    return j;
}

// implementa recursivamente el sort rápido
void quickAux(vector<int> &v, int start, int end, int &calls, int &comps, int &swaps)
{
    calls++;
    if (end > start) {
        int pivot = split(v, start, end, comps, swaps);
        quickAux(v, start, pivot, calls, comps, swaps);
        quickAux(v, pivot + 1, end, calls, comps, swaps);
    }
}

// ordena un vector ascendentemente por el sort rápido
// Complejidad: mejor O(n log n) peor O(n^2)
void quickSort(vector<int> &v, int &calls, int &comps, int &swaps)
{
    int n = v.size();
    calls = comps = swaps = 0;
    quickAux(v, 0, n - 1, calls, comps, swaps);
}

int main() {
    int n; // cantidad de elementos
    // cout << "dame n? ";
    cin >> n;

    // leer los datos
    vector<int> disordered(n);
    for (int i = 0; i < n; i++) {
        // cout << "valor " << i+1 << "? ";
        cin >> disordered[i];
    }
    cout << "Desordenado: ";
    display(disordered);
    cout << endl;

    vector<int> ordered;
    int comps, swaps;

    cout << "Intercambio: ";
    ordered = disordered;
    exchangeSort(ordered, comps, swaps);
    display(ordered);
    cout << endl
            << "Comparaciones: " << comps << "  Intercambios: " << swaps << endl;

    cout << "Burbuja: ";
    ordered = disordered;
    bubbleSort(ordered, comps, swaps);
    display(ordered);
    cout << endl
            << "Comparaciones: " << comps << "  Intercambios: " << swaps << endl;

    cout << "Seleccion: ";
    ordered = disordered;
    selectionSort(ordered, comps, swaps);
    display(ordered);
    cout << endl
            << "Comparaciones: " << comps << "  Intercambios: " << swaps << endl;

    cout << "Insercion: ";
    ordered = disordered;
    insertionSort(ordered, comps, swaps);
    display(ordered);
    cout << endl
            << "Comparaciones: " << comps << "  Intercambios: " << swaps << endl;

    int calls;

    cout << "MergeSort: ";
    ordered = disordered;
    mergeSort(ordered, calls, comps, swaps);
    display(ordered);
    cout << endl
         << "Llamadas recursivas: " << calls
         << "  Comparaciones: " << comps
         << "  Intercambios: " << swaps << endl;

    cout << "QuickSort: ";
    ordered = disordered;
    quickSort(ordered, calls, comps, swaps);
    display(ordered);
    cout << endl
         << "Llamadas recursivas: " << calls
         << "  Comparaciones: " << comps
         << "  Intercambios: " << swaps << endl;

    return 0;
}