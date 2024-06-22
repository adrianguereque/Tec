// Aplicación para encontrar el bot master de un botnet
#include <iostream>
#include <iomanip> //
#include <vector>
#include <unordered_map>
#include <queue> // priority queue tambien de aqui
#include <string>

using namespace std;

struct Adjacents {
    int adjacents; // contador de adyacentes
    string dirIp; 

    // constructor
    Adjacents(int nadj=0, string ip="") {
        // TO DO
    }

    // sobrecarga el operador de ordenamiento <
    // compara dos estructuras para ver cual tiene mas adjacencias
    bool operator<(const Adjacents &adj) const
    {
        // TO DO
    }
};

// lee las direcciones de ip y crea el mapa de ips a nodos
// Complejidad: O()
void readIPs(int n, unordered_map<string, int> &ipMap, string ip)
{
    // TO DO
}

// lee las incidencias y crea el grafo como una lista de adyacencias
// Complejidad: O()
void createGraph(int m, unordered_map<string, int> &ipMap, vector<vector<string>> &grafo) 
{
    // TO DO
}

// despliega una Lista de Adyacencias
// Complejidad: O()
void printAdjList(vector<vector<int>> const &adjLst) {
    int n = adjLst.size();
    int m;
    cout << "Lista de Adyacencias" << endl;
    for (int source = 0; source < n; source++)
    {
        cout << source << ":";
        m = adjLst[source].size();
        for (int target = 0; target < m; target++) {
            cout << " " << adjLst[source][target];
        }
        cout << endl;
    }
}

// crea un heap usando la cantidad de adyacentes a un grafo como prioridad
// Complejidad: O()
void createHeap(const vector<vector<string>> &graph, priority_queue<Adjacents> &heap)
{
    // TO DO
}

// despliega los candidatos a bot master.
// Complejidad: O()
void botMaster(priority_queue<Adjacents> &heap) 
{
    // TO DO
}

// despliega las n direcciones Ip con mayores fan-out
void maxFanOut(priority_queue<Adjacents> &heap, int n) 
{
    // TO DO
}

int main()
{
    int n, m; // cantidad de nodos (13370) y arcos (91910)
    string dummy;

    cin >> n >> m;
    getline(cin, dummy);

    // ip con su numero de nodo
    unordered_map<string, int> map; // mapa de IDs a posiciones en el grafo
    // para saber que numero de nodo es dado la ip
    // <"36.29.138.97",0>

    vector<vector<string>> graph(n); // grafo de IPs
    priority_queue<Adjacents> heap;

    string line;
    readIPs(n, map, line); // leer todos los nodos y crear el mapa

    // crear grafo de origen a destino
    createGraph(m, map, graph);
    //printAdjList(graph);
    createHeap(graph, heap);
    botMaster(heap);
    maxFanOut(heap, 10);

    return 0;
}