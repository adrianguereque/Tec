#include <iostream>
using namespace std;
const float interes = 1.1875;
double inversionIter(double capital, int n){
    for(int mes=1;mes<=n;mes++){
        capital = capital*interes;
    }
    return capital;
}

double inversionRecu(double capital, int n){
    if(n==0){
        return capital;
    }
    else{
        return inversionRecu(capital*interes,n-1);
    }
}

int main(){
    int capital;
    int meses;
    cout<<"Capital a invertir"<<endl; 
    cin>>capital;
    cout<<"Numero de meses"<<endl;
    cin>>meses;


    cout<<"Monto final (iterativo) despues de "<<meses<<" meses = "<<inversionIter(capital,meses);
    cout<<"Monto final (recursivo) despues de "<<meses<<" meses = "<<inversionRecu(capital,meses);
    return 0;
}