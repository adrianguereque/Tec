#ifndef BST_1_H
#define BST_1_H

#include "NodeT.h"

enum Traversal {
    preorder, inorder, postorder, levelbylevel
};

class BST {
    public:
        BST();
        ~BST();
        bool search(int data) const;
        void add(int data);
        void remove(int data);
        bool isEmpty() const;
        int getSize() const;
        // Actividad 3.1
        void print(Traversal t) const;
        int height() const;
        void ancestors(int data) const;
        int whatLevelAmI(int data) const;

    private:
        NodeT *root;
        int size;
        // funciones auxiliares
        void deleteBT(NodeT *node);
        int countChildren(NodeT *node) const;
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
    while (curr != nullptr && curr->getData() != data)
        curr = (data < curr->getData()) ? curr->getLeft() : curr->getRight();
    return curr != nullptr;
}

void BST::add(int data) {
    if (isEmpty())
        root = new NodeT(data);
    else {
        NodeT *parent = nullptr;
        NodeT *curr = root;
        do {
            // el dato ya existe
            if (data == curr->getData())
                return;
            parent = curr;
            curr = (data < curr->getData()) ? curr->getLeft() : curr->getRight();
        } while (curr != nullptr);
        if (data < parent->getData())
            parent->setLeft(new NodeT(data));
        else
            parent->setRight(new NodeT(data));
    }
    size++;
}

void BST::remove(int data) {
    NodeT *parent = nullptr;
    NodeT *toRemove = root;
    while (toRemove != nullptr && data != toRemove->getData()) {
        parent = toRemove;
        toRemove = (data < parent->getData()) ? parent->getLeft() : parent->getRight();
    }
    if (toRemove != nullptr) {
        int children = countChildren(toRemove);
        if (children == 0) { // caso 1: eliminar nodo hoja
            if (parent == nullptr)
                root = nullptr;
            else if (data < parent->getData())
                parent->setLeft(nullptr);
            else
                parent->setRight(nullptr);
            delete toRemove;
            size--;
        } else if (children == 1) { // caso 1: eliminar nodo con un hijo
            NodeT *child = (toRemove->getLeft() != nullptr) ? toRemove->getLeft() : 
                                                              toRemove->getRight();
            if (parent == nullptr)
                root = child;
            else if (data < parent->getData())
                parent->setLeft(child);
            else
                parent->setRight(child);
            delete toRemove;
            size--;
        } else { // caso 3: eliminar nodo con dos hijos mediante el predecesor
            NodeT *predecessor = toRemove->getLeft();
            while (predecessor->getRight() != nullptr)
                predecessor = predecessor->getRight();
            int predData = predecessor->getData();
            remove(predData);
            toRemove->setData(predData);
        }
   }
}

bool BST::isEmpty() const {
    return size == 0;
}

int BST::getSize() const {
    return size;
}

// Actividad 3.1

void BST::print(Traversal t) const {
    // TO DO
}

int BST::height() const {
    // TO DO
}

void BST::ancestors(int data) const {
    // TO DO
}

int BST::whatLevelAmI(int data) const {
    // TO DO
}

// FUNCIONES AUXILIARES

void BST::deleteBT(NodeT * node)
{
    if (node != nullptr)
    {
        deleteBT(node->getLeft());
        deleteBT(node->getRight());
        delete node;
    }
}

int BST::countChildren(NodeT * node) const
{
    int children = 0;
    children += (node->getLeft() == nullptr) ? 0 : 1;
    children += (node->getRight() == nullptr) ? 0 : 1;
    return children;
}

#endif // BST_1_H