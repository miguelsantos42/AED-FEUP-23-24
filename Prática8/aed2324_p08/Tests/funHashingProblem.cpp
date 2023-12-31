#include "funHashingProblem.h"

FunHashingProblem::FunHashingProblem() {}


//=============================================================================
// Exercise 1: Find Duplicates
//=============================================================================
// TODO
vector<int> FunHashingProblem::findDuplicates(const vector<int>& values, int k) {
    vector<int> res; //guarda os valores duplos
    unordered_set<int> usada; //guarda o intervalo usado com k valores

    for(int i = 0; i < values.size(); i++){
        if(i > k){
            usada.erase(values[i-k-1]);
        }
        if(usada.find(values[i]) != usada.end()){
            res.push_back(values[i]);
        }
        usada.insert(values[i]);
    }
    return res;
}
