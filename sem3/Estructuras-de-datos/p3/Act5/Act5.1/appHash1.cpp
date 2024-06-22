// aplicación para probar el ADT unordered_set con función de hashing residual
// y hashing abierto lineal

#include <iostream>

using namespace std;

#include "unordered_set1.h"

int main() {
    int table_size;
    //cout << "Tamanio de la tabla? ";
    cin >> table_size;

    unordered_set set(table_size);
    int nvals, val;

    //cout << "Cantidad de valores a insertar? ";
    cin >> nvals;

    for (int i = 0; i < nvals; i++) {
        //cout << "valor a insertar " << i+1 << "? ";
        cin >> val;
        set.insert(val);
    }
    cout << "El conjunto tiene " << set.getSize() << " elementos" << endl;
    set.print();
    set.print_table();

    //cout << "Cantidad de valores a borrar? ";
    cin >> nvals;
    for (int i = 0; i < nvals; i++)
    {
        //cout << "valor a borrar " << i+1 << ": ";
        cin >> val;
        if (!set.isEmpty()) set.erase(val);
    }
    cout << "El conjunto tiene " << set.getSize() << " elementos" << endl;
    set.print();
    set.print_table();

    //cout << "Cantidad de valores a buscar? ";
    cin >> nvals;
    for (int i = 0; i < nvals; i++)
    {
        //cout << "valor a buscar " << i+1 << ": ";
        cin >> val;
        if (set.find(val))
            cout << "< Encontrado >" << endl;
        else
            cout << "< NO encontrado >" << endl;
    }

    return 0;
}