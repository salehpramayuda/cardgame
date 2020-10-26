#ifndef HANDSTACK_HPP
#define HANDSTACK_HPP
#include "cardstack.hpp"
#include <vector>

class Handstack {
private:
    std::vector<Card *> hand;

public:
    Handstack();
    void draw(Cardstack &);
    void throw_away(unsigned int, Cardstack &);
    void list_card();
    void insert(Card *);
};

#endif