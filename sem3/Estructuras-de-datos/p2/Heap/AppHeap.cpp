// probar el uso de Árboles HEAP
#include <iostream>

using namespace std;

#include "priority_queue.h"

// Despliega el contenido del heap x prioridad.
void print_heap(priority_queue heap) {
    // TO DO
}

// ordena un vector usando el heap sort
void heapSort(vector<int> &vec) {
    // TO DO
}

int main() {
    priority_queue heap;

    vector<int> vec = {1, 52, 90, 24, 67, 15, 6, 47, 23, 15, 52, 7};
    // crea el heap
    for (int i = 0; i < vec.size(); i++)
        heap.push(vec[i]);
    cout << "Cantidad de datos en Heap: " << heap.size() << endl; // Cantidad de datos en Heap: 12
    cout << "Datos en heap: " << heap << endl; // Datos en heap : -1 90 67 52 47 52 15 6 1 23 15 24 7 
    cout << "Datos x prioridad en Heap: ";
    print_heap(heap); // Datos x prioridad en Heap: 90 67 52 52 47 24 23 15 15 7 6 1
    priority_queue heap2 = vec;
    cout << "Nuevo heap: " << heap2 << endl; // Nuevo heap: -1 90 67 15 47 52 7 6 24 23 15 52 1
    cout << "Nuevo heap x prioridad: ";
    print_heap(heap2); // Nuevo heap: 90 67 52 52 47 24 23 15 15 7 6 1
    heapSort(vec);
    cout << "Vector ordenado: ";
    for (auto value: vec) { // Vector ordenado: 1 6 7 15 15 23 24 47 52 52 67 90
        cout << value << " ";
    }
    cout << endl;

    return 0;
}