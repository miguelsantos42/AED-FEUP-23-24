// ------------------------------------------------------------
//
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

class GraphOps_sol {
public:
  static bool directlyUnconnected(Graph<int> g, int u, int v);
  static vector<int> largestOutDegree(Graph<int> g);
  static bool isDAG(Graph<int> g);
  static vector<int> numberSourcesSinks(Graph<int> g);
  static bool pathExists(Graph<int> g, int s, int t, vector<int> skip);
  static int numberConnectedComponents(Graph<int> g);
};

// ------------------------------------------------------------
