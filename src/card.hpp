#ifndef CARD_HPP
#define CARD_HPP
#include "rect.hpp"
#include <iostream>
#include <map>
#include <sstream>
#include <string.h>
#include <string>

class Card : public Rect {
private:
    unsigned int worth;  //value of the card
    unsigned kingdom;    //1: spade, 2: diamond, etc
    unsigned int number; //number on the card, royals are 11, 12, 13

public:
    Card(unsigned int kd, unsigned int nr, int x, int y, const std::string &image_path); //constructor
    void calculate_worth();                                                              //asign worth based on number
    unsigned int get_worth();                                                            //getter for worth
    unsigned int get_kingdom();                                                          //getter for kingdom
    unsigned int get_number();                                                           //getter for number
    std::string get_name();                                                              //get name as string
    void printCard();
    bool compare(Card *);
    ~Card(); //destructor
};

#endif