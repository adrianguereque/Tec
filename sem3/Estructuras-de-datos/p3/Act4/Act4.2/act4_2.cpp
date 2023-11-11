
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void loadGraph(int n, int m, vector<vector<int>> &adjLst){
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
}

void printAdjList(vector<vector<int>> &adjLst) {
    int nodes = adjLst.size();
    cout<< "Lista de adjecencias"<<endl;
    for(int node = 0; node < nodes; node++){
        cout<<"Nodo "<<node<<":";
        for(auto neighbor : adjLst[node])
            cout<<" -> " << neighbor;
        cout<<endl;
    }
}

void DFSaux(const vector<vector<int>> &adjLst, vector<bool> &processed, int node){
    cout<< " " << node;
    processed[node] = true;
    for(auto neighbor : adjLst[node])
        if(! processed[neighbor])
            DFSaux(adjLst,processed,neighbor);
}

void DFS(const vector<vector<int>> &adjLst, int start){
        cout<< "DFS: ";
        vector<bool> processed(adjLst.size(), false);
        DFSaux(adjLst,processed,start);
}

bool isDAG(const vector<vector<int>> &adjLst){
    vector<bool> processed(adjLst.size(), false);
    stack<int> stackR;
    for(int node = 0; node < adjLst.size(); node++)
        if(hasCycleNode(node, processed, stackR, adjLst)) // si se cicla, no es DAG
            return false;
    return true;
}



bool hasCycleNode(int node, vector<bool> processed, stack<int> stack, const vector<vector<int>> &adjLst){
    processed[node] = true;
    stack.push(node);
    for(auto neighbor : adjLst[node])
        if(! processed[neighbor])
            if(hasCycleNode(neighbor, processed, stack, adjLst))
                return true;
        //else if() //if neighbor in recursion stack
            return true;
    stack.pop();
    return false;
}

vector<int> topologicalSort(const vector<vector<int>> &adjLst){
    vector<int> result;
    //
    return result;
}

bool bipartiteGraph(const vector<vector<int>> &adjLst){
    //
    return true;
}

int main(){
    int nodes, arcs;
    cout<<"nodos?";
    cin>>nodes;
    cout<<"arcos?";
    cin>>arcs;

    vector<vector<int>> adjList;
    loadGraph(nodes, arcs, adjList);
    printAdjList(adjList);
    cout<<endl;

    for(int start = 0; start < nodes ; start++){
        DFS(adjList, start);
        cout<<endl;
    }
   

    if(isDAG(adjList)) { 
        cout<<"El grafo es un DAG"<<endl<<endl;
        vector<int> tsort = topologicalSort(adjList);
        cout<<"Orden topologico:"<<endl;
        for(int i=0;i<tsort.size();i++)
            cout<<tsort[i]<<" ";
        cout<<endl;
    }
    else cout<<"El grafo no es un DAG y por ende no tiene orden topologico"<<endl;

    if(bipartiteGraph(adjList))
        cout<<"Si es un grafo bipartito"<<endl;
    else cout<<"No es un grafo bipartito"<<endl;

    return 0;
}
