// Version original por: Roman Martinez

using namespace std;
#include <iostream>

//Definimos la matriz de transiciones
//				   0-9 del  otro
int m_Int[2][3] = {{1, 200, 200},
				   {1, 100, 200}};

//	Funcion para sacar la columna de la matriz que corresponda al caracter
int getCol (char c)
{	switch (c)
	{	case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':	return 0;	//	numeros 0 a 9, columna 0

		case ' ':
		case '\0':  return 1;   //	delimitadores: espacio o fin de cadena

		default:	return 2;	//	columna "otro"
	}
}

int main( )
{	// 	Leemos la cadena que vamos a evaluar
	char cadena[100];
	cout << "Ingresa la cadena a evaluar: ";
	cin >> cadena;
	cout << cadena << endl;

	int i = 0;
	char aux;			//	aux sera cada caracter de la cadena
	int estado = 0; 	//	Comenzamos en estado 0
	int columna = 0;

	while (estado != 100 && estado != 200 && i < 100)
	{	aux = cadena[i];					//	procesaremos caracteres uno por uno
		cout << "cadena["<<i << "]:\t" << aux << endl;

		columna = getCol(aux);				//	obtenemos la columna que corresponde al caracter
		estado = m_Int[estado][columna]; 	//	dados estado (fila) y columna, sabemos la transicion
		
		if (estado == 200)	{	cout << "Error!!"<<endl;	break; }

		i++;
	}	
	//	Si al final termino en aceptacion, es valido
	if (estado == 100)	{	cout << "Es un entero valido"<<endl;	}

	return 0;
}

