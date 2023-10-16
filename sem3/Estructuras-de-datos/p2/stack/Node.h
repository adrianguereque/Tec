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

// Construye un nodo que apunta a nada
template <class T>
Node<T>::Node(T data) {
    this->data = data;
    next = nullptr; // NULL = apunta a nada
}

// Construye un nodo que apunta a otro nodo
template <class T>
Node<T>::Node(T data, Node<T> *next)
{
    this->data = data;
    this->next = next;
}

// Obtiene la información de un nodo
template <class T>
T Node<T>::getData() {
    return data;
}

// Obtiene el apuntador al siguiente de un nodo
template <class T>
Node<T> *Node<T>::getNext() {
    return next;
}

// Modifica la información de un nodo
template <class T>
void Node<T>::setData(T data) {
    this->data = data;
}

// Modifica el apuntador al siguiente de un nodo
template <class T>
void Node<T>::setNext(Node<T> *next)
{
    this->next = next;
}

#endif // NODE_H