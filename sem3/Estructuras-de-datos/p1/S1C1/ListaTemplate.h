#include <iostream>
using namespace std;

template <class T>
const int MAX = 100;

template <class T>
class Lista {
public:
    Lista();
    void insert(T d);
    void erase();
    T getData(int pos);
    int getSize();
    void print();

private:
    int size;
    T data[MAX];
};

template <class T>
Lista<T>::Lista() {
    size = 0;
}

template <class T>
void Lista<T>::insert(T d) {
    if (size < MAX) {
        data[size] = d;
        size++;
    }
}

template <class T>
void Lista<T>::erase() {
    if (size > 0) {
        size--;
        cout << data[size] << endl;
    } else {
        cout << "NO HAY ELEMENTOS" << endl;
    }
}

template <class T>
T Lista<T>::getData(int pos) {
    return data[pos];
}

template <class T>
int Lista<T>::getSize() {
    return size;
}

template <class T>
void Lista<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << i << "-" << data[i] << endl;
    }
}

int main() {
    Lista<int> myList;
    myList.insert(5);
    myList.insert(10);
    myList.print();
    return 0;
}
