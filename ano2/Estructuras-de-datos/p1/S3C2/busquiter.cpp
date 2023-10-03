#include <iostream>
#include "Lista.h"
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
int busqSecuencial(Lista<int> lista, int clave){
    for(int pos=0;pos<lista.getSize();pos++){
        if(clave == lista.getData(pos))
            return pos;
    }
    return -1;
}

int busqBinaria(Lista<int> lista, int clave){
    return 0;
}

int main(){
    int n;
    cout<<"Dame un numero"<<endl;
    cin>>n;

    int clave, pos;
    cout<<"Clave a buscar?"<<endl;
    cin>>clave;
}