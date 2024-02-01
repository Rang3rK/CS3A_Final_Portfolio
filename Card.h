//
// Created by Nu lar on 11/1/23.
//

#ifndef SFMLMIDTERM_CARD_H
#define SFMLMIDTERM_CARD_H

#include<iostream>
#include "Rank.h"
#include "Suit.h"

class Card {
private:
    Suit suit;
    Rank rank;
public:
    Card();
    Card(Rank rank, Suit suit);

    std::string rankToString() const;
    std::string suitToString() const;

    const Suit& getSuit() const;
    const Rank& getRank() const;
    void setSuit(Suit suit);
    void setRank(Rank rank);


    friend std::ostream& operator<<(std::ostream& out, const Card& card);
    friend bool operator==(const Card& card1, const Card& card2);
    friend bool operator!=(const Card& card1, const Card& card2);
    friend bool operator <(const Card& card1, const Card& card2);
    friend bool operator >(const Card& card1, const Card& card2);
    Card operator++(int);

};

#endif //SFMLMIDTERM_CARD_H
