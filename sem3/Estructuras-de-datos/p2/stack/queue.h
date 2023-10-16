#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <class T>
class queue {
    public:
        queue();
        ~queue();
        bool empty() const;
        int size() const;
        T front() const;
        void push(T data);
        void pop();
    private:
        Node<T> *_last;
        int _size;
};

template <class T>
queue<T>::queue() {
    _last = nullptr;
    _size = 0;
}

template <class T>
queue<T>::~queue() {
    while (! empty())
        pop();
}

template <class T>
bool queue<T>::empty() const {
    return _size == 0;
}

template <class T>
int queue<T>::size() const {
    return _size;
}

template <class T>
T queue<T>::front() const {
    return _last->getNext()->getData();
}

template <class T>
void queue<T>::push(T data) {
    if (empty()) {
        _last = new Node<T>(data);
        _last->setNext(_last);
    }
    else {
        Node<T> *oldLast = _last;
        _last = new Node<T>(data, _last->getNext());
        oldLast->setNext(_last);
    }
    _size++;
}

template <class T>
void queue<T>::pop() {
    if (! empty()) {
        Node<T> *toDelete = _last->getNext();
        if (size() == 1)
            _last = nullptr;
        else
            _last->setNext(toDelete->getNext());
        _size--;
        delete toDelete;
    }
}

#endif // QUEUE_H