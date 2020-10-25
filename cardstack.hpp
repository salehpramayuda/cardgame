#ifndef CARDSTACK_HPP
#define CARDSTACK_HPP
#include <list>
#include "card.hpp"

class Cardstack{
    protected:
        std::list <Card*> stack;    //contains Card-Pointer and not Card itself
    public:
        Cardstack();                //creates an empty cardstack
        void makeStack();           //for center Stack
        void insert(Card*);         //insert card into top of cardstack
        Card* show_top();           //getter for top Card
        Card* drawn();              //taking top card out of cardstack
        ~Cardstack();
};

#endif