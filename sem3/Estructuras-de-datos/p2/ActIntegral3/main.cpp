#include <iostream>
#include <vector>
#include "BST.h"
#include <fstream>
#include "priority_queue.h"
using namespace std;

string extractIPAddress(const string& line) {
    string ip;
    int spaceCount = 0;
    
    for (char c : line) { //checa por espacios en cada caracter de la linea
        if (c == ' ') {
            spaceCount++; //si hay un espacio, se suma el contador de espacios
            if (spaceCount > 3) // el tres es el numero de espacios hasta el ip
                break;
        } 
        else if (spaceCount == 3) //cuando sea tres la cantidad de espacios,
            ip.push_back(c);    //extrae los caracteres, hasta que se tope con otro
                                //espacio y pare el loop con el break, extrayendo
    }                           //los carcteres del ip

    return ip;
}

int extractFirstNumber(const string& ip) {
    string ip3;
    for (char c : ip) { // por cada character de la ip
        if (c == '.') // checa si el character es un punto
                break;
        else // y si no
            ip3.push_back(c);  // le agrega al string hasta que se tope con un punto
    }                          

    return stoi(ip3); // regresa un entero del string
}

int main(){
    vector<vector<string>> ipGroups(1000); // vector con vectores para guardar todos los numeros de ip
    vector<int> contadores(1000,0);
    BST arbol;

    ifstream inputFile("bitacora.txt");
    string line;
    while (getline(inputFile, line)) {
        string ipAddress = extractIPAddress(line);    // Extrae el ip
        int ipFirstNumber = extractFirstNumber(ipAddress); // Extrae los primeros 3 numeros
        contadores[ipFirstNumber]++;            // le suma al contador del arreglo de contadores
        if( contadores[ipFirstNumber] <= 1)     // si no se le habia sumado a su contador antes
            arbol.add(ipFirstNumber);               // se agrega al BST
        ipGroups[ipFirstNumber].push_back(ipAddress); // y se agrega la ip a un arreglo que esta
    }                                                 // en la posicion igual a los primeros tres 
    inputFile.close();                                // numeros de su ip de otro arreglo

    priority_queue heap;

    // crea el heap
    for (int i = 0; i < contadores.size(); i++){
        if(contadores[i]!=0)
            heap.push(contadores[i],ipGroups[i]);
    }

    heap.displayTop3();
}