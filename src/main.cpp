#include "match.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    cout << "Let's start the game!\n";
    int player_amount = 1;

    Match game;
    game.start_match(player_amount);

    return 0;
}
