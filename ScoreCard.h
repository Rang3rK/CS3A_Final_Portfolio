//
// Created by Nu lar on 11/2/23.
//

#ifndef SFMLMIDTERM_SCORECARD_H
#define SFMLMIDTERM_SCORECARD_H

#include<vector>
#include<iostream>
//#include <SFML/Graphics.hpp>

enum Scores
{
    ROYAL_FLUSH, STRAIGHT_FLUSH, FOUR_OF_A_KIND, FULL_HOUSE, FLUSH, STRAIGHT, THREE_OF_A_KIND, TWO_PAIR, ONE_PAIR, HIGH_CARD
};

class ScoreCard {
private:
    static std::vector<int>scoresV;
public:
    ScoreCard();

    static void addScore(Scores score);
    static void print();
    static int getScoresV(Scores score);
    static bool isRoyalFlush();

    //ScoreCard& operator+=(const Scores& score);
    Scores operator[](unsigned int index) const;
};

#endif //SFMLMIDTERM_SCORECARD_H
