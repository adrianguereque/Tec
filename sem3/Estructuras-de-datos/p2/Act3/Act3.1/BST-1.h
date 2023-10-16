#ifndef BST_1_H
#define BST_1_H
#include <queue>
#include <stack>
#include "NodeT.h"

enum Traversal { // basicamente solamente les da valor numerico 
    preorder, inorder, postorder, levelbylevel
};  // = 0      = 1       = 2         = 3

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
        // switch case que llama las funciones auxiliares para el caso
        int height() const;
        void ancestors(int data) const;
        // si no esta, regresa dato inexistente
        // si es el root, regresa no tiene ancestros
        // si si esta y no es el root, llama la funcion auxiliar
        int whatLevelAmI(int data) const;
        // si no esta, pues -1
        // si esta, pues solamente cuentas cuantas veces se mueve el apuntador
        // hasta llegar al nivel
    private:
        NodeT *root;
        int size;
        // funciones auxiliares
        void deleteBT(NodeT *node);
        int countChildren(NodeT *node) const;
        // Act3.1
        void preOrderPrint(NodeT *node) const;
        void inOrderPrint(NodeT *node) const;
        void postOrderPrint(NodeT *node) const;
        void LBLprint(queue<NodeT *> node) const;
        // metes el root al queue, metes sus hijos al queue
        // desplegas el root, le haces pop, metes los hijos del
        // nuevo front, lo desplegas, pop, metes los hijos del nuevo
        // front, lo desplegas, pop, etc, etc.
        int getHeight(NodeT *node) const;

        int getAncestors(NodeT *node) const;
        // empezando del root, guarda todos los valores en el camino al
        // valor dado en un stack, y cuando llegue al valor, desplegas
        // el stack
        // o puedes desplegar datos sin stack de ida al valor
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
void BST::preOrderPrint(NodeT *node) const{
    if (root == nullptr)
        return;

    stack<NodeT *> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        NodeT *node = nodeStack.top();
        nodeStack.pop();

        // Print the data of the current node
        cout << node->getData() << " ";

        // Push the right child first so that it is processed after the left child
        if (node->getRight() != nullptr)
            nodeStack.push(node->getRight());

        // Push the left child to be processed next
        if (node->getLeft() != nullptr)
            nodeStack.push(node->getLeft());
    }
    cout<<endl;

}
void BST::inOrderPrint(NodeT *node) const{
    if (node != nullptr) {
		inOrderPrint(node->getLeft());
		cout << node->getData() << " ";
		inOrderPrint(node->getRight());
	}
}   
void BST::postOrderPrint(NodeT *node) const{
    if (node != nullptr) {
		postOrderPrint(node->getLeft());
		postOrderPrint(node->getRight());
		cout << node->getData() << " ";
	}
}

void BST::LBLprint(queue<NodeT *> nodes) const{
    if(nodes.empty()) return;

    queue<NodeT *> nextLevelNodes;

    while(!nodes.empty()){
        NodeT *node = nodes.front();
        cout << node->getData() << " ";
        if(node->getLeft()!=nullptr)
            nodes.push(node->getLeft());
        
        if(node->getRight()!=nullptr)
            nodes.push(node->getRight());
        nodes.pop();
    }
    LBLprint(nextLevelNodes);
}

void BST::print(Traversal t) const {
    if(root==nullptr) return;
    switch(t){
        case preorder:
            preOrderPrint(root);
            // primero todos los subarboles izquierdos, luego los derechos
            break;
        case inorder:
            inOrderPrint(root);
            // en orden (menor a mayor)
            // desplegar siempre el subarbon izquierdo
            cout<<endl;
            break;
        case postorder:
            postOrderPrint(root);
            cout<<endl;
            break;
        case levelbylevel:
            queue<NodeT *> nodes;
            nodes.push(root);
            LBLprint(nodes);
            cout<<endl;
            break;
    }
}

int BST::getHeight(NodeT *node) const { //Obtiene la altura en la que se encuentra un numero determinado
    if (node == nullptr) {
        return 0;
    }
    
    int leftHeight = getHeight(node->getLeft());
    int rightHeight = getHeight(node->getRight());

    return std::max(leftHeight, rightHeight) + 1;
}

int BST::height() const{
    return getHeight(root);
}

void BST::ancestors(int data) const {
    if(search(data)!=true){
        cout<<"DATO INEXISTENTE"<<endl;
        return;
    }
    if(root->getData()==data){
        cout<<"SIN ANCESTROS"<<endl;
        return;
    }
    NodeT *curr = root;
    stack<int> nums;
    nums.push(curr->getData());
    while(curr->getData()!=data){
        if(data>curr->getData())
            curr=curr->getRight();
        else
            curr=curr->getLeft();
        if(curr->getData()!=data)
            nums.push(curr->getData());
    }
    while (!nums.empty()) {
        cout << nums.top() <<" ";
        nums.pop();
    }
    cout<<endl;
}

int BST::whatLevelAmI(int data) const {
    if(root!=nullptr && search(data) == true){
        NodeT *curr = root;
        int levels = 0;
        while(curr->getData()!=data){
            if(data>curr->getData()){
                curr=curr->getRight();
                levels++;
            }
            else if(data<curr->getData()){
                curr=curr->getLeft();
                levels++;
            }
        }
        return levels;
    }
    return -1;
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