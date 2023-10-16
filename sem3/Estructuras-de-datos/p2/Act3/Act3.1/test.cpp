// Aplicación de prueba de los métodos de la actividad 3.1
#include <iostream>

using namespace std;

#include "BST-1.h"

int main(){
    BST miArbol;

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
    miArbol.print(preorder);
    miArbol.print(inorder);
    miArbol.print(postorder);
    miArbol.print(levelbylevel);

    miArbol.ancestors(4);
    cout<<miArbol.whatLevelAmI(9);

}