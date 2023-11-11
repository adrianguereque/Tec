// Representa grafos como matrices y listas de adyacencias.
#include <iostream>
#include <vector>

using namespace std;

// lea y cree un grafo
void loadGraph(int &nodes, int &arcs, 
               vector<vector<bool>> &adjMatrix, vector<vector<int>> &adjList) {
    //cout << "Nodos? ";
    cin >> nodes;
    //cout << "Arcos? ";
    cin >> arcs;

    vector<bool> cols(nodes, false); // vector de falsos para cada nodo
    vector<int> adjs;                // vector vacío de adyacentes

    // inicializa las estructuras de grafo
    for (int n = 0; n < nodes; n++) {
        adjMatrix.push_back(cols);
        adjList.push_back(adjs);
    }

    // agrega la información de las adyacencias
    int origen, destino;
    for (int a = 0; a < arcs; a++) {
        //cout << "Origen del arco " << a << ": ";
        cin >> origen;
        //cout << "Destino del arco " << a << ": ";
        cin >> destino;
        adjMatrix[origen][destino] = adjMatrix[destino][origen] = true;
        adjList[origen].push_back(destino);
        adjList[destino].push_back(origen);
    }
}

// despliega una matriz de adyacencias
void dispAdjMatrix(const vector<vector<bool>> &adjMatrix) {
    int nodes = adjMatrix.size(); // cantidad de nodos del grafo

    cout << "Matriz de Adyacencias" << endl;
    for (int n = 0; n < nodes; n++) {
        cout << "Nodo " << n << ": ";
        for (int c = 0 ; c < nodes; c++) {
            cout << (adjMatrix[n][c] ? "T " : "F ");
        }
        cout << endl;
    }
}

// despliega una lista de adyacencias
void dispAdjList(const vector<vector<int>> &adjList) {
    int nodes = adjList.size(); // cantidad de nodos del grafo

    cout << "Lista de Adyacencias" << endl;
    for (int n = 0; n < nodes; n++) {
        cout << "Nodo " << n;
        for (int c = 0 ; c < adjList[n].size(); c++) {
            cout << " -> " << adjList[n][c];
        }
        cout << endl;
    }
}

int main() {
    int nodes, arcs; // cantidad de nodos y arcos
    vector<vector<bool>> adjMatrix; // matriz de adyacencias
    vector<vector<int>> adjList;    // lista de adyacencias

    loadGraph(nodes, arcs, adjMatrix, adjList);

    dispAdjMatrix(adjMatrix);

    dispAdjList(adjList);

    return 0;
}
