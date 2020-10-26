#include "handstack.hpp"
#include <iostream>

Handstack::Handstack() {}

void Handstack::draw(Cardstack &others) {
    Card *temp = others.drawn();
    std::cout << "Drawing: " << temp->get_name() << std::endl;
    this->insert(temp);
}

void Handstack::insert(Card *temp) {
    hand.push_back(temp);
}

void Handstack::throw_away(unsigned int index, Cardstack &other) {
    Card* temp = hand[index];               //add 2nd Pointer to elemetn
    hand.erase(hand.begin() + index);       //remove first pointer
    other.insert(temp);
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