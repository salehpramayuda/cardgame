#ifndef HANDSTACK_HPP
#define HANDSTACK_HPP
#include "cardstack.hpp"
#include "tablepile.hpp"
#include <vector>

class Handstack {
private:
    std::vector<Card *> hand;

public:
    Handstack();
    void draw(Cardstack &);
    bool submit_card(unsigned int, Tablepile &);
    void list_card();
    void insert(Card *);
    int get_hand_size();
    ~Handstack();
};

#endif
