#ifndef MATCH_HPP
#define MATCH_HPP
#include "card.hpp"
#include "cardstack.hpp"
#include "handstack.hpp"
#include <iostream>

class Match {
private:
    std::vector<Handstack *> players; // Vector for easy call by index
    Cardstack deck;
    Cardstack table_pile;
    unsigned int current_player;
    unsigned int score;

    void initialize_player();
    void process_turn();
    void end_turn();
    void submit_card(unsigned int chosen_card);
    void calculate_score();
    int wait_for_input();

public:
    Match();
    void start_match(unsigned int player_count);
    ~Match();
};

#endif