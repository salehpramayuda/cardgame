#include "handstack.hpp"
#include <iostream>

Handstack::Handstack() {}

void Handstack::draw(Cardstack &others) {
    Card *temp = others.drawn();
<<<<<<< HEAD
    std::cout << "Drawing: " << temp->get_name() << std::endl;
=======
    std::cout << "Drawing: ";
    temp->printCard();
>>>>>>> ad768c473a9e3af92a3901d11296660762df359b
    this->insert(temp);
}

void Handstack::insert(Card *temp) {
    this->hand.push_back(temp);
<<<<<<< HEAD
=======
}

void Handstack::throw_away(unsigned int index, Cardstack &other) {
    //throw away the i-th card in hand (starts from 0)
    Card *temp = this->hand[index];               //copy card into a pointer
    this->hand.erase(this->hand.begin() + index); //remove card from vector
    other.insert(temp);                           //insert card into stack
>>>>>>> ad768c473a9e3af92a3901d11296660762df359b
}

void Handstack::submit_card(unsigned int index, Cardstack &other) {
    //throw away the i-th card in hand (starts from 0)
    Card *temp = this->hand[index];               //copy card into a pointer
    this->hand.erase(this->hand.begin() + index); //remove card from vector
    other.insert(temp);                           //insert card into stack
<<<<<<< HEAD
=======
    std::cout << "You played: " << temp->get_name() << std::endl;
>>>>>>> ad768c473a9e3af92a3901d11296660762df359b
}

void Handstack::list_card() {
    std::vector<Card *>::iterator it;
    std::cout << "Your hand contains: \n";
    int index = 0;
    for (it = hand.begin(); it < hand.end(); it++) {
        std::cout << index << ": ";
        (*it)->printCard();
        index++;
    }
}

<<<<<<< HEAD
Handstack::~Handstack(){
    std::vector<Card*>::iterator it=hand.begin();
    for(it; it<hand.end(); it++){
        (*it)->~Card();
    }
    std::cout << "Your Hand just got burned!" << std::endl <<std::endl;
}
=======
int Handstack::get_hand_size() {
    return hand.size();
}
>>>>>>> ad768c473a9e3af92a3901d11296660762df359b
