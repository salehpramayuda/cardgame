#include "handstack.hpp"

Handstack::Handstack(){}

void Handstack::draw(Cardstack others){
    Card* temp = others.drawn();
    this->insert(temp);
}

void Handstack::insert(Card* temp){
    this->hand.push_back(temp);
}

void Handstack::throw_away(unsigned int index, Cardstack other){
    //throw away the i-th card in hand (starts from 0)
    Card* temp = this->hand[index];                 //copy card into a pointer
    this->hand.erase(this->hand.begin()+index);     //remove card from vector
    other.insert(temp);                             //insert card into stack
}

void list_card(){
    
}