// ------------------------------------------------------------
//
// ------------------------------------------------------------
#include <cstddef>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#include "Graph.h"
#include "createGraphs.h"
#include "GraphOps.h"
#include "GraphOps_sol.h"

//using testing::Eq;

static int counter;
static string res_str;

//=============================================================================
bool checkVectorIntAsArray(vector<int> res, vector<int> sol){
  if(res.size() != sol.size()){
    return false;
  }
  for (unsigned i = 0; i < res.size(); i++){
    if(sol[i] != res[i]){
      return false;
    }
  }
  return true;
}

//=============================================================================
bool checkVectorIntAsSet(vector<int> res, vector<int> sol){
  if(res.size() != sol.size()){
    return false;
  }
  for (unsigned i = 0; i < res.size(); i++){
    int item = sol[i];
    if(std::find(res.begin(), res.end(), item) == res.end()){
      return false;
    }
  }
  return true;
}

void report_pred(bool p) {
  if(p) {
//      cout << ",P";
res_str += ",P";
      counter = counter + 1;
  } else {
//      cout << ",F";
res_str += ",F";
  }
}

void report_str(string s){
  //  cout << s;
   res_str += s;
}

void report_nl(){
    //cout << endl;
}

void report_count(){
    //cout << ",cnt,";
    //cout << counter;
}

//=============================================================================
// TEST 1
//=============================================================================
void TEST1() {
    int i;
    Graph<int> g;
    bool res;
    bool sol;
    string gs;

    counter = 0;
    res_str = "";

    for(i = 1; i <= 20; i++){

      gs = ",g"+to_string(i);
      report_str(gs);
      g = createGraphs::createGraphNumber(i);
      res = GraphOps::directlyUnconnected(g, 1, 2); 
      sol = GraphOps_sol::directlyUnconnected(g, 1, 2);
      report_pred((res == sol));
      g = createGraphs::createGraphNumber(i);
      res = GraphOps::directlyUnconnected(g, 1, 3);
      sol = GraphOps_sol::directlyUnconnected(g, 1, 3);
      report_pred((res == sol));
      g = createGraphs::createGraphNumber(i);
      res = GraphOps::directlyUnconnected(g, 3, 1);
      sol = GraphOps_sol::directlyUnconnected(g, 3, 1);
      report_pred((res == sol));
      g = createGraphs::createGraphNumber(i);
      res = GraphOps::directlyUnconnected(g, 2, 0);
      sol = GraphOps_sol::directlyUnconnected(g, 2, 0);
      report_pred((res == sol));
      g = createGraphs::createGraphNumber(i);
      res = GraphOps::directlyUnconnected(g, 0, 4);
      sol = GraphOps_sol::directlyUnconnected(g, 0, 4);
      report_pred((res == sol));
      g = createGraphs::createGraphNumber(i);
      res = GraphOps::directlyUnconnected(g, 3, 4);
      sol = GraphOps_sol::directlyUnconnected(g, 3, 4);
      report_pred((res == sol));

  }
  res_str = "test1,"+ to_string(counter) + res_str;
  cout << res_str << endl;
}

//=============================================================================
// TEST 2 
//=============================================================================
void TEST2() {
  int i;
  vector<int> vec;
  vector<int> sol;
  Graph<int> g;
   bool res;
   string gs;

    counter = 0;
    res_str = "";
    for(i = 1; i <= 20; i++){
      gs = ",g"+to_string(i);
      report_str(gs);
      g = createGraphs::createGraphNumber(i);
      vec = GraphOps::largestOutDegree(g);
      g = createGraphs::createGraphNumber(i);
      sol = GraphOps_sol::largestOutDegree(g);
      res = checkVectorIntAsSet(vec, sol);
      report_pred(res);
    }
    res_str = "test2,"+ to_string(counter) + res_str;
    cout << res_str << endl;
}

//=============================================================================
// TEST 3 
//=============================================================================
void TEST3() {
  int i;
  Graph<int> g;
  bool sol;
  bool res;
  string gs;

    counter = 0;
    res_str = "";
    for(i = 1; i <= 20; i++){
      gs = ",g"+to_string(i);
      report_str(gs);
      g = createGraphs::createGraphNumber(i);
      res = GraphOps::isDAG(g);
      g = createGraphs::createGraphNumber(i);
      sol = GraphOps_sol::isDAG(g);
      report_pred((res == sol));
    }
    res_str = "test3,"+ to_string(counter) + res_str;
    cout << res_str << endl;
}

//=============================================================================
// TEST 4 
//=============================================================================
void TEST4() {
  int i;
  vector<int> vec;
  vector<int> sol;
  Graph<int> g;
  bool res;
  string gs;

    counter = 0;
    res_str = "";
    for(i = 1; i <= 20; i++){
      gs = ",g"+to_string(i);
      report_str(gs);

      g = createGraphs::createGraphNumber(i);
      vec = GraphOps::numberSourcesSinks(g);
      g = createGraphs::createGraphNumber(i);
      sol = GraphOps_sol::numberSourcesSinks(g);
      res = checkVectorIntAsSet(vec, sol);
      report_pred(res);
    }
    res_str = "test4,"+ to_string(counter) + res_str;
    cout << res_str << endl;
}

//=============================================================================
// TEST 5 
//=============================================================================
void TEST5(){
  int i, n;
  bool res;
  bool sol;
  Graph<int> g;
  vector<int> skip1;
  vector<int> skip2;
  vector<int> skip3;
  vector<int> skip4;
  vector<int> skip5;
  vector<int> skip6;
  vector<int> skip7;
  vector<int> skip8;

    string gs;

    counter = 0;
    res_str = "";
    for(i = 1; i <= 20; i++){
      if(((i >= 4) && (i <= 7)) || ((i >= 10) && (i <= 18))) {
        continue;
      }
      gs = ",g"+to_string(i);
      report_str(gs);

      g = createGraphs::createGraphNumber(i);
      skip1.clear();
      skip1.push_back(2);
      res = GraphOps::pathExists(g, 0, 5, skip1);
      skip1.clear();
      skip1.push_back(2);
      sol = GraphOps_sol::pathExists(g, 0, 5, skip1);
      report_pred((res == sol));

      g = createGraphs::createGraphNumber(i);
      skip2.clear();
      skip2.push_back(3);
      res = GraphOps::pathExists(g, 0, 5, skip2);
      skip2.clear();
      skip2.push_back(3);
      sol = GraphOps_sol::pathExists(g, 0, 5, skip2);
      report_pred((res == sol));

      g = createGraphs::createGraphNumber(i);
      skip3.clear();
      skip3.push_back(4);
      res = GraphOps::pathExists(g, 1, 6, skip3);
      skip3.clear();
      skip3.push_back(4);
      sol = GraphOps_sol::pathExists(g, 1, 6, skip3);
      report_pred((res == sol));

      g = createGraphs::createGraphNumber(i);
      skip4.clear();
      skip4.push_back(7);
      skip4.push_back(8);
      res = GraphOps::pathExists(g, 1, 6, skip4);
      skip4.clear();
      skip4.push_back(7);
      skip4.push_back(8);
      sol = GraphOps_sol::pathExists(g, 1, 6, skip4);
      report_pred((res == sol));

      g = createGraphs::createGraphNumber(i);
      skip5.clear();
      skip5.push_back(1);
      res = GraphOps::pathExists(g, 0, 2, skip5);
      skip5.clear();
      skip5.push_back(1);
      sol = GraphOps_sol::pathExists(g, 0, 2, skip5);
      report_pred((res == sol));

      g = createGraphs::createGraphNumber(i);
      skip6.clear();
      skip6.push_back(2);
      res = GraphOps::pathExists(g, 0, 1, skip6);
      skip6.clear();
      skip6.push_back(2);
      sol = GraphOps_sol::pathExists(g, 0, 1, skip6);
      report_pred((res == sol));

      g = createGraphs::createGraphNumber(i);
      skip7.clear();
      skip7.push_back(2);
      res = GraphOps::pathExists(g, 1, 0, skip7);
      skip7.clear();
      skip7.push_back(2);
      sol = GraphOps_sol::pathExists(g, 1, 0, skip7);
      report_pred((res == sol));

      g = createGraphs::createGraphNumber(i);
      skip8.clear();
      skip8.push_back(0);
      res = GraphOps::pathExists(g, 1, 5, skip8);
      skip8.clear();
      skip8.push_back(0);
      sol = GraphOps_sol::pathExists(g, 1, 5, skip8);
      report_pred((res == sol));
    }
    res_str = "test5,"+ to_string(counter) + res_str;
    cout << res_str << endl;

}

//=============================================================================
// TEST 6 
//=============================================================================
void TEST6(){
  int i;
  Graph<int> g;
  int sol;
  int res;
    string gs;

    counter = 0;
    res_str = "";
    for(i = 1; i <= 20; i++){
        gs = ",g"+to_string(i);
        report_str(gs);

      g = createGraphs::createGraphNumber(i);
      res = GraphOps::numberConnectedComponents(g);
      g = createGraphs::createGraphNumber(i);
      sol = GraphOps_sol::numberConnectedComponents(g);
      report_pred((res == sol));
    }
    res_str = "test6,"+ to_string(counter) + res_str;
    cout << res_str << endl;
}


// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------
int main(int argc, char **argv) {

  if(atoi(argv[1]) == 1)
    TEST1();
  if(atoi(argv[1]) == 2)
    TEST2();
  if(atoi(argv[1]) == 3)
    TEST3();
  if(atoi(argv[1]) == 4)
    TEST4();
  if(atoi(argv[1]) == 5)
    TEST5();
  if(atoi(argv[1]) == 6)
    TEST6();

  return 0;
}
