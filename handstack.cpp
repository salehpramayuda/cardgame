#include "handstack.hpp"
#include <iostream>

Handstack::Handstack() {}

void Handstack::draw(Cardstack others) {
    Card *temp = others.drawn();
    std::cout << "Drawing\n";
    temp->printCard();
    this->insert(temp);
}

void Handstack::insert(Card *temp) {
    hand.push_back(temp);
}

void Handstack::throw_away(unsigned int index, Cardstack) {
    hand.erase(hand.begin() + index);
}

void Handstack::list_card() {
    std::vector<Card *>::iterator it;
    std::cout << "Your hand contains: \n";
    for (it = hand.begin(); it < hand.end(); it++) {
        (*it)->printCard();
    }
}