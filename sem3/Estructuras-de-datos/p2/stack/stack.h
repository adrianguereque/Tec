#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <class T>
class stack {
    public:
        stack();
        ~stack();
        bool empty() const;
        int size() const;
        T top() const;
        void push(T data);
        void pop();
    private:
        Node<T> *_top;
        int _size;
};

template <class T>
stack<T>::stack() {
    _top = nullptr;
    _size = 0;
}

template <class T>
stack<T>::~stack() {
    while (! empty())
        pop();
}

template <class T>
bool stack<T>::empty() const {
    return _size == 0;
}

template <class T>
int stack<T>::size() const {
    return _size;
}

template <class T>
T stack<T>::top() const {
    return _top->getData();
}

template <class T>
void stack<T>::push(T data) {
    if (empty())
        _top = new Node<T>(data);
    else
        _top = new Node<T>(data, _top);
    _size++;
}

template <class T>
void stack<T>::pop() {
    if (! empty()) {
        Node<T> *toDelete = _top;
        _top = _top->getNext();
        _size--;
        delete toDelete;
    }
}

#endif // STACK_H