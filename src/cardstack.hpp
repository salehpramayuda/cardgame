#ifndef CARDSTACK_HPP
#define CARDSTACK_HPP
#include "card.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

class Cardstack {
protected:
    int card_index;

public:
    std::vector<Card *> stack; //contains Card-Pointer and not Card itself

public:
    Cardstack();                 //creates an empty cardstack
    void makeStack(Vector2 res); //for center Stack
    void shuffleStack();
    void insert(Card *);     //insert card into top of cardstack
    Card *show_top();        //getter for top Card
    Card *drawn();           //taking top card out of cardstack
    unsigned int get_size(); //getter for stack size
    ~Cardstack();

private:
    std::string generateCardPath(int kd, int nr);
};

#endif