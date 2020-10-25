#include <iostream>
#include <string.h>
#include "card.hpp"

Card::Card(unsigned int kd, unsigned int nr): kingdom(kd), number(nr){
    if(kd<1 || kd>4){
        std::cout << "Warning: False input of Kingdom: 0<Kingdom<5";   
        this->Card::~Card();    //if condition not fulfilled, destroyed
    }
    if(nr<1 || nr>13){
        std::cout << "Warning: False input of Number: 0<Number<14";
        this->Card::~Card();    //if condition not fulfilled, destroyed
    }
    Card::calculate_worth();    
}

void Card::calculate_worth(){
    if(number==1){
        worth = 11;             //ace equals 1
    }
    else if(number<11){
        worth = 10;             //for number 2-10
    }
    else worth = 10;            //royals equal 10
}

unsigned int Card::get_kingdom(){
    return kingdom;
}

unsigned int Card::get_worth(){
    return worth;
}

unsigned int Card::get_number(){
    return number;
}

void Card::printCard(){
    //too lazy to make this
    std::cout<<number<<". Card of the "<<kingdom<<". Kingdom"<<std::endl;
}

Card::~Card(){
    std::cout << "Card has been burned" << std::endl;
}