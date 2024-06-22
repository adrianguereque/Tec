#include <iostream>
using namespace std;

//                  -   0-9 delim
int m_Int[3][3] = {{1,   2, 200},
                   {200, 2, 200},
                   {200, 2, 100}};

int getCol(char c) {
    switch (c) {
        case '-':
            return 0;  // negativo
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
            return 1;  // numeros

        case ' ':
		case '\0':  return 2;   //	delimitadores: espacio o fin de cadena

		default:	return 3;	//	columna "otro"
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

        if (estado == 200) {	cout << "Error!!"<<endl;	break; }

        i++;
    }

    if (estado == 100)	{	cout << "Es un entero valido"<<endl;	}

    return 0;
}
