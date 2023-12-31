#include "funWithGraphs.h"


//=============================================================================
// Exercise 2: Vertex degrees
//=============================================================================
// Subexercise 2.1: outDegree
//=============================================================================
//TODO
int FunWithGraphs::outDegree(const Graph<int> g, const int &v) {
    for(auto i : g.getVertexSet()){
        if(i->getInfo() == v){
            return i->getAdj().size();
        }
    }
    return -1;
}


//=============================================================================
// Subexercise 2.2: inDegree
//=============================================================================
//TODO
int FunWithGraphs::inDegree(const Graph<int> g, const int &v) {

    if(g.findVertex(v) == nullptr){
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

    if(g.findVertex(v) == nullptr){
        return -1;
    }

    int count = 0;

    for(auto i : g.getVertexSet()){
        for(auto j : i->getAdj()){
            count += j.getWeight();
        }
        return count;
    }
    return -1;
}
