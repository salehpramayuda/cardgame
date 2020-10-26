#include "handstack.hpp"
#include <iostream>

Handstack::Handstack() {}

void Handstack::draw(Cardstack &others) {
    Card *temp = others.drawn();
    std::cout << "Drawing: ";
    temp->printCard();
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