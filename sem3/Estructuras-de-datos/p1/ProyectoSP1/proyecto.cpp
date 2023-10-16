// Adrian Guereque a01722394
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map> // Para que los meses tengan un entero asignado
#include <vector>
using namespace std;

// intercambia dos elementos en un vector
// toma como argumento un vector pair para que se sortee por fecha
// con toda la linea
void swap(vector<pair<int, string>> &v, int pos1, int pos2) {
    pair<int,string> temp = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = temp;
}

// despliega los elementos de un vector en un renglón
// despliega primero el valor numerico de cada dia con mes, y luego la linea
// que le corresponde
void display(const vector<pair<int,string>> &v) {
    for (int i = 0; i < v.size(); i++) 
        cout << " Line: " << v[i].second << endl;
}

// divide el segmento del vector a ordenar en 2 particiones a partir de un pivote
// lo mismo pero con un vector pair, solamente especificar el .first para que agarre
// como argumento el int (la fecha numerica) y no el string
int split(vector<pair<int,string>> &v, int start, int end, int &comps, int &swaps) {
    int pivot = v[start].first;
    int j = start;
    for (int i = start + 1; i <= end; i++) {
        comps++;
        if (v[i].first < pivot) {
            j++;
            if (i > j) {
                swaps++;
                swap(v, i, j);
            }
        }
    }
    if (j > start) {
        swaps++;
        swap(v, start, j);
    }
    return j;
}

// implementa recursivamente el sort rápido
// solamente cambia el vector pair como argumento
void quickAux(vector<pair<int,string>> &v, int start, int end, int &calls, int &comps, int &swaps)
{
    calls++;
    if (end > start) {
        int pivot = split(v, start, end, comps, swaps);
        quickAux(v, start, pivot, calls, comps, swaps);
        quickAux(v, pivot + 1, end, calls, comps, swaps);
    }
}


// ordena un vector ascendentemente por el sort rápido
// Complejidad: mejor O(n log n) peor O(n^2)
// solamente cambia el vector pair como argumento
void quickSort(vector<pair<int,string>> &v, int &calls, int &comps, int &swaps){
    int n = v.size();
    calls = comps = swaps = 0;
    quickAux(v, 0, n - 1, calls, comps, swaps);
}

int main() {
    ifstream inputFile("bitacora.txt");

    // Crear una tabla para poder otorgarle el valor entero a las abreviaciones
    // de los meses
    unordered_map<string, int> monthAbbreviations = {
        {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6},
        {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
    };

    string line;
    vector<pair<int, string>> linesWithNumericDates; 
    // un vector pair para guardar la linea entera con su fecha int correspondiente,
    // para cuando se ordene por los enteros, despliegue el string correspondiente

    // agarra cada linea del file .txt
    while (getline(inputFile, line)) {
        size_t pos = 0; 
        // Es la posicion de donde vamos a iniciar a extraer informacion
        // en la linea (como la fecha esta al principio, es 0)

        string dateInfo = line.substr(pos, 15); 
        // (pos, 15) = inicio de position y numero de characters despues.
        // de 0 a 14 de cada linea, saca los characters

        string monthAbbrev = dateInfo.substr(0, 3);
        //lo mismo pero de 0 a 2 para el mes

        string dayAbbreb = dateInfo.substr(4, 2); 
        // lo mismo pero de 4 a 5 para el dia

        int day = stoi(dayAbbreb.erase(dayAbbreb.find_last_not_of(" \t\n\r\f\v") + 1));
        // primero checa si hay un espacio (" "), si si, lo borra, y luego es
        // convertido a un entero

        int n = 7;
        if(day<10){ //si el dia es menor a 10, significa que tiene un caracter menos
            n--;    // el string, y por ende se le resta uno a la posicion 
        }           
        
        int hour = stoi(dateInfo.substr(n,2));
        // lo mismo de 7 a 8 para la hora 

        int min = stoi(dateInfo.substr(n+3,2));
        // lo mismo de 10 a 11 para los minutos 

        int sec = stoi(dateInfo.substr(n+6,2));
        // lo mismo de 13 a 14 para los segundos 

        int month = monthAbbreviations[monthAbbrev];
        // convierte el string de los meses a su numero asignado con el unordered map

        int numericDate = month * 100000000 + day*1000000 + hour*10000 + min*100 + sec;
        // convierte la fecha a un numero para poder ordenarlo mas facilmente

        linesWithNumericDates.push_back({numericDate, line}); 
        // guarda cada fecha con su linea en un vector. Esto es para poder asignar cada linea
        // con su fecha, y al ordenar la fecha, se estara ordenando con su linea
    }
    inputFile.close();

    vector<pair<int, string>> ordered = linesWithNumericDates;
    // en realidad no es necesario, pero lo hago para que se vea similar a lo
    // utilizado en clase    
    int comps, swaps, calls;
    quickSort(ordered, calls, comps, swaps);
    // display(ordered); 
    cout << endl                
         << "Llamadas recursivas: " << calls
         << "  Comparaciones: " << comps
         << "  Intercambios: " << swaps << endl;
    int mes1, dia1, mes2, dia2;
    cout<<"Desde que a que fecha? (Dia y mes)"<<endl;
    cout<<"Desde Mes (1 a 12): ";
    cin>>mes1;
    cout<<"Dia: ";
    cin>>dia1;
    cout<<"Hasta Mes (1 a 12): ";
    cin>>mes2;
    cout<<"Dia: ";
    cin>>dia2;
    int fecha1, fecha2;
    fecha1 = mes1 * 100000000 + dia1*1000000;
    fecha2 = mes2 * 100000000 + dia2*1000000;

    vector<string> linesInRange;
    // crea vector para guardar las lineas que esten dentro del rango de fechas

    for (const pair<int, string> data : ordered) {
        int numericDate = data.first;
        if (numericDate >= fecha1 && numericDate <= fecha2) {
            linesInRange.push_back(data.second);
        }
    }
    // si la fecha es mas grande que fecha 1 y mas chico que fecha 2, se guarda el string
    // de la linea en linesInRange

    ofstream outputFile("ordered_bitacora_range.txt");
    //crea el archivo
    for (const string& line : linesInRange) {
        outputFile << line << endl;
    }   // se le mete cada linea que estaba dentro del rango al archivo
    outputFile.close();
    //se cierra el archivo de output 
    return 0;
}
