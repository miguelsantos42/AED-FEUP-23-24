// AED 2022/2023 - CI2 - Teste Pratico
// Pedro Ribeiro (DCC/FCUP) [last update: 04/01/2023]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
        bool avoid;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed
    vector<Node> nodes; // The list of nodes being represented

    void dfs(int v);    // An example implementation of dfs
    void bfs(int v);    // An example implementation of bfs

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1);

    // ----- Functions to implement in this test -----
    bool disconnected(int u, int v);
    vector<int> largestDegree();
    bool connected();
    int countNodes(int v, int k);
    bool pathExists(int u, int v, const vector<int> & avoid);
};

#endif
