// Adrian Guereque a01722394
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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

// Búsqueda secuencial de un valor en un vector de enteros
// Complejidad: O(n) mejor O(1)
int busqSec(vector<int> &v, int valor, int comps) { //valor = valor a buscar
    comps = 0;
    int n = v.size();
    for (int i = 0; i < n; i++){
        comps++;
        if (valor == v[i]){
            return i;
        }
    }
    return -1;
}

// Búsqueda binaria de un valor en un vector de enteros
// Complejidad: O(log n)
int busqBin(vector<int> &v, int valor, int comps) {
    comps = 0;
    int medio, izq = 0, der = v.size() - 1;

    while (izq <= der){
        comps++;
        medio = (izq + der) / 2;
        if (valor == v[medio])
            return medio;
        else if (valor < v[medio])
            der = medio - 1;
        else
            izq = medio + 1;
    }
    return -1;
}

int main() {
    ifstream MyFile("./Act1.2_casos/01.in"); //leer file
    string myText;
    vector<int> disordered;
    while (getline(MyFile, myText)) {
        stringstream ss(myText);
        int num;
        while (ss >> num) {
            disordered.push_back(num); //guardar numeros en vector
        }
    }
    MyFile.close();

    // cout << "Desordenado: ";
    // display(disordered);
    // cout << endl;

    vector<int> ordered;
    int comps, swaps;

    // cout << "Intercambio: ";
    ordered = disordered;
    exchangeSort(ordered, comps, swaps);
    // display(ordered);
    cout << comps<<" ";

    // cout << "Burbuja: ";
    ordered = disordered;
    bubbleSort(ordered, comps, swaps);
    // display(ordered);
    cout << comps << " ";

    int calls;

    // cout << "MergeSort: ";
    ordered = disordered;
    mergeSort(ordered, calls, comps, swaps);
    // display(ordered);
    cout << comps<<endl;

    cout<<"Cuantos valores quieres buscar?"<<endl;
    int a, valor;
    cin>>a;
    for(int i=0;i<a;i++){
        cout<<"Cual valor?"<<endl;
        cin>>valor;

        busqSec(ordered, valor, comps);
        cout<<valor<<" "<<comps<<" ";
        busqBin(ordered, valor, comps);
        cout<<valor<<" "<<comps<<endl;
    }

    return 0;
}