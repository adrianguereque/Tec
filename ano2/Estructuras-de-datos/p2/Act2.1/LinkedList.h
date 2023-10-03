// Adrian Guereque a01722394
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <iostream>
using namespace std;
template <class T>
class LinkedList { 
    public:
        LinkedList(); // constructor
        ~LinkedList(); // destructor
        void addFirst(T data);
        void addLast(T data);
        bool add(T data, int pos);
        void deleteFirst();
        void deleteLast();
        void del(int pos);
        bool isEmpty() const;
        int deleteAll();
        T set(T data, int pos);
        T get(int pos) const;
        bool change(int pos1, int pos2);
        int getSize() const;
        void print() const;

        void reverse();
        void shiftPos();
        void shiftNeg();
        void shift(int num);

        bool operator == (const LinkedList& other) const;
    private:
        Node<T> *head;
        int size;
};

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    deleteAll();
}

template <class T>
void LinkedList<T>::addFirst(T data) {
    if (isEmpty()) 
        head = new Node<T>(data);
    else 
        head = new Node<T>(data, head);
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data) {
    if (isEmpty()) // la lista está vacía
        addFirst(data);
    else {
        Node<T> *curr = head;
        // moverse al último nodo
        while (curr->getNext() != nullptr) 
            curr = curr->getNext();
        curr->setNext(new Node<T>(data));
        size++;
    }
}

template <class T>
bool LinkedList<T>::add(T data, int pos) {
    // se asume una posición no negativa
    if (pos <= size) {
        if (pos == 0)
            addFirst(data);
        else {
            Node<T> *previous = head;
            for (int i = 1; i < pos; i++)
                previous = previous->getNext();
            previous->setNext(new Node<T>(data, previous->getNext()));
            size++;
        }
        return true;
    }
    return false;
}

template <class T>
void LinkedList<T>::deleteFirst() {
    if (! isEmpty()) {
        Node<T> *node = head;
        head = head->getNext();
        delete node;
        size--;
    }
}

template <class T>
void LinkedList<T>::deleteLast() {
    if (! isEmpty()) {
        if (size == 1)
            deleteFirst();
        else {
            Node<T> *curr = head;
            // buscar el penúltimo
            while(curr->getNext()->getNext() != nullptr) 
                curr = curr->getNext();
            delete curr->getNext();
            curr->setNext(nullptr);
            size--;
        }
    }
}

template <class T>
void LinkedList<T>::del(int pos) {
    // se asume una posición válida
    if (pos == 0)
        deleteFirst();
    else {
        Node<T> *previous = head;
        for (int i = 1; i < pos; i++)
            previous = previous->getNext();
        Node<T> *toDelete = previous->getNext();
        previous->setNext(toDelete->getNext());
        delete toDelete;
        size--;
    }
}

template <class T>
bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

template <class T>
int LinkedList<T>::deleteAll() {
    int deleted = size;
    while (! isEmpty())
        deleteFirst();
    return deleted;
}

template <class T>
T LinkedList<T>::set(T data, int pos) {
    // se asume una posición válida
    Node<T> * curr = head;
    for (int i = 0; i < pos; i++) 
        curr = curr->getNext();
    T previous = curr->getData();
    curr->setData(data);
    return previous;
}

template <class T>
T LinkedList<T>::get(int pos) const {
    // se asume una posición válida
    Node<T> * curr = head;
    for (int i = 0; i < pos; i++) 
        curr = curr->getNext();
    return curr->getData();
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2) {
    if (pos1 >= 0 && pos2 >= 0 && pos1 < size && pos2 < size) {
        Node<T> *curr1 = head;
        for (int i = 0; i < pos1; i++) 
            curr1 = curr1->getNext();
        Node<T> *curr2 = head;
        for (int i = 0; i < pos2; i++) 
            curr2 = curr2->getNext();
        T temp = curr1->getData();
        curr1->setData(curr2->getData());
        curr2->setData(temp);
        return true;
    }
    return false;
}

template <class T>
int LinkedList<T>::getSize() const {
    return size;
}

template <class T>
void LinkedList<T>::print() const {
    if (! isEmpty()) {
        cout << head->getData();
        Node<T> *curr = head->getNext();
        while (curr != nullptr) {
            cout << " " << curr->getData();
            curr = curr->getNext();
        }
    }
    cout << endl;
}

// ........... este metodo si es O(n^2) porque el change() es O(n)
// y este metodo tiene otro loop
template <class T>
void LinkedList<T>::reverse(){
    int middle = size / 2; // saca la mitad de los valores porque solamente
    int end = size - 1; // va a cambiar la mitad, y el end para poder usarlo
    if(size>1){ // en el loop y no cambiar el size en si de la lista
        for(int i=0;i<middle;i++){ //por la mitad de sus valores va a cambiar
            change(i,end); // el primero con el ultimo, segundo con penultimo, etc.
            end--;
        }
    }
}

template <class T>
void LinkedList<T>::shiftPos() {
    if (size <= 1) return;
    Node<T> *prev; 
    Node<T> *curr = head;
    while (curr->getNext() != nullptr) {
        prev = curr;
        curr = curr->getNext();
    }
    curr->setNext(head);
    head = curr;

    if (prev != nullptr)
        prev->setNext(nullptr);
}

// Es O(n) porque tiene un loop
template <class T>
void LinkedList<T>::shiftNeg(){
    if(size <= 1)return;
    Node<T> *curr = head;
    T last = curr->getData(); // para guardar el valor
    for(int i=0;i<size-1;i++){ // por cada uno de sus valores - 1
        curr->setData(curr->getNext()->getData()); // va a guardar el siguiente valor
        curr=curr->getNext();   // en el presente
    }
    this->set(last,size-1); // cambia el ultimo valor por el primero que se guardo
}

// Es O(n^2) ya que hay loop dentro de los shifts auxiliares y dentro de este
// shift
template <class T>
void LinkedList<T>::shift(int num){
    if(num > 0){
        for(int i = 0;i<num;i++)
            shiftPos();
    }
    else{
        for (int i = 0;i>num;i--){
            shiftNeg();
        }
    }
}

// Es O(n) ya que usa un loop
template <class T>
bool LinkedList<T>::operator==(const LinkedList& list1) const{
    if(list1.getSize() != size) return false; // si su tamanio no es igual, falso
    Node<T> *curr1 = head; // se guarda el valor de la lista que se compara
    Node<T> *curr2 = list1.head;// y de la otra
    for(int i = 0;i<size;i++){
        if(curr1->getData() != curr2->getData()) return false; // si el valor en la misma 
        curr1 = curr1->getNext();   // posicion no es igual, falso. Si no, continua
        curr2 = curr2->getNext(); // el loop con todas las posiciones
    }
    return true; // y si no regreso falso hasta el mero final, entonces es verdadero
}

#endif // LINKEDLIST_H