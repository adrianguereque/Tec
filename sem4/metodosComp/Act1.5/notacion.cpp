#include <iostream>
using namespace std;

//                  0-9   .    e|E   -   delim
int m_Int[7][5] =  {{1,  200, 200,  200, 200},
                    {200,2,   200,  200, 200},
                    {3,  200, 200,  200, 200},
                    {3,  200, 4,    200, 200},
                    {6,  200, 200,  5,   200},
                    {6,  200, 200,  200, 200},
                    {6,  200, 200,  200, 100}};

int getCol(char c) {
    switch (c) {
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
            return 0;  // numeros
        case '.':
            return 1; // punto decimal
        case 'e':
        case 'E':
            return 2; // e o E para notacion
        case '-':
            return 3; // negativos
        case ' ':
		case '\0':  return 4;   //	delimitadores: espacio o fin de cadena

		default:	return 5;	//	columna "otro"
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

    if (estado == 100)	{	cout << "Es un numero de notacion cientifica valido"<<endl;	}

    return 0;
}
