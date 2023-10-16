// Aplicación de prueba de los métodos de la actividad 3.1
#include <iostream>
#include "NodeT.h"
#include <queue>
#include <stack>
#include "BST-1.h"

using namespace std;

/*int BST::nearestRelative(int data1, int data2) const{
    if(search(data1)!=true || search(data2)!=true){
        return -1;
    }
    cout<<"Primer queue"<<endl;
    NodeT *curr = root;
    queue<int> numsData1;
    queue<int> numsData2;
    numsData1.push(curr->getData());
    cout<<curr->getData()<<" ";
    while(curr->getData()!=data1){
        if(data1>curr->getData())
            curr=curr->getRight();
        else
            curr=curr->getLeft();
        if(curr->getData()!=data1)
            numsData1.push(curr->getData());
            cout<<curr->getData()<<" ";
    }

    cout<<endl<<endl;
    cout<<"Segundo queue"<<endl;
    curr = root;
    numsData2.push(curr->getData());
    cout<<curr->getData()<<" ";
    while(curr->getData()!=data2){
        if(data2>curr->getData())
            curr=curr->getRight();
        else
            curr=curr->getLeft();
        if(curr->getData()!=data2)
            numsData2.push(curr->getData());
            cout<<curr->getData()<<" ";

    }
    
    /*for(int i=0;i<numsData2.size();i++){
        cout<<numsData2.front()<<" ";
        numsData2.pop();
    }
    cout<<endl;

    cout<<endl<<endl;
    cout<<"Comparacion de queues"<<endl;
    int common = 0;
    while(numsData1.front() == numsData2.front()){
        common = numsData1.front();
        cout<< numsData1.front()<<" "<<numsData2.front()<<endl;
        numsData1.pop();
        numsData2.pop();
        if(numsData1.empty() && numsData2.empty()) break;
    }
    if(numsData1.front() == data1 || numsData1.front() == data2) common = numsData1.front();
    if(numsData2.front() == data1 || numsData2.front() == data2) common = numsData2.front();
    cout<<endl;
    cout<<"return"<<endl;
    return common;
}*/


int main(){
    BST miArbol;

    miArbol.add(8);
    miArbol.add(15);
    miArbol.add(21);
    miArbol.add(40);
    miArbol.add(7);
    miArbol.add(18);
    miArbol.add(9);
    miArbol.add(5);
    miArbol.add(2);
    miArbol.add(1);
    miArbol.add(4);
    miArbol.add(11);
    miArbol.add(6);
    /*miArbol.print(preorder);
    miArbol.print(inorder);
    miArbol.print(postorder);
    miArbol.print(levelbylevel);*/
    // miArbol.nearestRelative(11,6);
    cout<<miArbol.nearestRelative(18,40)<<endl;

 

}