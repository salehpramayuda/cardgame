#include "cardstack.hpp"

Cardstack::Cardstack() {} //creates an empty cardstack

void Cardstack::makeStack(Vector2 pos) {
    //generate all 52 Cards and ensure that no cards can be the same
    Vector2 deviation = {40, 30};
    pos = pos / 2 - deviation;
    std::string path;
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 14; j++) {
            path = generateCardPath(i, j);
            Card *temp = new Card(i, j, pos.x, pos.y, path);
            stack.insert(stack.begin(), temp);
            // pos += 10;
        }
    }
    shuffleStack();
}

void Cardstack::shuffleStack() {
    // RENDER ORDER NOT KEPT
    int p = rand() % 9;
    srand(time(NULL));
    while (p != 0) {
        for (int i = 0; i <= 52; i++) {
            int index1 = rand() % 52;
            int index2 = rand() % 52;
            std::swap(stack[index1], stack[index2]);

            // Card *card1 = stack[index1];
            // Card *card2 = stack[index2];
            // Vector2 card1_pos = card1->position;
            // card1->moveRect(card2->position);
            // card2->moveRect(card1_pos);
        }
        p--;
    }
}

void Cardstack::insert(Card *toInsert) {
    this->stack.insert(stack.begin(), toInsert);
}

Card *Cardstack::show_top() {
    return this->stack.front();
}

Card *Cardstack::drawn() {
    Card *temp = this->stack.front();
    this->stack.erase(stack.begin());
    return temp;
}

unsigned int Cardstack::get_size() {
    return stack.size();
}

Cardstack::~Cardstack() {
    std::vector<Card *>::iterator it = stack.begin();
    for (it; it != stack.end(); it++) {
        (*it)->~Card();
    }
    std::cout << "You have witness a Stack of Card get burned" << std::endl
              << std::endl;
}

std::string Cardstack::generateCardPath(int kd, int nr) {
    std::map<int, std::string> kingdom_names = {
        {1, "clover"},
        {2, "diamond"},
        {3, "heart"},
        {4, "spade"},
    };
    std::stringstream ss;
    ss << "res/" << kingdom_names[kd] << "/card_"
       << nr
       << "_" << kingdom_names[kd] << ".png";
    return ss.str();
}