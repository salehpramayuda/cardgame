#include "renderer.hpp"

Renderer::Renderer(std::vector<Card *> &vector) : hand(vector) {
    card_index = -1;
};

void Renderer::renderCards() {
    std::vector<Card *>::iterator it;
    for (it = hand.begin(); it != hand.end(); it++) {
        (*it)->draw();
    }
}

void Renderer::pollEvents(SDL_Event &event) {
    if (card_index != -1) {
        assignRenderPriority(*hand[card_index]);
        if (!hand[card_index]->pollEvents(event)) {
            card_index = -1;
        }
    } else {
        std::vector<Card *>::reverse_iterator it;
        for (it = hand.rbegin(); it != hand.rend(); it++) {
            if ((*it)->pollEvents(event)) {
                card_index = hand.size() - 1 - std::distance(hand.rbegin(), it);
                break;
            }
        }
    }
}

Renderer::~Renderer() {
    std::vector<Card *>::iterator it;
    for (it = hand.begin(); it != hand.end(); it++) {
        (*it)->~Card();
    }
}

void Renderer::assignRenderPriority(Card &card) {
    std::vector<Card *>::iterator it;
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
};