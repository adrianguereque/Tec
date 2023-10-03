#include <iostream>
using namespace std;
const int MAX = 100;
class Lista{
    public:
        Lista();
        void insert(int d);
        void erase();
        int getData(int pos);
        int getSize();
        void print();

    private:
        int size;
        int data[MAX];
};
Lista::Lista(){
    size = 0;
}
void Lista::insert(int d){
    if(size<MAX){
        data[size] = d;
        size++;
    }
};
void Lista::erase(){
    if(size>0){
        size--;
        cout<<data[size]<<endl;
    }
    else{
        cout<<"NO HAY ELEMENTOS"<<endl;
    }
};
int Lista::getData(int pos){
    return data[pos];
};
int Lista::getSize(){
    return size;
};
void Lista::print(){
    for(int i=0;i>size;i++){
        cout<<i<<"-"<<data[i]<<endl;
    }
};
