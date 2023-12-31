// AED 2022/2023 - CI2 - Teste Pratico
// Pedro Ribeiro (DCC/FCUP) [last update: 04/01/2023]
#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    // show node order
    // cout << v << " ";
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

// Breadth-First Search: example implementation
void Graph::bfs(int v) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        // show node order
        //cout << u << " ";
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

// ----------------------------------------------------------
// Exercise 1
// ----------------------------------------------------------
// TODO
bool Graph::disconnected(int u, int v) {
    for(auto i : nodes[u].adj){
        if(i.dest == v){
            return false;
        }
    }
    return true;
}

// ----------------------------------------------------------
// Exercise 2
// ----------------------------------------------------------
// TODO
vector<int> Graph::largestDegree() {
    vector<int> ans;
    //1) Definimos o maior grau
    int result = 0;
    for(auto i = nodes.begin(); i != nodes.end(); i++){
        if(i->adj.size() >= result){
            result = i->adj.size();
        }
    }

    //2) adicionamos os grafos com maior grau
    int contador = 0;
    for(auto i = nodes.begin(); i != nodes.end(); i++){
        if(i->adj.size() == result){
            ans.push_back(contador);
        }
        contador++;
    }

    return ans;
}

// ----------------------------------------------------------
// Exercise 3
// ----------------------------------------------------------
// TODO
bool Graph::connected() {
        for (int i = 1; i <= n; i++) {
            nodes[i].visited = false;
        }

        dfs(1); //aqui, todos os nós apartir de 1 devem de ser vistados. Caso, não sejam...

        //retorna falso
        for (int i = 1; i <= n; i++) {
            if (!nodes[i].visited) {
                return false;
            }
        }
        return true;
}

// ----------------------------------------------------------
// Exercise 4
// ----------------------------------------------------------
// TODO
int Graph::countNodes(int v, int k) {

    for(int i = 1; i <= n; i++){
        nodes[i].visited = false;
    }

    queue<int> q; // queue of unvisited nodes
    q.push(v); //o node v já foi visitado
    nodes[v].visited = true; //por isso passa a true
    vector<int> dist(n, -1);  //este vetor mantem a dsitnacia de cada no. como ainda não foi identifcada começa a -1
    dist[v] = 0;   //a distância do nó 'v' até ele mesmo é 0
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        // show node order
        //cout << u << " ";
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                dist[w] = dist[u] + 1;
            }
        }
    }

    int count = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] == k){
            count++;
        }
    }

    //for(int i = 0; i <= dist.size(); i++){
    //    cout << dist[i] << ' ';
    //}
    return count;
}

// ----------------------------------------------------------
// Exercise 5
// ----------------------------------------------------------
// TODO
bool Graph::pathExists(int u, int v, const vector<int> & avoid) {
    for (int i = 1; i <= n; i++) {
        nodes[i].visited = false;
    }

    for(auto i : avoid){
        if(i == u || i == v){
            return false;
        }
        nodes[i].visited = true;
    }

    dfs(u);

    return nodes[v].visited;
}