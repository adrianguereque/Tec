#include <iostream>
#include <fstream>
using namespace std;

int sumaIterativa(int n){ // O(n)
    int suma=0;
    for(int i=1;i<=n;i++){
        suma = suma + i;
    }
    return suma;
}
int sumaRecursiva(int n){ // O(n)
    if(n==0){
        return n;
    }
    else{
        return n + sumaRecursiva(n-1);
    }
}

int sumaDirecta(int n) { // O(1)
    return (n * (n + 1)) / 2;
}

void sumatoria(int n){
    cout<<"La suma iterativa de 1 hasta "<<n<<" es "<<sumaIterativa(n)<<endl;
    cout<<"La suma recursiva de 1 hasta "<<n<<" es "<<sumaRecursiva(n)<<endl;
    cout<<"La suma directa de 1 hasta "<<n<<" es "<<sumaDirecta(n)<<endl;
}
int main() {
    ifstream inputFile("./Act1.1_casos/1.in"); //abre el archivo .in
    
    if (!inputFile.is_open()) { //namas checa si existe
        cerr << "Could not open the input file." << endl;
        return 1;
    }
    
    string line;
    while (getline(inputFile, line)) {// agarra cada linea del archivo .in hasta que ya 
        sumatoria(stoi(line));        // no haya lineas, y el stoi convierte la linea de
    }                                 // string a int. (no me funcionaba cambiarle el string
                                      // line a int line por alguna razon, algo del getline)
    inputFile.close(); //cierra el archivo 
    
    return 0;
}
