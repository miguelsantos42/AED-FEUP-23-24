// ------------------------------------------------------------ //
// ------------------------------------------------------------
//
//
// ------------------------------------------------------------

#include <cstddef>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#include "Graph.h"
#include "createGraphs.h"
#include "GraphOps_sol.h"

// ------------------------------------------------------------
void DFSTraverseAUX_sol(Graph<int> g, Vertex<int> *v){
  v->setVisited(true);
  v->setProcessing(true);
  for (auto & e : v->getAdj()) {
    auto w = e.getDest();
//    if (w->isProcessing())
//      return;
    if (! w->isVisited()){
      DFSTraverseAUX_sol(g, w);
    }
  }
  v->setProcessing(false);
}

// ------------------------------------------------------------
bool dfsIsDAG_sol(Vertex<int> *v);
bool GraphOps_sol::isDAG(Graph<int> g) {
  for (auto v : g.getVertexSet()) {
    v->setVisited(false);
    v->setProcessing(false);
  }
  for (auto v : g.getVertexSet()){
    if (! v->isVisited())
      if ( ! dfsIsDAG_sol(v) )
        return false;
  }
  return true;
}

bool dfsIsDAG_sol(Vertex<int> *v) {
  v->setVisited(true);
  v->setProcessing(true);
  for (auto & e : v->getAdj()) {
    auto w = e.getDest();
    if (w->isProcessing())
      return false;
    if (! w->isVisited()){
      if (! dfsIsDAG_sol(w))
        return false;
    }
  }
  v->setProcessing(false);
  return true;
}

// ------------------------------------------------------------
bool GraphOps_sol::directlyUnconnected(Graph<int> g, int u, int v){
  Vertex<int>* vtx;

  vtx = g.findVertex(u);
  if(vtx == NULL){
    return true;
  }
  for (auto & e : vtx->getAdj()) {
    auto w = e.getDest();
    if(w->getInfo() == v){
      return false;
    }
  }
  return true;
}

// ------------------------------------------------------------
vector<int> GraphOps_sol::largestOutDegree(Graph<int> g){
  int k, max;
  vector<int> res;

  max = 0;
  for (auto v : g.getVertexSet()) {
    k = (v->getAdj().size());
    if(k > max){
      max = k;
    }
  }
  for (auto v : g.getVertexSet()) {
    k = (v->getAdj().size());
    if(k == max){
      res.push_back(v->getInfo());
    }
  }
  return res;
}

// ---------------------------------------------------------------------
vector<int> GraphOps_sol::numberSourcesSinks(Graph<int> g){
  int k, i, sz;
  int numSinks;
  int numSources;
  vector<int> res;
  stack<int> edge_stack;
  stack<int> aux_stack;
  int *r;

  numSinks   = 0;
  numSources = 0;

  sz =  g.getVertexSet().size();
  r = new int[sz];
  for (i = 0; i < sz; i++){
    r[i] = 0;
  }

  for (auto v : g.getVertexSet()) {
    for (auto & e : v->getAdj()) {
      int dst;
      auto w = e.getDest();
      dst = w->getInfo();
      r[dst] = 1;
    }
  }

  numSinks = 0;
  for (i = 0; i < sz; i++){
    if(r[i] == 0){
      numSources++;
    }
  }

  for (auto v : g.getVertexSet()) {
    k = (v->getAdj().size());
    if(k == 0){
      numSinks++;
    }
  }

  delete []r;

  res.push_back(numSources);
  res.push_back(numSinks);
  return res;
}

// ---------------------------------------------------------------------
int GraphOps_sol::numberConnectedComponents(Graph<int> g){
  int num_components;

  stack<int> edge_stack;

  for (auto v : g.getVertexSet()) {
    for (auto & e : v->getAdj()) {
      auto w = e.getDest();
      edge_stack.push(w->getInfo());
      edge_stack.push(v->getInfo());
    }
  }

  // --- Now we invert the edges by removing them and then pustting back in reverse.
  while (!edge_stack.empty()) {
    int src;
    int dst;
    dst = edge_stack.top();
    edge_stack.pop();
    src = edge_stack.top();
    edge_stack.pop();
    g.addEdge(src,dst,0);
  }

  // --- we now compute the DFS on all the invisited nodes.

  for (auto v : g.getVertexSet()) {
    v->setVisited(false);
    v->setProcessing(false);
  }

  num_components = 0;
  for (auto v : g.getVertexSet()) {
    if(!v->isVisited()){
      num_components++;
      DFSTraverseAUX_sol(g, v);
    }
  }
  return num_components;
}

// ---------------------------------------------------------------------
bool dfsPathExists_sol(Vertex<int> *v, int t, vector<int> skip);
bool GraphOps_sol::pathExists(Graph<int> g, int s, int t, vector<int> skip){
  Vertex<int> *vtx;

  for (auto v : g.getVertexSet()) {
    v->setVisited(false);
    v->setProcessing(false);
  }

  // --- check niether s nor t are in skip.
  if(find(skip.begin(), skip.end(), s) != skip.end()){
    return false;
  }
  if(find(skip.begin(), skip.end(), t) != skip.end()){
    return false;
  }

  vtx = g.findVertex(s);
  return dfsPathExists_sol(vtx,t, skip);
}

bool dfsPathExists_sol(Vertex<int> *v, int t, vector<int> skip) {
  int id;

  v->setVisited(true);
  v->setProcessing(true);
  for (auto & e : v->getAdj()) {
    auto w = e.getDest();
    id = w->getInfo();
    if(id == t){
      return true;
    }
    // --- check is neighbor is in skip.
    if(find(skip.begin(), skip.end(), id) != skip.end()){
     // --- skip
    } else {
      if (!w->isProcessing()){
        if (! w->isVisited()){
          if(dfsPathExists_sol(w,t,skip))
 	    return true;
        }
      }
    }
  }
  v->setProcessing(false);
  return false;
}
