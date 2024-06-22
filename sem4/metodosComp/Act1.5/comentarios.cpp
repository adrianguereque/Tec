#include <iostream>
using namespace std;
// LEER <<-------------------------------------
// No funciona /* */ con espacios, pero si sin espacios
// y no entieno por que (e.g. /*ssd*/ acepta pero no /*ssd */)
// Tambien cuando hay dos //, acepta pero termina cuando hay espacio
// (e.g. //hola soy a acepta pero solamente sale hola)
//                  /       *    any char   delim
int m_Int[6][4] = {{1,      200,    200,    200},
                   {5,      2,      200,    200},
                   {200,    3,      2,      200},
                   {4,      200,    2,      200},
                   {200,    200,    200,    100},
                   {200,    200,    5,      100}}; 

int getCol(char c) {
    switch (c) {
        case '/':
            return 0;  // 
        case '*':
            return 1;  // 
        case '\0':
            return 3;  // delimitador
        default:
            return 2;  // cualquier otro char
    }
}

int main() {
    char cadena[100];
    cout << "Ingresa la cadena a evaluar: ";
    cin >> cadena;
    cout << cadena << endl;

    int i = 0;
    char aux;
    int estado = 0;
    int columna = 0;

    while (estado != 100 && estado != 200 && i < 100) {
        aux = cadena[i];
        cout << "cadena[" << i << "]:\t" << aux << endl;

        columna = getCol(aux);
        estado = m_Int[estado][columna];

        if (estado == 200) {
            cout << "Error!!" << endl;
            break;
        }

        i++;
    }

    if (estado == 100) {
        cout << "Es una cadena valida" << endl;
    }

    return 0;
}
