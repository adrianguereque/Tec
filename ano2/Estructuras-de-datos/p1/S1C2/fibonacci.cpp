#include <iostream>
using namespace std;

int fibonacciIterativo(int n){
    int fibo[n];
    fibo[1,1];
    for(int i=2;i<=n;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    return fibo[n];
}

int fibonacciRecursivo(int n){
    if(n<3){
        return 1;
    }
    return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
}

int main(){
    int n;
    cout<<"Dame n"<<endl; 
    cin>>n;

    cout<<"Fibonacci Iterativo de "<<n<<" = "<<fibonacciIterativo(n)<<endl;
    cout<<"Fibonacci Recursivo de "<<n<<" = "<<fibonacciIterativo(n);
    return 0;
}