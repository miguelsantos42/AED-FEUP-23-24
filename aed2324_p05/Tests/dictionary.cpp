#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
	return words;
}

void Dictionary::addWord(WordMean wm)  {
    words.insert(wm);
}


//=============================================================================
// Exercise 1: Dictionary
//=============================================================================
//TODO
bool WordMean::operator< (const WordMean& wm2) const {
    if(wm2.getWord() > getWord()) return true;
    return false;
}

//=============================================================================
// Subexercise 1.1: Create Dictionary
//=============================================================================
//TODO
void Dictionary::readFile(ifstream &f) {
    string line_word;
    string line_meaning;

    while (getline(f, line_word) && getline(f, line_meaning)) {
        WordMean palavra(line_word, line_meaning);
        cout << line_word << line_meaning;
        addWord(palavra);
    }
}

//=============================================================================
// Subexercise 1.2: Print Dictionary
//=============================================================================
//TODO
void Dictionary::print() const {
    for(auto& wm : words){
        cout << wm.getWord() << endl;
        cout << wm.getMeaning() << endl;
    }
}

//=============================================================================
// Subexercise 1.3: Consult Dictionary
//=============================================================================
//TODO
string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {
    previous = WordMean("", "");
    for(auto& i: words){
        if(i.getWord() == w1){
            return i.getMeaning();
        }
        else if(i.getWord() > w1){
            next = i;
            return "word not found";
        }
        previous = i;
    }
    next = WordMean("","");
    return "word not found";
}

//=============================================================================
// Subexercise 1.4: Update Dictionary
//=============================================================================
//TODO
bool Dictionary::update(string w1, string m1) {
    auto it = words.find(WordMean(w1, ""));
    if (it != words.end()) {
        // Remover o elemento antigo
        words.erase(it);
        // Adicionar o novo elemento com o significado atualizado
        words.insert(WordMean(w1, m1));
        return true; // Retornar true para indicar que a palavra foi atualizada
    } else {
        // Adicionar uma nova palavra se ela não existir
        words.insert(WordMean(w1, m1));
        return false; // Retornar false para indicar que uma nova palavra foi adicionada
    }
}