#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "card.hpp"
#include "cardstack.hpp"
#include "handstack.hpp"


class Player{
    private:
        Handstack cards_in_hand;
        Cardstack sidestack;
        unsigned int score;

    public:
        Player();
        void calculate_score();
        void draw();
        ~Player();
};

#endif