#include <iostream>
#include <vector>
using namespace std;

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

void merge(vector<int> &v, int start, int middle, int end, int &comps, int &swaps){
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
                ordered[k] = v[i];
                i++;
                k++;
            }
    else
    while (j <= end) {
        ordered[k] = v[j];
        j++;
        k++;
    }
    for (int r = 0; r < n; r++)
        v[start + r] = ordered[r];
}

//dividir el vector en 2 particiones
int split(vector<int> &v, int start, int end, int comps, int swaps){
    int pivot = v[start];     // el valor del pivote
    int j = start;
    for(int i = start + 1; i <= end; i++){
        comps++;
        if(v[i]<pivot){
            j++;
            if(i>j){
                swaps++;
                swap(v, i, j);
            }
        }
    }
    if(start<j){
        swap(v,start,j);
        swaps++;
    }
    return j;
}

// implementa recursivamente el quicksort
void quickAux(vector<int> &v, int start, int end, int &calls, int &comps, int
&swaps) {
    calls++;
    if(end>start){
        int pivot = split(v, start, end, comps, swaps); //donde quedo el pivote
        quickAux(v, start, pivot-1, calls, comps, swaps);
        quickAux(v, pivot + 1, end, calls, comps, swaps);
    }
}

void quickSort(vector<int> &v, int &calls, int &comps, int &swaps) {
    int n = v.size();
    calls = comps = swaps = 0;
    quickAux(v, 0, n - 1, calls, comps, swaps);
}

int main() {
     // int n; //cantidad de elementos
    // cout<<"Dame n"<<endl;
    // cin>>n;

    // // leer los datos
    // vector<int> disordered(n);
    // for(int i=0;i<n;i++){
    //     cout<<"Valor "<<i+1<<"? ";
    //     cin>>disordered[i];
    // }
    vector<int> disordered = {10,4,10,12,20,15,54,18};
    cout << "Desordenado: ";
    display(disordered);
    cout << endl;
    vector<int> ordered;
    int comps, swaps, calls;
    cout << "Intercambio: ";
    ordered = disordered;
    quickSort(ordered, calls, comps, swaps);
    display(ordered);
    cout<<"Comparaciones: "<<comps<<", swaps: "<<swaps<<endl<<endl;

    return 0;
}
