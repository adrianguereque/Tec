#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int> &v, int pos1, int pos2){
    int temp = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = temp;
}

void display(const vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

void exchangeSort(vector<int> &v, int &comps, int &swaps){
    int n = v.size();
    comps = swaps = 0;
    for(int i = 0; i<n-1;i++){
        for(int j = i+1;j<n;j++){
            comps++;
            if(v[j]<v[i]){
                swaps++;
                swap(v,i,j);
            }
        }
    }
}

void bubbleSort(vector<int> &v, int &comps, int &swaps){
    int n = v.size();
    comps = swaps = 0;
    bool ordered = false;
    for(int j=n-1;j>0 && !ordered;j--){
        ordered = true;
        for(int i=0;i<j;i++){
            comps++;
            if(v[i+1]<v[i]){
                swaps++;
                ordered = false;
                swap(v,i,i+1);
            }
        }
    }
}

void selectionSort(vector<int> &v, int &comps, int &swaps){
    int n = v.size();
    comps = swaps = 0;
    for(int i = 0;i<n-1;i++){
        int menor = i;
        for(int j=i+1; j<n; j++){
            comps++;
            if(v[j]<v[menor]){
                menor = j;
            }
        }
        if(i!=menor){
            swaps++;
            swap(v,i,menor);
        }
    }
}

void InsertionSort(vector<int> &v, int &comps, int &swaps){
    int n = v.size();
    comps = swaps = 0;
    for(int j=1;j<n;j++){
        int val = v[j]; // elemento a comparar
        int i = j - 1; // elemento con el que se compara
        while(i>=0){
            comps++;
            if(val<v[i]){
                swaps++;
                v[i+1] = v[i];
                i--;
            }
            else break;
        }
        v[i+1] = val;
    }
}
//implemente recursivamente el merge sort
void MergeAux(vector<int> &v, int start, int end){
    if(end-start+1>1){
        int middle = (start+end)/2;
        MergeAux(v,start,middle);
        MergeAux(v,middle+1,end);
        merge(v,start,middle,end);
    }
}

//mezcla dos segmentos de vector ordenados
void merge(vector<int> &v, int start, int middle, int end){
    int n = end - start + 1;
    vector<int> ordered(n);
    int i = start, j = middle+1, k=0;
    while(i<=middle && j<=end){
        if(v[j]<v[i]){
            ordered[k] = v[j];
            j++;
        }
        else{
            ordered[k]=v[i];
            i++;
        }
        k++;
    } 
    // copia elementos restantes del segmento que no se acabo 
    if(i<=middle){
        while(i<=middle){
            ordered[k] = v[i];
            i++;
            k++;
        }
    }
    else{
        while(j<=end){
            ordered[k] = v[j];
            j++;
            k++;
        }
    }
    //regresar elementos ordenados al vector
    for(int w=0;w<n;w++){
        v[start+w] = ordered[w];
    }
}
//parte el vector a la mitad 
void MergeSort(vector<int> &v, int &calls, int &comps, int &swaps){
    int n = v.size();
    calls = comps = swaps = 0;

}

int main(){
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

    cout<<endl<<"Desordenado: "<<endl;
    display(disordered);
    cout<<endl<<endl;

    int comps, swaps;
    vector<int> ordered;

    ordered = disordered;
    cout<<"Intercambio: "<<endl;
    exchangeSort(ordered, comps, swaps);
    display(ordered);
    cout<<"Comparaciones: "<<comps<<", swaps: "<<swaps<<endl<<endl;

    ordered = disordered;
    cout<<"Bubble: "<<endl;
    bubbleSort(ordered, comps, swaps);
    display(ordered);
    cout<<"Comparaciones: "<<comps<<", swaps: "<<swaps<<endl<<endl;

    ordered = disordered;
    cout<<"Selection: "<<endl;
    selectionSort(ordered, comps, swaps);
    display(ordered);
    cout<<"Comparaciones: "<<comps<<", swaps: "<<swaps<<endl<<endl;

    ordered = disordered;
    cout<<"Insertion: "<<endl;
    InsertionSort(ordered, comps, swaps);
    display(ordered);
    cout<<"Comparaciones: "<<comps<<", swaps: "<<swaps<<endl<<endl;

    ordered = disordered;
    cout<<"Merge: "<<endl;
    int calls;
    MergeSort(ordered, calls, comps, swaps);
    display(ordered);
    cout<<"Comparaciones: "<<comps<<", swaps: "<<swaps<<endl<<endl;

    return 0;
}