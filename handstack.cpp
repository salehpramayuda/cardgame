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
>>>>>>> 8129febd55fcd078e6a549c61e33792493d843f2
    this->insert(temp);
}

void Handstack::insert(Card *temp) {
<<<<<<< HEAD
    hand.push_back(temp);
}

void Handstack::throw_away(unsigned int index, Cardstack &other) {
    Card* temp = hand[index];               //add 2nd Pointer to elemetn
    hand.erase(hand.begin() + index);       //remove first pointer
    other.insert(temp);
=======
    this->hand.push_back(temp);
}

void Handstack::throw_away(unsigned int index, Cardstack &other) {
    //throw away the i-th card in hand (starts from 0)
    Card *temp = this->hand[index];               //copy card into a pointer
    this->hand.erase(this->hand.begin() + index); //remove card from vector
    other.insert(temp);                           //insert card into stack
>>>>>>> 8129febd55fcd078e6a549c61e33792493d843f2
}

void Handstack::list_card() {
    std::vector<Card *>::iterator it;
    std::cout << "Your hand contains: \n";
    for (it = hand.begin(); it < hand.end(); it++) {
        (*it)->printCard();
    }
<<<<<<< HEAD
}

Handstack::~Handstack(){
    std::vector<Card*>::iterator it=hand.begin();
    for(it; it<hand.end(); it++){
        (*it)->~Card();
    }
    std::cout << "Your Hand just got burned!" << std::endl <<std::endl;
=======
>>>>>>> 8129febd55fcd078e6a549c61e33792493d843f2
}