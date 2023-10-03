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

int main(){
    int n; //cantidad de elementos
    cout<<"Dame n"<<endl;
    cin>>n;

    // leer los datos
    vector<int> disordered(n);
    for(int i=0;i<n;i++){
        cout<<"Valor "<<i+1<<"? ";
        cin>>disordered[i];
    }

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

    return 0;
}