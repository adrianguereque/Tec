#ifndef NODET_H
#define NODET_H

class NodeT {
    public:
        NodeT(int data); // constructor
        int getData();
        NodeT *getLeft();
        NodeT *getRight();
        void setData(int data);
        void setLeft(NodeT *left);
        void setRight(NodeT *right);
    private:
        int data;
        NodeT *left, *right;
};

// constructor de nodos
NodeT::NodeT(int data) {
    this->data = data;
    left = right = nullptr;
}

// regresa el dato del nodo
int NodeT::getData() {
    return data;
}

// regresa el apuntador al subárbol izquerdo
NodeT *NodeT::getLeft() {
    return left;
}

// regresa el apuntador al subárbol derecho
NodeT *NodeT::getRight() {
    return right;
}

// modifica el dato del nodo
void NodeT::setData(int data) {
    this->data = data;
}

// modifica el apuntador al subárbol izquierdo
void NodeT::setLeft(NodeT *left) {
    this->left = left;
}

// modifica el apuntador al subárbol izquierdo
void NodeT::setRight(NodeT *right) {
    this->right = right;
}

#endif // NODET_H

