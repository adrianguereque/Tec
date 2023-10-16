// Aplicación de prueba para la clase BST
#include <iostream>

using namespace std;

#include "BST.h"

int main()
{
    BST miArbol;

    cout << "El arbol tiene: " << miArbol.getSize() << " nodos" << endl; // 0 nodos
    miArbol.add(8);
    miArbol.add(15);
    miArbol.add(21);
    miArbol.add(40);
    miArbol.add(7);
    miArbol.add(18);
    miArbol.add(9);
    miArbol.add(5);
    miArbol.add(2);
    miArbol.add(1);
    miArbol.add(4);
    miArbol.add(11);
    miArbol.add(6);
    miArbol.print();    // Recorrido: 8 7 5 2 1 4 6 15 9 11 21 18 40
    cout << "El arbol tiene: " << miArbol.getSize() << " nodos" << endl; // 13 nodos
    miArbol.remove(18);
    miArbol.print();    // Recorrido: 8 7 5 2 1 4 6 15 9 11 21 40
    cout << "El arbol tiene: " << miArbol.getSize() << " nodos" << endl; // 12 nodos
    miArbol.remove(7);
    miArbol.print(); // Recorrido: 8 5 2 1 4 6 15 9 11 21 40
    cout << "El arbol tiene: " << miArbol.getSize() << " nodos" << endl; // 11 nodos
    miArbol.remove(8);
    miArbol.print(); // Recorrido: 6 5 2 1 4 15 9 11 21 40
    cout << "El arbol tiene: " << miArbol.getSize() << " nodos" << endl; // 10 nodos

    return 0;
}