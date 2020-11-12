#include "cardstack.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Cardstack::Cardstack() {} //creates an empty cardstack

void Cardstack::makeStack() {
    //generate all 52 Cards and ensure that no cards can be the same
    for(int i = 1; i < 5; i++){
        for(int j = 1; j<14; j++){
            Card* temp = new Card(i, j);
            stack.insert(stack.begin(), temp);
        }
    }

    //shuffle
    int p = rand()%9;
    srand(time(NULL));
    while(p!=0){
        for(int i = 0; i<=52; i++){
            unsigned int index = rand()%52;
            Card* temp = stack[index];
            stack.erase(stack.begin()+index);
            index = rand()%51+1;
            stack.insert(stack.begin()+index, temp);
        }
        p--;
    }
}

void Cardstack::insert(Card *toInsert) {
    this->stack.insert(stack.begin(), toInsert);
}

Card *Cardstack::show_top() {
    return this->stack.front();
}

Card *Cardstack::drawn() {
    Card *temp = this->stack.front();
    this->stack.erase(stack.begin());
    return temp;
}

unsigned int Cardstack::get_size(){
    return stack.size();
}

Cardstack::~Cardstack() {
    std::vector<Card*>::iterator it = stack.begin();
    for(it ; it != stack.end();it++){
        (*it)->~Card();
    }
    std::cout << "You have witness a Stack of Card get burned" << std::endl <<std::endl;
}
