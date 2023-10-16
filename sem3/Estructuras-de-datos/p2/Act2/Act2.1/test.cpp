#include <iostream>
using namespace std;
#include "LinkedList.h"
int main(){
    LinkedList<string> list;
    list.addFirst("Hola");
    list.addLast("Me");
    list.addLast("llamo");
    list.addLast("Adrian");
    list.print();
    list.reverse();
    list.print();
    list.reverse();
    list.print();
    list.shiftNeg();
    list.print();
    list.shiftPos();
    list.print();
    list.shiftPos();
    list.print();
}