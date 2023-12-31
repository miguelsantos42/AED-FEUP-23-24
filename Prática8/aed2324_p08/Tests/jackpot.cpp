#include <iostream>
#include "jackpot.h"


Bet::Bet(vector<int> ns, string p): numbers(ns), player(p) {}

vector<int> Bet::getNumbers() const {
    return numbers;
}

string Bet::getPlayer() const {
    return player;
}

Jackpot::Jackpot(){}

unsigned Jackpot::getNumBets() const {
    return bets.size();
}


//=============================================================================
// Exercise 2: Jackpot
//=============================================================================
// Subexercise 2.1: Add Bet
//=============================================================================
// TODO
void Jackpot::addBet(const Bet& b) {
    bets.insert(b);
}

//=============================================================================
// Subexercise 2.2: Bets in Number
//=============================================================================
// TODO
unsigned Jackpot::betsInNumber(unsigned num) const {
	unsigned count = 0;
    for(auto i : bets){
        for(auto j : i.getNumbers()){
            if(j == num){
                count++;
            }
        }
    }
	return count;
}

//=============================================================================
// Subexercise 2.3: Drawn Bets
//=============================================================================
// TODO
vector<string> Jackpot::drawnBets(vector<int> draw) const {
	vector<string> res;
    for(auto i : bets){
        int count = 0;
        for(auto j : i.getNumbers()){
            for(auto h : draw){
                if(j == h){
                    count++;
                }
                if(count == 3){
                    res.push_back(i.getPlayer());
                    break;
                }
            }
            if(count == 3){
                break;
            }
        }
    }
	return res;
}
