#include "card.hpp"
#include <iostream>
#include <map>
#include <sstream>
#include <string.h>

Card::Card(unsigned int kd, unsigned int nr) : kingdom(kd), number(nr) {
    if (kd < 1 || kd > 4) {
        std::cout << "Warning: False input of Kingdom: 0<Kingdom<5";
        this->Card::~Card(); //if condition not fulfilled, destroyed
    }
    if (nr < 1 || nr > 13) {
        std::cout << "Warning: False input of Number: 0<Number<14";
        this->Card::~Card(); //if condition not fulfilled, destroyed
    }
    Card::calculate_worth();
}

void Card::calculate_worth() {
    if (number == 1) {
        worth = 11; //ace equals 1
    } else if (number < 11) {
        worth = 10; //for number 2-10
    } else
        worth = 10; //royals equal 10
}

unsigned int Card::get_kingdom() {
    return kingdom;
}

unsigned int Card::get_worth() {
    return worth;
}

unsigned int Card::get_number() {
    return number;
}

std::string Card::get_name() {
    std::map<int, std::string> kingdom_names = {
        {1, "Clubs"},
        {2, "Diamonds"},
        {3, "Hearts"},
        {4, "Spades"},
    };
    std::map<int, std::string> number_names = {
        {1, "Ace"},
        {2, "2"},
        {3, "3"},
        {4, "4"},
        {5, "5"},
        {6, "6"},
        {7, "7"},
        {8, "8"},
        {9, "9"},
        {10, "10"},
        {11, "Jack"},
        {12, "Queen"},
        {13, "King"},
    };
    std::stringstream ss;
    ss << number_names[number] << " of " << kingdom_names[kingdom];
    return ss.str();
}

void Card::printCard() {
    std::cout << get_name() << std::endl;
}

bool Card::compare(Card* other){
    if(worth>other->get_worth()){
        return true;
    }
    else{
        if(worth==other->get_worth()){
            if(number>other->get_number()){
                return true;
            }
            else{
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    
}

Card::~Card() {
    std::cout << get_name() << " has been burned" << std::endl;
}
