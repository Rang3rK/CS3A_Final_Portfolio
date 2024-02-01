//
// Created by Nu lar on 11/2/23.
//

#include "ScoreCard.h"

std::vector<int> ScoreCard::scoresV(10);

ScoreCard::ScoreCard()
{

}

void ScoreCard::addScore(Scores score) {
    scoresV[score]++;
}

/*
ScoreCard& ScoreCard::operator+=(const Scores& score)
{
    return *this;
}
*/

Scores ScoreCard::operator[](unsigned int index) const {
    return static_cast<Scores>(scoresV[index]);
}

void ScoreCard::print()
{
    std::cout<<"Royal : "<< scoresV[ROYAL_FLUSH] <<std::endl;
    std::cout<<"Straight flush : "<< scoresV[STRAIGHT_FLUSH] <<std::endl;
    std::cout<<"Flush : "<< scoresV[FLUSH] <<std::endl;
    std::cout<<"Straight : "<< scoresV[STRAIGHT] <<std::endl;
    std::cout<<"FullHouse: "<<scoresV[FULL_HOUSE]<<std::endl;
    std::cout<<"Four kind : "<< scoresV[FOUR_OF_A_KIND] <<std::endl;
    std::cout<<"Three kind : "<< scoresV[THREE_OF_A_KIND] <<std::endl;
    std::cout<<"Two Pair : "<< scoresV[TWO_PAIR] <<std::endl;
    std::cout<<"One Pair : "<< scoresV[ONE_PAIR] <<std::endl;
    std::cout<<"High : "<< scoresV[HIGH_CARD] <<std::endl;
}

int ScoreCard::getScoresV(Scores score)
{
    return scoresV[static_cast<int>(score)];
    //return scoresV[score];
}


bool ScoreCard::isRoyalFlush()
{
    return (scoresV[ROYAL_FLUSH] > 0);
}
