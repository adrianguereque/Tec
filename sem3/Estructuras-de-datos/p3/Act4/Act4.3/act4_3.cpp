//Maria Quetzalli Ramirez Martinez  A01753959
//Eugenio Garza Cabello			        A00836687
//Adrian Guereque				            A01722394
//Sebastián De Alejandro Villarreal	A01285448
//Equipo 7

// Aplicación para encontrar el bot master de un botnet
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Estructura para contar la cantidad de adyacentes a un nodo
struct Adjacents {
  int adjacents; // contador de adyacentes
  string dirIp;

  //El constructor
  Adjacents(int nadj = 0, string ip = "") : adjacents(nadj), dirIp(ip) {}

  //Sobrecarga el operador de ordenamiento
  bool operator<(const Adjacents &adj) const {
    return adjacents < adj.adjacents; // ordena de mayor a menor
  }
}; //Ultima modificación el 20 de noviembre de 2023

// Lee las direcciones de ip y crea el mapa de ips a nodos. Nos pide la variable de los nodos y arcos, la lista de la bitacora, el guarda los datos y el desordenado mapa de los ips.
// Complejidad: O(n)
void readIPs(int &n, int &m, ifstream &file, string &filename,
             unordered_map<string, int> &ipMap, vector<vector<string>> &graph) {
  file.open(filename);

  if (file.fail()) {
    cout << "Error al abrir el archivo"
         << endl; // si no se puede abrir el archivo, termina el programa
    exit(1);
  }

  file >> n >> m;
  string line;

  for (int i = 0; i < n; i++) {
    getline(file, line);
    if (i == 0 && line.empty()) {
      getline(file, line);
    }
    ipMap[line] = i;
    graph.push_back(vector<string>{line}); // Se agrega la IP al grafo
  }
}//Ultima modificacion el 20 de noviembre de 2023

// lee las incidencias y crea el grafo como una lista de adyacencias. Pide los arcos, el guardador de file, el desordenado mapa de ips, y el vector del grafo.
// Complejidad: O(n)
void createGraph(int m, ifstream &file,
                 unordered_map<string, int> &ipMap,
                 vector<vector<string>> &graph) {
  string line, ip, ip2, conexion;
  int index; // Indice de la IP en el grafo
  for (int i = 0; i < m; i++) {
    if (!getline(file, line))
      break;

    istringstream iss(line);

    if (!(iss >> conexion >> conexion >> conexion >> ip >> ip2))
      continue; // lee las ips
    ip = ip.substr(0, ip.length() - 5);
    ip2 = ip2.substr(0, ip2.length() - 5);

    index = ipMap[ip]; // Se obtiene el indice de la IP en el grafo
    graph[index].push_back(ip2);
  }
}//Ultima modificacion el 20 de noviembre de 2023

// crea un heap usando la cantidad de adyacentes a un grafo como prioridad. Nos pide el vector del grafo y el queue de los heaps.
// Complejidad: O(n)
void createHeap(const vector<vector<string>> &graph,
                priority_queue<Adjacents> &heap) {
  int n = graph.size();
  int fanOut;

  for (int i = 0; i < n; i++) {
    fanOut = graph[i].size() - 1;
    heap.push(Adjacents(fanOut, graph[i][0]));
  }
}//Ultima modificacion el 20 de noviembre de 2023

// despliega los candidatos a bot master (mayor fan-out, contando adyacencias). Nos pide el queue del heap.
// Complejidad: O(n)
void botMaster(priority_queue<Adjacents> &heap) {
  if (heap.empty())
    return;
  priority_queue<Adjacents> copyHeap = heap;
  int max = copyHeap.top().adjacents; // Fan-out maximo

  cout << "Candidatos a Bot Master (Fan-out = " << max << "):" << endl;

  while (!copyHeap.empty()) {
    if (copyHeap.top().adjacents == max) {
      cout << "dirIp: " << right << setw(15) << copyHeap.top().dirIp
           << endl; // Se imprime la IP
    }
    copyHeap.pop();
  }
}//Ultima modificación el 20 de noviembre de 2023

// despliega las n direcciones Ip con mayores fan-out, usando el heap priority. Nos pide el queue del heap y la variable de rest.
//Complejidad: O(n)
void maxFanOut(priority_queue<Adjacents> &heap, int rest) {
  if (heap.empty())
    return;
  int max = heap.top().adjacents; // Max fan-out
  int resta = rest;
  cout << "Las " << rest << " direcciones de Ip con mayor fan-out:" << endl;
  while (!heap.empty() && resta > 0) {
    Adjacents current = heap.top();
    heap.pop();

    if (current.adjacents < max) {
      cout << "DirIp: " << right << setw(15) << current.dirIp
           << " fan-out: " << current.adjacents << endl;
      resta--;
    } else if (current.adjacents == max) {
      rest--;
    }
  }
}//Ultima modificacion el 20 de noviembre de 2023
//-----------------------------------------------------------
//Este es el main, que ejecutara todo para esta actividad.
int main() {
  int vertices, arcos;
  string filename = "bitacoraACT4_3.txt";
  ifstream file;
  unordered_map<string, int> map;
  vector<vector<string>> graph;

  readIPs(vertices, arcos, file, filename, map, graph);
  createGraph(arcos, file, map, graph);

  priority_queue<Adjacents> heap;
  createHeap(graph, heap);
  botMaster(heap);
  maxFanOut(heap, 10);

  return 0;
}