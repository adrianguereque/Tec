#ifndef STACK
#define STACK

#include "Node.h"
template <class T>
class Stack{
    public:
        Stack();
        ~Stack();
        bool empty( );
        int size() const;
        T top() const;
        void push(T data);
        void pop();
        
        bool isFull( );   
    private:
        Node<T> *_top;
        int _size;
};

template <class T>
Stack<T>::Stack(){

}
template <class T>
Stack<T>::~Stack(){
    
}
template <class T>
bool Stack<T>::empty(){
    
}
template <class T>
int Stack<T>::size(){
    
}
template <class T>
T Stack<T>::top(){
    
}
template <class T>
Stack<T>::Stack(){
    
}



#endif