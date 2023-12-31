#include "funListStackQueueProblem.h"
#include "cell.h"

FunListStackQueueProblem::FunListStackQueueProblem() {}


//=============================================================================
// Exercise 1: Remove Higher
//=============================================================================
// TODO
list<int> FunListStackQueueProblem::removeHigher(list<int> &values, int x) {
    list<int> l1;
    list<int> l2;

    for(auto i = values.begin(); i != values.end();i++){
        //cout << *i << endl;
        if(*i > x){
            l1.push_back(*i);
        }
        else{
            l2.push_back(*i);
        }
    }
    values = l2;
    return l1;
}


//=============================================================================
// Exercise 2: Overlapping Intervals
//=============================================================================
//TODO
list<pair<int,int>> FunListStackQueueProblem::overlappingIntervals(list<pair<int,int>> values) {
    list<pair<int, int>> res;
    values.sort();

    int start;
    int end;

    for (auto i = values.begin(); i != values.end(); i++) {
        if (i == values.begin()) {
            start = values.begin()->first;
            end = values.begin()->second;
        } else {
            if (end >= i->first) {
                end = max(end, i->second);
            } else {
                res.push_back(make_pair(start, end));
                start = i->first;
                end = i->second;
            }
        }
    }
    res.push_back(make_pair(start, end));

    return res;
}


//=============================================================================
// Exercise 4: Binary Numbers
//=============================================================================
// TODO
vector<string> FunListStackQueueProblem::binaryNumbers(int n) {
    vector<string> res;
    stack<int> pilha;
    for(int i = 1; i < n+1; i++){
        string str = "";
        int aux = i;
        while (aux > 0){
            int d = aux % 2;
            aux = aux / 2;
            if(d){
                str = "1" + str;
            }
            else{
                str = "0" + str;
            }
        }
        res.push_back(str);
    }
    return res;
}


//=============================================================================
// Exercise 5: Calculate Span
//=============================================================================
//TODO
vector<int> FunListStackQueueProblem::calculateSpan(vector<int> prices) {
    vector<int> res;
    stack<pair<int,int>> pilha;
    int count = 0;

    for(int i = 0; i < prices.size(); i++) {
        count = 1;
        if (pilha.empty()) {
            pilha.push(make_pair(prices[i], count));
        } else {
            while (!pilha.empty() && pilha.top().first < prices[i]) {
                count += pilha.top().second;
                pilha.pop();
            }
            pilha.push(make_pair(prices[i], count));
        }
        res.push_back(count);
    }
    return res;
}


//=============================================================================
// Exercise 7: Knight Jumps
//=============================================================================
//TODO
int FunListStackQueueProblem::knightJumps(int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n) {
    return -1;
}
