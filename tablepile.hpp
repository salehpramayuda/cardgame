#ifndef TABLEPILE_HPP
#define TABLEPILE_HPP
#include "cardstack.hpp"

/*
    A class exclusive to the game of Cangkul with 2 
*/

class Tablepile : public Cardstack{
    private:
        unsigned int attribute;         // decided by the first card
        unsigned int winner;            // index of player with biggest card
        Card* biggest;                  // card with the biggest value
        void set_biggest();
        
    public:
        Tablepile();
        bool insert(Card *);            // overriding insert-method from cardstack, return false if card failed to be inserted
        void set_winner(unsigned int);              // set winner according to card stacked inside
        unsigned int reset_pile();      // destroy cards without destroying stack and return winner
        ~Tablepile();

        


};
#endif