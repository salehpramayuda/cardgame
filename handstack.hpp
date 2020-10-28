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
    void submit_card(unsigned int, Cardstack &);
    void throw_away(unsigned int, Cardstack &);
    void list_card();
    void insert(Card *);
    int get_hand_size();
};

#endif
