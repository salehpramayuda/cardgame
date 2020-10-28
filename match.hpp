#ifndef MATCH_HPP
#define MATCH_HPP
#include "card.hpp"
#include "cardstack.hpp"
#include "handstack.hpp"
#include "tablepile.hpp"
#include <iostream>

class Match {
private:
    std::vector<Handstack *> players;   // Vector for easy call by index
    Cardstack deck;                     // make_stack()
    Tablepile table_pile;               // to throw card away
    unsigned int current_player;        // index of current player
    std::vector<unsigned int> order;
    unsigned int score;  
    bool skip;                          // need this to know if player skipped turn               

    void initialize_player();
    void set_order(unsigned int);
    void turn();
    void process_turn();
    void end_turn(bool);
    void submit_card(unsigned int chosen_card);
    void calculate_score();
    int wait_for_input();
    void next_round();

public:
    Match();
    void start_match(unsigned int player_count);
    ~Match();
};

#endif