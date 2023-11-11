// Eugenio Garza A00836687
// Adrian Guerreque A01722394

// Ultima modificaion: 5 Nov 2023
//representa grafos como matrices y listas de adyacencias

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//funcion que lea y crea un grafo
// O(nodes + arcs).
void loadGraph(int &nodes, int &arcs, vector<vector<bool>> &adjMatrix, vector<vector<int>> &adjList) {
    cout << "Nodos: ";
    cin >> nodes;
    cout << "Arcos: ";
    cin >> arcs;

    vector <bool> cols(nodes, false); // vector de falsos para cada nodo
    vector<int> adjs; //vector vacios de adyacentes

    
    for (int n = 0; n < nodes; n++) { //inicializa las estructuras de grafo
        adjMatrix.push_back(cols);
        adjList.push_back(adjs);
    }

    int origen, destino;
    for (int a = 0; a < arcs; a++) { // agrega la informacion de las adyacencias
        cout << "origen del arco " << a << ": ";
        cin >> origen;
        cout << "Destino del arco " << a << ": ";
        cin >> destino;

        adjMatrix[origen][destino] = adjMatrix[destino][origen] = true;
        adjList[origen].push_back(destino);
        adjList[destino].push_back(origen);
    }
}

//despliega una matriz de adyacencias
// O(nodes^2)
void dispAdjMatrix(const vector<vector<bool>> &adjMatrix) {
    int nodes = adjMatrix.size(); //cantidad de nodos del grafo

    cout << "MATRIZ DE ADJACENTES" << endl << endl;
    for (int n = 0; n < nodes; n++) {
        cout << "Nodo " << n << ": ";
        for (int c = 0; c < nodes; c++) {
            cout << (adjMatrix[n][c] ? "T " : "F ");
        }
        cout << endl;
    }

}

//despliega una matriz de adyacencias
// O(arcs)
void dispAdjList(const vector<vector<int>> &adjList) {
    int nodes = adjList.size(); //cantidad de nodos del grafo

    cout << "LISTA DE ADJACENTES" << endl << endl;
    for (int n = 0; n < nodes; n++) {
        cout << "Nodo " << n << ": ";
        for (int c = 0; c < adjList[n].size(); c++) {
            cout << " -> " << adjList[n][c];
        }
        cout << endl;
    }
}

// implementa busqueda primero en anchura (Breadth First Node) (utilizando Lista)
// O(nodes + arcs)
void BFS(const vector<vector<int>> &adjList, int start) {
    int nodes = adjList.size(); // pasamos matriz y cantidad de nodos
    vector<bool> processed(nodes, false); // creamos vector de booleanos para cada nodos y los inicamos en falso
    queue<int> waiting; //fila que guarda los identificadores de los nodos. int porq los nodos son enteros en este caso
    waiting.push(start); //metemos el nodo de inicio
    processed[start] = true; //una vez que entra a la fila ya lo considero como procesado

    cout << "BFS: ";
    while (! waiting.empty()) { //si esta procesado lo desecho. Si todavia no, lo proceso (mientras la fila no este vacia, voy a seguir iterando)
        int node = waiting.front(); //obtener el valor que esta al inicio de la fila
        waiting.pop(); // lo elimina de la fila
        cout << " " << node; 

        for (int n = 0; n < adjList[node].size(); n++) { //para que recorra toda la fila y los voy metiendo a la fila waiting 
            int neighbor = adjList[node][n];
            if (! processed[neighbor]) { // segundo parametro: si el nodo no esta procesado entonces despliegalo
                waiting.push(neighbor);
                processed[neighbor] = true;
            }
        }
    }
    cout << endl;
}

// implementa busqueda primero en profundidad (Depth First Node) (utilizando Lista)
// O(nodes + arcs)
void DFS(const vector<vector<int>> &adjList, int start) {
    int nodes = adjList.size();
    vector<bool> processed(nodes, false);
    stack<int> waiting;
    waiting.push(start);

    cout << "DFS: ";
    while (! waiting.empty()) {
        int node = waiting.top();
        waiting.pop();

        if (! processed[node]) {
            processed[node] = true;
            cout << " " << node;

            // Recorre los vecinos en orden inverso para mantener el orden correcto (opcional)
            for (int i = adjList[node].size() - 1; i >= 0; --i) {
                int neighbor = adjList[node][i];
                if (! processed[neighbor]) {
                    waiting.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}


int main()
{
    int nodes, arcs; //cantidad de nodos y arcos

    vector<vector<bool>> adjMatrix; //matriz de adyacencias
    vector<vector<int>> adjList; //lista de adyacencias

    loadGraph(nodes, arcs, adjMatrix, adjList);

    cout << "----------------" << endl;

    dispAdjMatrix(adjMatrix);

    cout << "----------------" << endl;

    dispAdjList(adjList);

    cout << "----------------" << endl;

    for (int n = 0; n < nodes; n++) {
        BFS(adjList,n);
    }

    cout << "----------------" << endl;

    //int startNode = 0;
    //DFS(adjList, startNode);
    for (int n = 0; n < nodes; n++) {
        DFS(adjList,n);
    }

    return 0;
}