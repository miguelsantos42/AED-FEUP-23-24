#include "funHashingProblem.h"

FunHashingProblem::FunHashingProblem() {}


//=============================================================================
// Exercise 1: Find Duplicates
//=============================================================================
// TODO
vector<int> FunHashingProblem::findDuplicates(const vector<int>& values, int k) {
    vector<int> res;
    unordered_set<int> use;

    for(int i = 0; i < values.size(); i++){
        if(i > k){
            use.erase(values[i-k-1]);
        }
        if(use.find(values[i]) != use.end()){
            res.push_back(values[i]);
        }
        use.insert(values[i]);
    }
    return res;
}
