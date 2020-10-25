#include "cardstack.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Cardstack::Cardstack() {} //creates an empty cardstack

void Cardstack::makeStack() {
    //generate all 52 Cards and ensure that no cards can be the same
    srand(time(NULL));
    int counter = 0;
    while (counter < 52) {
        bool not_exist = false;
        unsigned int king_ran = (unsigned int)rand() % 4 + 1;
        unsigned int nr_ran = (unsigned int)rand() % 13 + 1;
        if (stack.empty()) {
            Card *temp = new Card(king_ran, nr_ran);
            stack.push_front(temp);
        } else {
            while (!not_exist) {
                std::list<Card *>::iterator it = stack.begin();
                while (it != stack.end() && !not_exist) {
                    bool check_1 = ((*it)->get_kingdom() != king_ran); //iterator it must be dereference as a pointer first
                    bool check_2 = ((*it)->get_number() != nr_ran);    //check if "card already exist"
                    if (check_1 && check_2) {
                        not_exist = true;
                    }
                    it++;
                }
                if (!not_exist) {
                    king_ran = (unsigned int)rand() % 4 + 1;
                    nr_ran = (unsigned int)rand() % 13 + 1;
                }
            }
            Card *temp = new Card(king_ran, nr_ran);
            stack.push_front(temp);
        }
        counter++;
    }
}

void Cardstack::insert(Card *toInsert) {
    this->stack.push_front(toInsert);
}

Card *Cardstack::show_top() {
    return stack.front();
}

Card *Cardstack::drawn() {
    Card *temp = show_top();
    this->stack.pop_front();
    return temp;
}

Cardstack::~Cardstack() {
    std::cout << "You have witness a Stack of Card get burned" << std::endl;
}
