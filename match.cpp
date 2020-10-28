#include "match.hpp"

Match::Match() {}

void Match::start_match(unsigned int player_count) {
    deck.makeStack();

    for (int i = 0; i < player_count; i++) {
        initialize_player();
    };
    current_player = 0;
    set_order(current_player);
    printf("Game has started \n");
    bool game = true;
    while (game) {
        turn();
    };
}

void Match::set_order(unsigned int number){
    if(!order.empty()){
        int size = order.size();
        for(int i=0; i<size; i++){
            order.erase(order.begin());
        }
    }
    int i = number;
    for(i; i< players.size(); i++){
        order.push_back(i);
    }
    for(int j = 0; j<number; j++){
        order.push_back(j);
    }
}

void Match::initialize_player() {
    Handstack *player = new Handstack;
    int max_card = 5;
    for (int i = 0; i < max_card; i++) {
        player->draw(deck);
    }
    players.push_back(player);
}

void Match::turn(){                 // separated from process_turn
    process_turn();     // will always be called until input has been safely made
    end_turn(skip);                    // player decided to skip
}

void Match::process_turn() {
    printf("\n");
    std::cout << "Player " << order[current_player] << "'s Turn:" << std::endl;
    int input;
    input = wait_for_input();
    int hand_size = players[order[current_player]]->get_hand_size();
    if (input < hand_size+2) {
        if(input < hand_size){
            skip = false;
            submit_card(input);
        }
        else{
            if(input == hand_size){
                players[order[current_player]]->draw(deck);
                process_turn();
            }
            else{
                std::cout<<"You passed your turn!"<<std::endl;
                skip = true;
            } 
        }
    } else {
        printf("Invalid input \n");
        process_turn();
    }
}

int Match::wait_for_input() {
    players[order[current_player]]->list_card();
    std::cout << players[order[current_player]]->get_hand_size()<< ": Draw from deck" << std::endl;
    std::cout << players[order[current_player]]->get_hand_size()+1<< ": Pass your turn" << std::endl;
    std::string i;
    std::cout << "Which card do you want to play? ";
    std::cin >> i;
    return std::stoi(i);
}

void Match::submit_card(unsigned int chosen_card) {
    if(!players[order[current_player]]->submit_card(chosen_card, table_pile)){
        process_turn();
    }
}

void Match::end_turn(bool skip) {
    if(!skip){
        calculate_score();
        table_pile.set_winner(order[current_player]);
    }
    if (players.size() > current_player+1) {
        current_player += 1;
    }
    else{
        next_round();
    }
}

void Match::calculate_score() {
    if (players[order[current_player]]->get_hand_size() == 0) {
        printf("\nYou won!");
        exit(0);
    }
}

void Match::next_round(){
    current_player = 0;
    unsigned int winner = table_pile.reset_pile();
    std::cout << "Winner of this round is Player " << winner <<"!\n";
    std::cout << "Player " << winner << " will start first in the next round\n\n";
    set_order(winner);
    std::cout << "Next Round!\n";
}

Match::~Match() {}