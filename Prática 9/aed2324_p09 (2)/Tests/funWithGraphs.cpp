#include "funWithGraphs.h"


//=============================================================================
// Exercise 2: Vertex degrees
//=============================================================================
// Subexercise 2.1: outDegree
//=============================================================================
//TODO
int FunWithGraphs::outDegree(const Graph<int> g, const int &v) {
    Vertex<int> *vertice = g.findVertex(v);
    if(vertice != nullptr){
        return vertice->getAdj().size();
    }
    return -1;
}


//=============================================================================
// Subexercise 2.2: inDegree
//=============================================================================
//TODO
int FunWithGraphs::inDegree(const Graph<int> g, const int &v) {

    Vertex<int> *vertice = g.findVertex(v);

    if(vertice == nullptr){
        return -1;
    }

    int count = 0;
    for(auto i : g.getVertexSet()){
        for(auto j : i->getAdj()){
            if(j.getDest()->getInfo() == v){
                count++;
            }
        }
    }
    return count;
}

//=============================================================================
// Subexercise 2.3: weightedOutDegree
//=============================================================================
// TODO
int FunWithGraphs::weightedOutDegree(const Graph<int> g, const int &v) {
    Vertex<int> *vertice = g.findVertex(v);

    int count = 0;
    if(vertice != nullptr){
        for(auto i : vertice->getAdj()){
            count += i.getWeight();
        }
        return count;
    }
    return -1;
}
