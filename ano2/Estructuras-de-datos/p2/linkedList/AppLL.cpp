#include <iostream>

using namespace std;

#include "LinkedList.h"

int main() {
	cout << "Pruebas para lista encadenada" << endl;
	cout << "----------" << endl;
	LinkedList<string> lista;
	lista.addLast("HOLA");
	lista.addLast("CRAYOLA");
	lista.addFirst("AQUI");
	lista.addLast("ESTOY");
	lista.print(); // AQUI HOLA CRAYOLA ESTOY
	cout << "----------" << endl; 
	lista.add("MTY",1);
	lista.print(); // AQUI MTY HOLA CRAYOLA ESTOY
	cout << "----------" << endl; 
	lista.del(2);
	lista.print(); // AQUI MTY CRAYOLA ESTOY
	cout << "----------" << endl;
	cout << "Size = " << lista.getSize() << endl; // Size = 4
	cout << "----------" << endl; 
	lista.deleteFirst(); // MTY CRAYOLA ESTOY
	lista.print(); // MTY CRAYOLA ESTOY
	cout << "----------" << endl; 
	lista.addFirst("TC1031"); // TC1031 MTY CRAYOLA ESTOY
	lista.deleteLast(); // TC1031 MTY CRAYOLA 
	lista.print(); // TC1031 MTY CRAYOLA
	cout << "----------" << endl;
	lista.addLast("ESTRUCTURA"); // TC1031 MTY CRAYOLA ESTRUCTURA
	lista.addLast("DATOS"); // TC1031 MTY CRAYOLA ESTRUCTURA DATOS
	cout << "Dato en pos 2 es " << lista.get(2) << endl; // Dato en pos 2 es CRAYOLA
	cout << "----------" << endl;
	lista.set("LUNA", 2) ; // TC1031 MTY LUNA ESTRUCTURA DATOS
	cout << "Dato en pos 2 es " << lista.get(2)  << endl; // Dato en pos 2 es LUNA
	cout << "----------" << endl;
	lista.print(); // TC1031 MTY LUNA ESTRUCTURA DATOS
	cout << "----------" << endl; 
	lista.change(1,3);
	lista.print(); // TC1031 ESTRUCTURA LUNA MTY DATOS
	cout << "----------" << endl; 	
	lista.deleteAll();
	lista.print();
	lista.addFirst("UNO");
	lista.print();
	lista.addLast("DOS");
	lista.print(); // UNO DOS
	
	return 0;
}