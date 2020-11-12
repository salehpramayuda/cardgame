#include "arena.hpp"

Arena::Arena(){};

void Arena::spawnCards(int amount) {
    Vector2 pos = {100, 200};
    Vector2 increment = {10, 6};
    std::string path = "res/clover/card_1_clover.png";
    for (int i = 0; i <= amount; i++) {
        Rect *card = new Rect(pos.x, pos.y, 0, 0, path);
        hand.insert(hand.begin(), card);
        pos += increment;
        std::cout << pos.x << " & " << pos.y << std::endl;
    }
}

void Arena::renderCards() {
    std::vector<Rect *>::iterator it;
    for (it = hand.begin(); it != hand.end(); it++) {
        (*it)->draw();
    }
}

void Arena::pollEvents(SDL_Event &event) {
    if (card_index != -1) {
        assignRenderPriority(*hand[card_index]);
        if (!hand[card_index]->pollEvents(event)) {
            card_index = -1;
        }
    } else {
        std::vector<Rect *>::reverse_iterator it;
        for (it = hand.rbegin(); it != hand.rend(); it++) {
            if ((*it)->pollEvents(event)) {
                card_index = hand.size() - 1 - std::distance(hand.rbegin(), it);
                break;
            }
        }
    }
}

Arena::~Arena() {
    std::vector<Rect *>::iterator it;
    for (it = hand.begin(); it != hand.end(); it++) {
        (*it)->~Rect();
    }
}

void Arena::assignRenderPriority(Rect &card) {
    std::vector<Rect *>::iterator it;
    int i = 0;
    for (it = hand.begin(); it != hand.end(); it++) {
        int card_reference_index = std::distance(hand.begin(), it);
        bool higher_y = (card.position.y < (*it)->position.y);
        bool higher_index = (card_reference_index > card_index);
        if (higher_y && higher_index) {
            std::swap((*it), hand[card_index]);
            card_index = card_reference_index;
        } else if (!higher_y && !higher_index) {
            std::swap((*it), hand[card_index]);
            card_index = card_reference_index;
        }
    }
    std::cout << " " << std::endl;
};