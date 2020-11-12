#ifndef CARDSTACK_HPP
#define CARDSTACK_HPP
#include "card.hpp"
#include <vector>

class Cardstack {
protected:
    std::vector<Card *> stack; //contains Card-Pointer and not Card itself
public:
    Cardstack();            //creates an empty cardstack
    void makeStack();       //for center Stack
    void insert(Card *);    //insert card into top of cardstack
    Card *show_top();       //getter for top Card
    Card *drawn();          //taking top card out of cardstack
    unsigned int get_size();//getter for stack size
    ~Cardstack();
};

#endif