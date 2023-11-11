#ifndef BST_1_H
#define BST_1_H

#include "NodeT.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

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
        int height() const;
        void ancestors(int data) const;
        int whatLevelAmI(int data) const;
        // Actividad 3.2
        int maxWidth() const;
        int nearestRelative(int num1, int num2) const;
        // void BST(BST bst);

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
        int getHeight(NodeT *node) const;
        int getAncestors(NodeT *node) const;
        // Act 3.2
        int getMaxWidth(queue<NodeT *> node) const;

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
// ------------------------------------------------

// Act 3.2 ----------------------------------------

// ------------------------------------------------

int BST::getMaxWidth(queue<NodeT *> nodes) const{
    if (nodes.empty()) return 0;

    int maxWidth = nodes.size();  

    queue<NodeT*> nextLevelNodes;
    while (!nodes.empty()) {
        NodeT* node = nodes.front();
        nodes.pop();
        if (node->getLeft() != nullptr)
            nextLevelNodes.push(node->getLeft());
        if (node->getRight() != nullptr)
            nextLevelNodes.push(node->getRight());
    }
    int nextLevelWidth = getMaxWidth(nextLevelNodes); 

    return max(maxWidth, nextLevelWidth);
}   

int BST::maxWidth() const{
    queue<NodeT *> nodes; 
    nodes.push(root);
    return getMaxWidth(nodes);
}

int BST::nearestRelative(int data1, int data2) const{
    if(search(data1)!=true || search(data2)!=true){
        return -1;
    }
    NodeT *curr = root;
    queue<int> numsData1;
    queue<int> numsData2;
    numsData1.push(curr->getData());
    while(curr->getData()!=data1){
        if(data1>curr->getData())
            curr=curr->getRight();
        else
            curr=curr->getLeft();
        if(curr->getData()!=data1)
            numsData1.push(curr->getData());
    }

   
    curr = root;
    numsData2.push(curr->getData());
    while(curr->getData()!=data2){
        if(data2>curr->getData())
            curr=curr->getRight();
        else
            curr=curr->getLeft();
        if(curr->getData()!=data2)
            numsData2.push(curr->getData());

    }
    
    int common = 0;
    while(numsData1.front() == numsData2.front()){
        common = numsData1.front();
        numsData1.pop();
        numsData2.pop();
        if(numsData1.empty() && numsData2.empty()) break;
    }
    if(numsData1.front() == data1 || numsData1.front() == data2) common = numsData1.front();
    if(numsData2.front() == data1 || numsData2.front() == data2) common = numsData2.front();
    return common;
}



#endif // BST_1_H