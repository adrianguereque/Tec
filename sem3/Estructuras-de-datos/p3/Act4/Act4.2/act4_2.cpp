// Eugenio Garza Cabello A00836687
// Adrian Guerreque A01722394

// Ultima modificacion: 16 Nov 2023
// En este codigo se implementan las funciones loadGraph, isDAG, topologicalSort y bipartiteGraph
// se crea un grafo con n cantidad de nodos y m cantidad de arcos para la implementacion de las funciones
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// crea un frafo dirigido representado como una lista de adyacencias
// O(nodes + arcs)
void loadGraph(int n, int m, vector<vector<int>> &adjLst){
    // agrega un elemenro a la lista de adyacenicas por cada nodo
    vector<int> empty;
    for(int node = 0; node < n; node++){
        adjLst.push_back(empty);
    }
    int source, target;
    for(int arc = 0; arc < m; arc++){
        cout<< "Origen arco "<< arc << "? ";
        cin >> source;
        cout<< "Destino arco " << arc << "? ";
        cin >> target;
        adjLst[source].push_back(target);
    }
    cout<<endl;
}

// O(nodes + arcs)
void printAdjList(vector<vector<int>> &adjLst) {
    int nodes = adjLst.size();
    cout<< "Lista de Adyacencias"<<endl;
    for(int node = 0; node < nodes; node++){
        cout<<"Nodo "<<node;
        for(auto neighbor : adjLst[node])
            cout<<" -> " << neighbor;
        cout<<endl;
    }
}

// implementa un recorrido primero en profundiad de un grafo
// O(nodes + arcs)
void DFSaux(const vector<vector<int>> &adjLst, vector<bool> &processed, int node){
    cout<< " " << node;
    processed[node] = true;// se marca como procesado el nodo
    for(auto neighbor : adjLst[node])// procesamos todos los nodos vecinos
        if(! processed[neighbor])// si el vecino no esta procesado, se llama a DFS
            DFSaux(adjLst,processed,neighbor);
}

// O(nodes + arcs)
void DFS(const vector<vector<int>> &adjLst, int start){
        cout<< "DFS:";
        vector<bool> processed(adjLst.size(), false);
        DFSaux(adjLst,processed,start);
}

// O(nodes)
bool found_in_stack(int to_find, stack<int> stack) {
    while (!stack.empty()) {
        if (stack.top() == to_find) return true;
        stack.pop();
    }
    return false;
}

// O(nodes + arcs)
bool hasCycleNode(int node, vector<bool> &processed, stack<int> &stack, const vector<vector<int>> &adjLst){
    processed[node] = true;
    stack.push(node);
    for(auto neighbor : adjLst[node])
        if(!processed[neighbor])
            hasCycleNode(neighbor, processed, stack, adjLst);
        else if(found_in_stack(neighbor, stack)) return true;
    stack.pop();
    return false;
}

// determina si un grafo dirigido es acilico
// O(nodes + arcs)
bool isDAG(const vector<vector<int>> &adjLst){
    vector<bool> processed(adjLst.size(), false);
    stack<int> stackR;
    for(int node = 0; node < adjLst.size(); node++)
        if(hasCycleNode(node, processed, stackR, adjLst)) // si se cicla, no es DAG
            return false;
    return true;
}


// Agrega un parámetro para pasar stack para almacenar el orden topológico
// O(nodes + arcs)
void DFSauxTopo(const vector<vector<int>> &adjLst, vector<bool> &processed, int node, stack<int> &topoOrder) {
    processed[node] = true;
    for (auto neighbor : adjLst[node]) {
        if (!processed[neighbor]) {
            DFSauxTopo(adjLst, processed, neighbor, topoOrder);
        }
    }
    topoOrder.push(node); // mueve el nodo al stack
}

// crea orden topologico de un DAG
// O(nodes + arcs)
vector<int> topologicalSort(const vector<vector<int>> &adjLst) {
    vector<bool> processed(adjLst.size(), false);
    stack<int> topoOrder;  // otrden topologico

    for (int node = 0; node < adjLst.size(); ++node) {
        if (!processed[node]) {
            DFSauxTopo(adjLst, processed, node, topoOrder);
        }
    }

    // mueve los elementos del stack a un vector
    vector<int> result;
    while (!topoOrder.empty()) {
        result.push_back(topoOrder.top());
        topoOrder.pop();
    }

    return result;
}

// determina si un grafo dirigido es bipartito
// O(nodes + arcs)
bool bipartiteGraph(const vector<vector<int>> &adjLst) {
    int n = adjLst.size();
    vector<int> color(n, -1); // color = -1 (representa un nodo todavia no coloreado)

    queue<int> q;
    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) {
            q.push(start);
            color[start] = 0; // color = 0 al nodo incial

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto neighbor : adjLst[node]) {
                    if (color[neighbor] == -1) { // Si el vecino no tiene un color asignado, asignarle el color opuesto al del nodo actual
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node]) { // Si el vecino tiene el mismo color que el nodo actual, el grafo no es bipartito
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main(){
    int nodes, arcs;
    cout<<"nodos?";// cantidad de nodos
    cin>>nodes;
    cout<<"arcos?";// cantidad de arcos
    cin>>arcs;

    vector<vector<int>> adjList;
    loadGraph(nodes, arcs, adjList);
    printAdjList(adjList);
    cout<<endl;

    //despliega recorrido DFS desde cada nodo
    for(int start = 0; start < nodes ; start++){
        DFS(adjList, start);
        cout<<endl;
    }
    cout << endl;
   
    if(isDAG(adjList)) { 
        cout<<"El grafo es un DAG"<<endl<<endl;
        vector<int> tsort = topologicalSort(adjList);
        cout<<"Orden topologico: ";
        for(int i=0;i<tsort.size();i++)
            cout<<tsort[i]<<" ";
        cout<<endl;
    }
    else {
        cout<<"El grafo NO es un DAG"<<endl;
        cout<<endl<<"El grafo NO tiene orden topologico"<<endl;
    }
    if(bipartiteGraph(adjList)){
        cout<<endl<<"El grafo es bipartito"<<endl;
    }
    else {
        cout<<endl<<"El grafo NO es bipartito"<<endl<<endl;
    }
    return 0;
}