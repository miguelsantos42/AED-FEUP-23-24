// ------------------------------------------------------------

#include <cstddef>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#include "Graph.h"
#include "GraphOps.h"

// ------------------------------------------------------------

bool verification(Vertex<int> *v){
    v->setVisited(true);
    v->setProcessing(true);
    for(auto& i : v->getAdj()){
        auto p = i.getDest();
        if(p->isProcessing()){
            return true;
        }
        else{
            if(!p->isVisited()){
                if(verification(p)){
                    return true;
                }
            }
        }
    }
    v->setProcessing(false);
    return false;
}


bool GraphOps::isDAG(Graph<int> g) {

    for(auto& i : g.getVertexSet()){
        i->setVisited(false);
        i->setProcessing(false);
    }

    for(auto& j : g.getVertexSet()){
        if(!j->isVisited()){
            if(verification(j)){
                return false;
            }
        }
    }

    return true;
}

// ------------------------------------------------------------
bool GraphOps::directlyUnconnected(Graph<int> g, int u, int v){

// TODO

    Vertex<int> *v1 = g.findVertex(u);
    Vertex<int> *v2 = g.findVertex(v);

    for(auto i : g.getVertexSet()){
        if(i == v1){
            for(auto j : v1->getAdj()){
                if(j.getDest() == v2){
                    return false;
                }
            }
        }
    }
  return true;
}

// ------------------------------------------------------------
vector<int> GraphOps::largestOutDegree(Graph<int> g){
  vector<int> res;

// TODO

    int maximo = 0;

    for(auto i : g.getVertexSet()){
        if(i->getAdj().size() >= maximo){
            maximo = i->getAdj().size();
        }
    }

    int count = 0;
    for(auto i : g.getVertexSet()){
        if(i->getAdj().size() == maximo){
            res.push_back(count);
        }
        count++;
    }


  return res;
}

// ---------------------------------------------------------------------
vector<int> GraphOps::numberSourcesSinks(Graph<int> g){
    vector<int> res;
  
// TODO

}

// ---------------------------------------------------------------------
int GraphOps::numberConnectedComponents(Graph<int> g){
  int res;

// TODO

  return res;
}

// ---------------------------------------------------------------------
bool GraphOps::pathExists(Graph<int> g, int s, int t, vector<int> skip){

// TODO


  return false;
}
