#ifndef BST_H
#define BST_H

#include "NodeT.h"
#include <iostream>
using namespace std;
class BST {
    public:
        BST(); // construye una lista vacía
        ~BST(); // destructor
        bool search(int data) const;
        void add(int data);
        void remove(int data);
        bool isEmpty() const;
        int getSize() const;
        void print();

        int countChildren(NodeT *ptr) const;
    private:
        NodeT *root;
        int size;
        // funciones auxiliares
        void deleteBT(NodeT *ptr);
        void printAll(NodeT *ptr);
};

BST::BST() {
    root = nullptr;
    size = 0;
}

BST::~BST() {
    deleteBT(root);
}

bool BST::search(int data) const {
    NodeT *curr = root;
    while(curr != nullptr){
        if(data == curr->getData()) return true;
        curr = (data < curr->getData()) ? curr->getLeft() : curr->getRight();
        // o
        // if (data <curr->getData())
        //    curr = curr->getLeft();
        // else 
        //    curr = curr->getRight();
    }
    return false;
}

void BST::add(int data) {
    if(isEmpty()){
        root = new NodeT(data);
    }
    else{
        NodeT *parent = nullptr;
        NodeT *curr = root;
        while(curr!=nullptr){
            if(data == curr->getData())
                return;
            parent = curr;
            if(data < curr->getData()){
                curr = curr->getLeft();
            }
            else{
                curr = curr->getRight();
            }
        }
        if(data<parent->getData())
            parent->setLeft(new NodeT(data));
        else{
            parent->setRight(new NodeT(data));
        }
    }
    size++;
}

int BST::countChildren(NodeT *node) const{
    int children = 0;
    children += (node->getLeft() == nullptr) ? 0 : 1;
    children += (node->getRight() == nullptr) ? 0 : 1;
    return children;
}

void BST::remove(int data) {
    NodeT *parent = nullptr;
    NodeT *toRemove = root;
    while(toRemove != nullptr && data != toRemove->getData()){
        parent = toRemove;
        toRemove = (data < toRemove->getData()) ? toRemove->getLeft() : toRemove->getRight();
    }
    if (toRemove != nullptr){ //si encontro un nodo con el dato
        switch(countChildren(toRemove)){
            case 0:
                if(parent == nullptr)
                    root = nullptr;
                else if (data < parent->getData())
                    parent->setLeft(nullptr);
                else 
                    parent->setRight(nullptr);
                delete toRemove;
                size--;
                break;
            case 1:
                NodeT *child = (toRemove->getLeft() != nullptr) ? toRemove->getLeft() : toRemove->getRight();
                if(parent == nullptr)
                    root = child;
                else if(data < parent->getData())
                    parent->setLeft(child);
                else parent->setRight(child);
                delete toRemove;
                size--;
                break;
            default:
                // Falta
        }
    }

    
}

bool BST::isEmpty() const {
    return size == 0;
}

int BST::getSize() const {
    return size;
}

void BST::print() {
    printAll(root);
}

// FUNCIONES AUXILIARES

void BST::deleteBT(NodeT *ptr) {
    if(root != nullptr){
        deleteBT(ptr->getLeft());
        deleteBT(ptr->getRight());
        delete ptr;
    }
}
void BST::printAll(NodeT *ptr) {
    if(ptr != nullptr){
        printAll(ptr->getLeft());
        cout<<ptr->getData()<<endl;
        printAll(ptr->getRight());
    }
}

#endif // BST_H