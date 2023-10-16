#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


// intercambia dos elementos en un vector
// toma como argumento un vector pair para que se sortee por fecha
// con toda la linea
void swap(vector<pair<long long, string>> &v, int pos1, int pos2) {
    pair<long long,string> temp = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = temp;
}

// despliega los elementos de un vector en un renglón
// despliega primero el valor numerico de cada dia con mes, y luego la linea
// que le corresponde
void display(const vector<pair<long long,string>> &v) {
    for (int i = 0; i < v.size(); i++) 
        cout << " Line: " << v[i].second << endl;
}

// divide el segmento del vector a ordenar en 2 particiones a partir de un pivote
// lo mismo pero con un vector pair, solamente especificar el .first para que agarre
// como argumento el int (la fecha numerica) y no el string
int split(vector<pair<long long,string>> &v, int start, int end, int &comps, int &swaps) {
    long long pivot = v[start].first;
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
void quickAux(vector<pair<long long,string>> &v, int start, int end, int &calls, int &comps, int &swaps)
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
void quickSort(vector<pair<long long,string>> &v, int &calls, int &comps, int &swaps){
    int n = v.size();
    calls = comps = swaps = 0;
    quickAux(v, 0, n - 1, calls, comps, swaps);
}


// ...............................................................


string extractIPAddress(const string& line) {
    string ip;
    int spaceCount = 0;
    
    for (char c : line) { //checa por espacios en cada caracter de la linea
        if (c == ' ') {
            spaceCount++; //si hay un espacio, se suma el contador de espacios
            if (spaceCount > 3) // el tres es el numero de espacios hasta el ip
                break;
        } 
        else if (spaceCount == 3) //cuando sea tres la cantidad de espacios,
            ip.push_back(c);    //extrae los caracteres, hasta que se tope con otro
                                //espacio y pare el loop con el break, extrayendo
    }                           //los carcteres del ip

    return ip;
}

long long parseIp(string ip){ // le agrega ceros antes de los puntos si no tiene
    string new_ip = "";         // para que todas las ip tengan la misma longitud
    int start = 0, pos;
    for(pos = 0;pos<ip.length();pos++){ 
        if(ip[pos] != '.' && ip[pos] != ':') continue;
        string part = ip.substr(start,pos-start);
        int precision = 3 - part.length();
        new_ip += string(precision, '0').append(part);
        start = pos+1;
    }
    pos++;
    string part = ip.substr(start,pos-start);
    int precision = 4 - part.length();
    new_ip += string(precision, '0').append(part);

    return stoll(new_ip);
}

int main() {
    ifstream inputFile("bitacora.txt");

    string line;
    vector<pair<long long, string>> linesWithIPAddress; 
    // un vector pair para guardar la linea entera con su ip int correspondiente,
    // para cuando se ordene por los enteros, despliegue el string correspondiente

    // agarra cada linea del file .txt
    while (getline(inputFile, line)) {
        string ipAddress = extractIPAddress(line);  // Extrae el ip

        linesWithIPAddress.push_back({parseIp(ipAddress), line}); 
        // guarda cada ip con su linea en un vector. Esto es para poder asignar cada linea
        // con su fecha, y al ordenar la fecha, se estara ordenando con su linea
    }
    inputFile.close();

    int comps, swaps, calls;
    quickSort(linesWithIPAddress, calls, comps, swaps);
    // display(ordered); 
    cout << endl                
         << "Llamadas recursivas: " << calls
         << "  Comparaciones: " << comps
         << "  Intercambios: " << swaps << endl;

    string startIP, endIP;
    cout<< "Formato de IP: ###.###.###.###:####"<<endl;
    cout << "Ingrese la IP de inicio de búsqueda: ";
    cin >> startIP;
    cout<< "Formato de IP: ###.###.###.###:####"<<endl;
    cout << "Ingrese la IP de fin de búsqueda: ";
    cin >> endIP;
    long long StartIPNum, EndIPNum;
    StartIPNum = parseIp(startIP);
    EndIPNum = parseIp(endIP);
    ofstream outputFile("output.txt");
    for (const auto& line : linesWithIPAddress) {
        if(line.first>StartIPNum && line.first <EndIPNum)
            outputFile << line.second << endl;
    }

    outputFile.close();
    return 0;
}
