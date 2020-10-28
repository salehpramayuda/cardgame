#ifndef HANDSTACK_HPP
#define HANDSTACK_HPP
#include "cardstack.hpp"
#include <vector>

<<<<<<< HEAD
class Handstack{
    private:
        std::vector<Card*> hand;
    public:
        Handstack();
        void draw(Cardstack&);
        void throw_away(unsigned int, Cardstack&);
        void list_card();
        void insert(Card*);
        ~Handstack();
=======
class Handstack {
private:
    std::vector<Card *> hand;

public:
    Handstack();
    void draw(Cardstack &);
    void submit_card(unsigned int, Cardstack &);
    void throw_away(unsigned int, Cardstack &);
    void list_card();
    void insert(Card *);
    int get_hand_size();
>>>>>>> ad768c473a9e3af92a3901d11296660762df359b
};

#endif
