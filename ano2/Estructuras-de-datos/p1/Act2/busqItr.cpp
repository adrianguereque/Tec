// busca secuencialmente un valor dentro de una lista generada aleatoriamente
// si no lo encuentra regresa -1
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;
#include "Lista.h"

// Búsqueda secuencial de un valor en un vector de enteros
// Complejidad: O(n) mejor O(1)
int busqSec(Lista<int> &lista, int valor) {
    {
        for (int i = 0; i < lista.getSize(); i++)
        {
            cout << "pos: " << i << endl;
            if (valor == lista.getData(i))
            {
                return i;
            }
        }
        return -1;
    }
}

// Búsqueda binaria de un valor en un vector de enteros
// Complejidad: O(log n)
int busqBin(vector<int> &vec, int valor) {
    int medio, izq = 0, der = vec.size() - 1;

    while (izq <= der)
    {
        medio = (izq + der) / 2;
        cout << "izq: " << izq << " med: " << medio << " der: " << der << endl;
        if (valor == vec[medio])
            return medio;
        else if (valor < vec[medio])
            der = medio - 1;
        else
            izq = medio + 1;
        }
    return -1;
}

int main() {
    int n, valor, pos;
    Lista<int> lista;

    cout << "Cantidad de enteros? ";
    cin >> n;

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        lista.insert(rand() % (2*n) + 1);
    }
    lista.print();

    cout << "Valor a buscar? ";
    cin >> valor;
    cout << "BUSQUEDA SECUENCIAL" << endl;
    if ((pos = busqSec(lista, valor)) == -1)
        cout << "Valor no encontrado" << endl;
    else
        cout << "Valor encontrado en posicion " << pos << endl;
 
    cout << "BUSQUEDA BINARIA" << endl;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        vec[i] = lista.getData(i);
    sort(vec.begin(), vec.end());
    cout << "Lista ordenada: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << endl;
    if ((pos = busqBin(vec, valor)) == -1)
        cout << "Valor no encontrado" << endl;
    else
        cout << "Valor encontrado en posicion " << pos << endl;

    return 0;
}