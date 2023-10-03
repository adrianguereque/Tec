#include <iostream>

using namespace std;

#include "Lista.h"

int main(){
	Lista miLista;
	miLista.insert(154);
	miLista.insert(587);
	miLista.insert(874);
	cout << "La lista tiene: " << miLista.getSize() << " elementos"<<endl;
	miLista.insert(1000);
	miLista.insert(9999);
	cout << "La lista tiene: " << miLista.getSize() << " elementos"<<endl;
	cout << "Voy a borrar el último elemento y fue: " ;
	miLista.erase();
	int cant = miLista.getSize();
	miLista.print();
	for (int i=0; i<cant; i++){
		miLista.erase();
	}
	return 0;
}