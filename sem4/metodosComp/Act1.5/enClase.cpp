#include <iostream>
using namespace std;


//                   a|x|y   _      0-9    delim
int m_Int[4][4] = {{1,      200,    200,    200},
                   {1,      2,      200,    200},
                   {200,    200,    3,      200},
                   {200,    200,    3,      100}};

int getCol(char c) {
    switch (c) {
        case 'a':
        case 'y':
        case 'x':
            return 0;  // a, y o x

        case '_':
            return 1;  // _

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return 2; // numeros

        default:
            return 3; // cualquier otra letra
    }
}

int main() {
    char cadena[100];
    cout << "Ingresa la cadena a evaluar: ";
    cin >> cadena;
    cout << cadena << endl;

    int i = 0;
    char aux; 
    int estado = 0; /* * * */
    int columna = 0;

    while (estado != 100 && estado != 200 && i < 100) {
        aux = cadena[i];
        cout << "cadena[" << i << "]:\t" << aux << endl;

        columna = getCol(aux);
        estado = m_Int[estado][columna];

        if (estado == 200) {	cout << "Error!!"<<endl;	break; }

        i++;
    }

    if (estado == 100)	{	cout << "Es una cadena valida"<<endl;	}

    return 0;
}
