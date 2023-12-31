#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

void Game::addKid(const Kid k1) {
 	kids.push_back(k1);
}

list<Kid> Game::getKids() const {
	return this->kids;
}

void Game::setKids(const list<Kid>& l1) {
    this->kids = l1;
}

//=============================================================================
// Exercise 6: Pim Pam Pum
//=============================================================================
// Subexercise 6.1: Loose Game
//=============================================================================
// TODO
Kid Game::loseGame(string phrase) {
    int n = numberOfWords(phrase);
    auto i = kids.begin();
    while (kids.size() > 1) {
        for (int j = 0; j < n - 1; j++) {
            ++i;
            if (i == kids.end()) {
                i = kids.begin();
            }
        }
        i = kids.erase(i);
        if (i == kids.end()) {
            i = kids.begin();
        }
    }
    return *kids.begin();
}


//=============================================================================
// Subexercise 6.2: Rearrange
//=============================================================================
// TODO

list<Kid> Game::rearrange() {
    queue<Kid> girls;
    queue<Kid> boys;
    list<Kid> res;
    list<Kid> lista;

    for(const Kid& kid : kids){
        if (kid.getSex() == 'f'){
            girls.push(kid);
        }
        else{
            boys.push(kid);
        }
    }


    int n = girls.size();
    int m = boys.size();
    int quant_girls = 0;
    int quant_boyz = 0;

    if (n == 0 | m == 0){
        quant_boyz = boys.size();
        quant_girls = girls.size();
    }

    else if(n < m){
        quant_girls = 1;
        quant_boyz = m / n;
    }

    else if(n >= m){
        quant_boyz = 1;
        quant_girls = n / m;
    }


    while(boys.size() >= quant_boyz and girls.size() >= quant_girls){
        if (m > n) {
            lista.push_back(girls.front());
            girls.pop();
            for (int i = 0; i < quant_boyz;i++){
                lista.push_back(boys.front());
                boys.pop();
            }
        }

        if (m <= n) {
            lista.push_back(boys.front());
            boys.pop();
            for (int i = 0; i < quant_girls;i++){
                lista.push_back(girls.front());
                girls.pop();
            }
        }
    }

    while (boys.size() > 0){
        res.push_back(boys.front());
        boys.pop();
    }

    while (girls.size() > 0){
        res.push_back(girls.front());
        girls.pop();
    }

    kids = lista;

    return res;
}


//=============================================================================
// Subexercise 6.3: Shuffle
//=============================================================================
// TODO
list<Kid> Game::shuffle() const {
    list<Kid> newList;

    for(const Kid& kid : kids){

    }

    return newList;
}
