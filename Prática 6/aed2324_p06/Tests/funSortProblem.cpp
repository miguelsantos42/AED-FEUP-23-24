#include "funSortProblem.h"

FunSortProblem::FunSortProblem() {}


//=============================================================================
// Exercise 4: Min Difference
//=============================================================================
// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if (nc > values.size()){
        return -1;
    }
    vector<unsigned> sortedvalues = values;
    sort(sortedvalues.begin(),sortedvalues.end());
    int dif = sortedvalues[nc-1] - sortedvalues[0]; //8
    //[1,3,4,7,9,9,12,56]
    for(int i = 1; i <= sortedvalues.size()-nc;i++){
        if(sortedvalues[nc-1+i]- sortedvalues[i] < dif){
            dif = sortedvalues[nc-1+i]- sortedvalues[i];
        }
    }
    return dif;
}


//=============================================================================
// Exercise 6: Num Inversions (extra)
//=============================================================================
//TODO
unsigned FunSortProblem::numInversions(vector <int> v) {
    return 0;
}


//=============================================================================
// Exercise 7: Nuts and Bolts (extra)
//=============================================================================
// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}
