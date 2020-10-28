#include "handstack.hpp"
#include <iostream>

Handstack::Handstack() {}

void Handstack::draw(Cardstack &others) {
    if(others.get_size()==0){
        std::cout << "Deck is empty!" << std::endl;
    }
    else{
        Card *temp = others.drawn();
        std::cout << "Drawing: " << temp->get_name() << std::endl;
        this->insert(temp);
    }
}

void Handstack::insert(Card *temp) {
    this->hand.push_back(temp);
}

bool Handstack::submit_card(unsigned int index, Tablepile &other) {
    //throw away the i-th card in hand (starts from 0)
    Card *temp = this->hand[index];               //copy card into a pointer
    this->hand.erase(this->hand.begin() + index); //remove card from vector
    std::cout << "You played: " << temp->get_name() << std::endl;
    if(!other.insert(temp)){                        //insert card into stack
        draw(other);                                //if failed, card must be
        return false;                               //drawn back
    }
    return true;
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

Handstack::~Handstack(){
    std::vector<Card*>::iterator it=hand.begin();
    for(it; it<hand.end(); it++){
        (*it)->~Card();
    }
    std::cout << "Your Hand just got burned!" << std::endl <<std::endl;
}

int Handstack::get_hand_size() {
    return hand.size();
}
