#pragma once
#include "rect.hpp"
#include "text.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Arena {
public:
    Arena();
    ~Arena();
    void spawnCards(int amount);
    void renderCards();
    void pollEvents(SDL_Event &event);

    std::vector<Rect *> hand;

private:
    int card_index;

private:
    void assignRenderPriority(Rect &card);
};