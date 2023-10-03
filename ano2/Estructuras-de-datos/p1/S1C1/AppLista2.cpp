#include <iostream>

using namespace std;

#include "ListaTemplate.h"

int main(){
	Lista<int> miLista1;
	miLista1.insert(154);
	miLista1.insert(587);
	miLista1.insert(874);
	cout << "La lista1 tiene: " << miLista1.getSize() << " elementos" << endl;
	miLista1.insert(1000);
	miLista1.insert(9999);
	cout << "La lista tiene: " << miLista1.getSize() << " elementos"<<endl;
	cout << "Voy a borrar el último elemento y fue: " ;
	miLista1.erase();
	int cant = miLista1.getSize();
	miLista1.print();
	cout << endl;
	for (int i=0; i<cant; i++){
		miLista1.erase();
	}
	Lista<string> miLista2;
	miLista2.insert("HOLA");
	miLista2.insert("CRAYOLA");
	miLista2.insert("COMO");
	miLista2.print();
	cout << "La lista2 tiene: " << miLista2.getSize() << " elementos" << endl;
	cout << "Voy a borrar el último elemento y fue: " ;
	miLista2.erase();
	cant = miLista2.getSize();
	miLista2.print();
	cout << endl;
	for (int i=0; i<cant; i++){
		miLista2.erase();
	}
	return 0;
}