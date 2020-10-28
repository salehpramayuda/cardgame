#include "handstack.hpp"
#include <iostream>

Handstack::Handstack() {}

void Handstack::draw(Cardstack &others) {
    Card *temp = others.drawn();
    std::cout << "Drawing: " << temp->get_name() << std::endl;
    this->insert(temp);
}

void Handstack::insert(Card *temp) {
    this->hand.push_back(temp);
}

void Handstack::throw_away(unsigned int index, Cardstack &other) {
    //throw away the i-th card in hand (starts from 0)
    Card *temp = this->hand[index];               //copy card into a pointer
    this->hand.erase(this->hand.begin() + index); //remove card from vector
    other.insert(temp);                           //insert card into stack
}

void Handstack::list_card() {
    std::vector<Card *>::iterator it;
    std::cout << "Your hand contains: \n";
    for (it = hand.begin(); it < hand.end(); it++) {
        (*it)->printCard();
    }
}

Handstack::~Handstack(){
    std::vector<Card*>::iterator it=hand.begin();
    for(it; it<hand.end(); it++){
        (*it)->~Card();
    }
    std::cout << "Your Hand just got burned!" << std::endl <<std::endl;
}