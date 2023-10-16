#ifndef NODE_H
#define NODE_H

template <class T>

class Node {
    public: 
        Node(T data);
        Node(T data, Node<T> *next);
        T getData();
        Node<T> *getNext();
        void setData(T data);
        void setNext(Node<T> *next);

    private: 
        T data;
        Node<T> *next;
};

//constructor
template <class T>
Node<T>::Node(T data) {
    this->data = data;
    next = nullptr;
}

//constructor de nodos
template <class T>
Node<T>::Node(T data, Node<T> *next) {
    this->data = data;
    this->next = next;
}

//regresa el dato del nodo
template <class T>
T Node<T>::getData() {
    return data;
}

//regresa el apuntador al siguiente del nodo
template <class T>
Node<T> *Node<T>::getNext() {
    return next;
}

//modifica el dato del nnodo
template <class T>
void Node<T>::setData(T data) {
    this->data = data;
}

//modifica el siguiente nodo
template <class T>
void Node<T>::setNext(Node<T> *next) {
    this->next=next;
}

#endif // NODE_H