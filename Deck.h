//
// Created by Nu lar on 11/1/23.
//

#ifndef SFMLMIDTERM_DECK_H
#define SFMLMIDTERM_DECK_H
#include <vector>
#include "Card.h"

class Deck {
private:
    // const int DECK_SIZE = 52;
    std::vector<Card>deck;  //deck is array of Cards

public:
    Deck(); //default constructor
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck); //print all cards to console

    Card drawCard();
    void shuffle(); // puts cards in random order
    bool empty();
    static void swap(Card& card1, Card& card2);


};

#endif //SFMLMIDTERM_DECK_H
