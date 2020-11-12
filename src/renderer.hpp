#pragma once
#include "card.hpp"
#include "text.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Renderer {
public:
    Renderer(std::vector<Card *> &vector);
    ~Renderer();
    void renderCards();
    void pollEvents(SDL_Event &event);

private:
    std::vector<Card *> hand;
    int card_index;

private:
    void assignRenderPriority(Card &card);
};