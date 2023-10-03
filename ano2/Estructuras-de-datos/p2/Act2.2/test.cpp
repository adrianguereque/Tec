#include <iostream>
using namespace std;
#include "LinkedList.h"
int main(){
    LinkedList<string> list1;
    list1.addFirst("Hola");
    list1.addLast("Me");
    list1.addLast("llamo");
    list1.addLast("Adrian");
    list1.print(); // Hola Me llamo Adrian

    LinkedList<string> list2;
    list2.addFirst("Adios"); 
    list2.print(); // Adios

    list1+=list2;
    list1.print(); // Hola Me llamo Adrian Adios

    LinkedList<string> list3;
    list3.addFirst("Diego");
    list3.print(); // Diego
    list3 = list2;
    list3.print(); // Adios

    LinkedList<string> list4(list3);
    list4.addLast("Pato");
    list4.print(); // Adios Pato
}