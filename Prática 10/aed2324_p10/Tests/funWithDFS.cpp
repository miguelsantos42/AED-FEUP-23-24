#include "funWithDFS.h"

//using namespace std;

//=============================================================================
// Exercise 2.1: Nodes at distance k
//=============================================================================
// Subexercise 2.1.1: Nodes at distance k (DFS)
//=============================================================================
// TODO
void nodesAtDistanceDFSVisit(const Graph<Person> *g, Vertex<Person> *v, int k, vector<Person> &res);

vector<Person> vertices;

vector<Person> FunWithDFS::nodesAtDistanceDFS(const Graph<Person> *g, const Person &source, int k) {
    vector<Person> res;

    vertices.clear();
    
    nodesAtDistanceDFSVisit(g, g->findVertex(source),k,res);

    return res;
}

bool find(Vertex<Person> *v, vector<Person> &res){
    for(auto i = res.begin(); i != res.end(); i++){
        if(i->getName() == v->getInfo().getName()){
            return true;
        }
    }
    return false;
}

// TODO
void nodesAtDistanceDFSVisit(const Graph<Person> *g, Vertex<Person> *v, int k, vector<Person> &res) {

    if(k < 0){
        return;
    }

    vertices.push_back(v->getInfo());

    if(k == 0){
        res.push_back(v->getInfo());
        return;
    }

    for(Edge<Person> i : v->getAdj()){
        if(!find(i.getDest(),vertices)){
            nodesAtDistanceDFSVisit(g, i.getDest(), k-1,res);
        }
    }
}

//=============================================================================
// Exercise 2.3: Directed Acyclic Graph
//=============================================================================
// TODO
bool dfsIsDAG(Vertex<int> *v);
bool FunWithDFS::isDAG(Graph<int> g) {
    return false;
}

// TODO
bool dfsIsDAG(Vertex<int> *v) {
    return false;
}
