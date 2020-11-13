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

// // FAILED ATTEMPT
// void Renderer::assignRenderPriority(Card &card) {
//     std::vector<Card *>::iterator it;
//     // Should only compare the front and back
//     it = hand.begin() + card_index - 1;
//     while (it <= hand.begin() + card_index + 2) {
//         int card_reference_index = std::distance(hand.begin(), it);
//         std::cout << card_reference_index << std::endl;
//         if (card_reference_index <= hand.size() - 1) {
//             std::cout << card_reference_index << std::endl;
//             bool ypos_higher = (card.position.y < (*it)->position.y);
//             bool index_higher = (card_reference_index > card_index);
//             if (ypos_higher && index_higher) {
//                 std::swap((*it), hand[card_index]);
//                 card_index = card_reference_index;
//                 std::cout << "Chosen card moved FRONT" << std::endl;
//             } else if (!ypos_higher && !index_higher) {
//                 std::swap((*it), hand[card_index]);
//                 card_index = card_reference_index;
//                 std::cout << "Chosen card moved BACK" << std::endl;
//             }
//             it += 2;
//         }
//         std::cout << " " << std::endl;
//     }
// }

void Renderer::assignRenderPriority(Card &card) {
    std::vector<Card *>::iterator it;
    int i = 0;
    for (it = hand.begin(); it != hand.end(); it++) {
        int card_reference_index = std::distance(hand.begin(), it);
        bool higher_y = (card.position.y < (*it)->position.y);
        bool same_y = (card.position.y == (*it)->position.y);
        bool higher_index = (card_reference_index > card_index);
        if (higher_y && higher_index) {
            std::swap((*it), hand[card_index]);
            card_index = card_reference_index;
        } else if (!higher_y && !higher_index && !same_y) {
            std::swap((*it), hand[card_index]);
            card_index = card_reference_index;
        }
    }
};