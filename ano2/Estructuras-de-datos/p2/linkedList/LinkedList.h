#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

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

#endif // LINKEDLIST_H