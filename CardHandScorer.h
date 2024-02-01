//
// Created by Nu lar on 11/1/23.
//

#ifndef SFMLMIDTERM_CARDHANDSCORER_H
#define SFMLMIDTERM_CARDHANDSCORER_H


#include "CardHand.h"
#include "ScoreCard.h"
#include <algorithm>

class CardHandScorer {
private:
    //static int numDup, numUnique;
    //int numDup, numUnique;

    static int numDup, numUnique;

public:
    CardHand cardHand;
    CardHandScorer();
    CardHandScorer(CardHand cardHand);

    void num_of_Dup(const CardHand& player);
    void num_of_Unique(const CardHand& player);
    const int& getNumDup() const;
    const int& getNumUnique() const;

    void scoreCardHand(CardHand& cardHand);

    void printHand(const CardHand& player);

    static bool isSameSuit(CardHand& cardHand);
    static bool isSequential(CardHand& cardHand);

    static bool isRoyalFlush(CardHand& cardHand);
    static bool isStraightFlush(CardHand& cardHand);
    static bool isFourKind();
    static bool isFullHouse();
    static bool isFlush(CardHand& cardHand);
    static bool isStraight(CardHand& cardHand);
    static bool ThreeKind();
    static bool TwoPair();
    static bool OnePair();

//    std::vector<Card>getCardHand() const;

};


#endif //SFMLMIDTERM_CARDHANDSCORER_H
