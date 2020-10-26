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
>>>>>>> 8129febd55fcd078e6a549c61e33792493d843f2

public:
    Handstack();
    void draw(Cardstack &);
    void throw_away(unsigned int, Cardstack &);
    void list_card();
    void insert(Card *);
};

#endif