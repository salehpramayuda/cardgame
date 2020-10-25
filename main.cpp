#include "cardstack.hpp"
#include "handstack.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << "Let's start the game!\n";

    // Make deck
    Cardstack deck1;
    deck1.makeStack();

    // Make hand
    Handstack my_hand;
    int max_card = 5;
    for (int i = 0; i < max_card; i++) {
        my_hand.draw(deck1);
    }

    my_hand.list_card();
    return 0;
}