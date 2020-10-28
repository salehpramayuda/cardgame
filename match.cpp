#include "match.hpp"

Match::Match() {}

void Match::start_match(unsigned int player_count) {
    deck.makeStack();

    for (int i = 0; i < player_count; i++) {
        initialize_player();
    };
    std::cout << players.size() << std::endl;
    current_player = 0;
    printf("Game has started \n");
    while (true) {
        process_turn();
    };
}

void Match::initialize_player() {
    Handstack *player = new Handstack;
    int max_card = 5;
    for (int i = 0; i < max_card; i++) {
        player->draw(deck);
    }
    players.push_back(player);
}

void Match::process_turn() {
    printf("\n");
    int input;
    input = wait_for_input();
    int hand_size = players[current_player]->get_hand_size();
    if (input <= hand_size) {
        submit_card(input);
        end_turn();
    } else {
        printf("Invalid input \n");
        process_turn();
    }
}

int Match::wait_for_input() {
    players[current_player]->list_card();
    std::string i;
    std::cout << "Which card do you want to play? ";
    std::cin >> i;
    return std::stoi(i);
}

void Match::submit_card(unsigned int chosen_card) {
    players[current_player]->submit_card(chosen_card, table_pile);
}

void Match::end_turn() {
    calculate_score();
    if (players.size() < current_player + 1) {
        current_player += 1;
    }
}

void Match::calculate_score() {
    if (players[current_player]->get_hand_size() == 0) {
        printf("\nYou won!");
        exit(0);
    }
}

Match::~Match() {}