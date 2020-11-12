#include "tablepile.hpp"
#include <iostream>
#include <map>

Tablepile::Tablepile(): Cardstack() {
    attribute = 0;
    winner = 0;
    biggest = NULL;
}

bool Tablepile::insert(Card* card){
    std::map<int, std::string> kingdom_names = {
        {1, "Clubs"},
        {2, "Diamonds"},
        {3, "Hearts"},
        {4, "Spades"},
    };
    Cardstack::insert(card);
    if(attribute == 0){
        attribute = card->get_kingdom();
        std::cout << "Pile has been set to " << kingdom_names[attribute] << "!\n";
        set_biggest();
        return true;
    }
    else{
        if(attribute!= card->get_kingdom()){
            std::cout << "Your card has been rejected!" << std::endl;
            std::cout << "Please draw your card back and play a card from the correct kingdom!\n";
            return false;
        }
        else{
            set_biggest();
            return true;
        }
    }
}

void Tablepile::set_biggest(){
    if(biggest == NULL){
        biggest = stack.front();
    }
    else{
        if(stack.front()->compare(biggest)){
            biggest = stack.front();
        }
    }
}

void Tablepile::set_winner(unsigned int current_player){    // made public because parameter is needed
    if(biggest==stack.front()){
        winner = current_player;
        
    }
}

unsigned int Tablepile::reset_pile(){
    unsigned int temp = winner;
    winner = 0;
    biggest = NULL;
    attribute = 0;
    std::vector<Card*>::iterator it = stack.begin();
    for(it; it!=stack.end(); it++){
        (*it)->~Card();
    }
    return temp;
}

Tablepile::~Tablepile(){
    std::vector<Card*>::iterator it = stack.begin();
    for(it; it!=stack.end(); it++){
        (*it)->~Card();
    }
    std::cout << "The table pile has been set on fire!\n";
}
