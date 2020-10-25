#include "handstack.hpp"

Handstack::Handstack(){}

void Handstack::draw(Cardstack others){
    Card* temp = others.drawn();
    this->insert(temp);
}

void Handstack::insert(Card* temp){

}

void Handstack::throw_away(unsigned int index, Cardstack){
}