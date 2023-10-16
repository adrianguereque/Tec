#include <iostream>
using namespace std;
const int MAX = 100;

class Lista {
    public: // interfaz de la clase
        Lista(); // constructor
        void insert(int valor);
        void erase();
        int getData(int pos);
        int getSize();
        void print();
    private:
        int data[MAX];
        int size;
};

Lista::Lista() {
    size = 0;
}

void Lista::insert(int valor) {
    if (size < MAX) 
        data[size++] = valor;
}

void Lista::erase() {
    if (size > 0) {
        size--;
        cout << "[" << size << "] - " << data[size] << endl;
    }
    else 
        cout << "NO HAY ELEMENTOS" << endl;
}

int Lista::getData(int pos) {
    return data[pos];
}

int Lista::getSize() {
    return size;
}

void Lista::print() {
    for (int i = 0; i < size; i++) 
        cout << "[" << i << "] - " << data[i] << endl;
}