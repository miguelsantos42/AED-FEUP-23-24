#include <algorithm>
#include "funWithCycles.h"
#include <string>
#include <cctype>
#include <map>

//=============================================================================
// Exercise 1: Palindromes
//=============================================================================
// TODO
bool FunWithCycles::palindrome(const std::string & s) {
    unsigned length = s.size();
    for(unsigned i = 0; i < length/2; i++){
        if(s[i] != s[length-i-1]){
            return false;
        }
    }
    return true;
}

//corremos a string até meio e vejo se o primeiro é igual ao último e sempre assim
//a invariante de ciclo, ou seja, a variável é algo que é verdade no inicio da interação, tem de ser igual no fim
//se o código terminar então a invariante está provada e está correta (correção parcial)
//para provar que o ciclo tem um fim usamos a variante (correção total)


//=============================================================================
// Exercise 2: Palindrome Sentences
//=============================================================================
// TODO
bool FunWithCycles::palindromeSentence(const std::string & s) {
    string new_str;
    
    for (char c: s) {
        if (isalpha(c)) {
            new_str += tolower(c);
        }
    }

    return palindrome(new_str);
}


//=============================================================================
// Exercise 3: Interesting Numbers
//=============================================================================
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {
    while (true){
        n++;
        if(digitSum(n) == sum){
            return n;
        }
    }
}

// This auxiliary function should return the sum of the digits of n
// TODO
int FunWithCycles::digitSum(int n) {
    int num = 0;
    int aux = n;

    while (aux != 0){
        int d = aux % 10;
        num = num + d;
        aux = aux / 10;
    }
    return num;
}


//=============================================================================
// Exercise 4: Winter is coming
//=============================================================================
// TODO
int FunWithCycles::winter(const vector<int> & v) {
    /*int max = 0;
    int last_temp = 0;
    int count = 0;

    for (auto i : v){
        if ((i - last_temp) < 0){
            count++;
        }
        else{
            if(count > max){
                max= count;
            }
            count = 0;
        }
        last_temp = i;

        if(){

        }
    }

    return max;*/

    int long_sequence = 0;
    int current = 0;

    for(int i = 1; i < v.size(); i++){
        int difference = v[i] - v[i-1];
        if (difference < 0){
            current++;
        }
        else{
            current = 0;
        }
        if (current > long_sequence){
            long_sequence = current;
        }
    }
    return long_sequence;
}


//=============================================================================
// Exercise 5: Playing with vectors
//=============================================================================

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {

    int total = 0;

    for(unsigned i = 0; i < v.size(); i++){
       if(v[i] == n) {
           total = total + 1;
       }
    }
    return total;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    map<int,int>counts;
    for(int i : v){
        counts[i]++;
    }
    for(auto j : counts){
        if(j.second >= 2){
            return true;
        }
    }
    return false;
}
/*
// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> & v) {
    vector<int> res;
    for(unsigned i = 0; i < v.size(); i++){

    }
}
*/
// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            ans.push_back(v1[i]);
            i++;
        }
        else if(v1[i] > v2[j]){
            ans.push_back(v2[j]);
            j++;
        }
        else{
            ans.push_back(v1[i]);
            ans.push_back(v1[i]);
            i++;
            j++;
        }
    }
    while(i < v1.size()){
        ans.push_back(v1[i]);
        i++;
    }

    while(j < v2.size()){
        ans.push_back(v2[j]);
        j++;
    }

    return ans;
}


//=============================================================================
// Exercise 6: Playing with prime numbers
//=============================================================================

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {

    if(n <= 1){
        return false;
    }

    for(int i = 2; i < n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;
    int total = 0;
    
    return ans;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;
    return ans;
}
