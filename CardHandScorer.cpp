//
// Created by Nu lar on 11/1/23.
//

#include "CardHandScorer.h"

//to use static function, need to redeclare static variables
int CardHandScorer::numUnique;
int CardHandScorer::numDup;

CardHandScorer::CardHandScorer()
{
}


void CardHandScorer::scoreCardHand(CardHand& cardHand)
{

    num_of_Dup(cardHand);
    num_of_Unique(cardHand);

    if(isRoyalFlush(cardHand))
    {
        ScoreCard::addScore(ROYAL_FLUSH);
        ScoreCard::addScore(STRAIGHT_FLUSH);
        ScoreCard::addScore(HIGH_CARD);
    }
    else if (isStraightFlush(cardHand))
    {
        ScoreCard::addScore(STRAIGHT_FLUSH);
        ScoreCard::addScore(FLUSH);
        ScoreCard::addScore(HIGH_CARD);

    }
    else if(isFourKind())
    {
        ScoreCard::addScore(FOUR_OF_A_KIND);
        ScoreCard::addScore(THREE_OF_A_KIND);
        ScoreCard::addScore(TWO_PAIR);
        ScoreCard::addScore(ONE_PAIR);
        ScoreCard::addScore(HIGH_CARD);

    }
    else if (isFullHouse())
    {
        ScoreCard::addScore(FULL_HOUSE);
        ScoreCard::addScore(THREE_OF_A_KIND);
        ScoreCard::addScore(HIGH_CARD);

    }
    else if (isFlush(cardHand))
    {
        ScoreCard::addScore(FLUSH);
        ScoreCard::addScore(HIGH_CARD);

    }
    else if (isStraight(cardHand))
    {
        ScoreCard::addScore(STRAIGHT);
        ScoreCard::addScore(HIGH_CARD);

    }
    else if (ThreeKind())
    {
        ScoreCard::addScore(THREE_OF_A_KIND);
        ScoreCard::addScore(ONE_PAIR);
        ScoreCard::addScore(HIGH_CARD);

    }
    else if (TwoPair())
    {
        ScoreCard::addScore(TWO_PAIR);
        ScoreCard::addScore(ONE_PAIR);
        ScoreCard::addScore(HIGH_CARD);
    }
    else if (OnePair())
    {
        ScoreCard::addScore(ONE_PAIR);
        ScoreCard::addScore(HIGH_CARD);
    }
    else
        ScoreCard::addScore(HIGH_CARD);
}

void CardHandScorer::num_of_Unique(const CardHand& player)
{
    std::vector<Card> cards = player.getCards();
    std::sort(cards.begin(), cards.end());
    numUnique = 0;
    int numCards = cards.size();
    for(int i=0;i < numCards; i++)
    {
        bool isUnique = true;

        for(int j=i+1; j < numCards; j++)
        {
            if((i != j) && (cards[i].getRank() == cards[j].getRank())) {
                //std::cout<<"it is unique: "<<numUnique<<std::endl;
                isUnique =false;
                break;
            }
        }
        if(isUnique) {
            numUnique++;
            //std::cout<<"Num of Unique :"<<numUnique<<std::endl;
        }
    }
}


void CardHandScorer::num_of_Dup(const CardHand& player)
{
    numDup = 0;
    int count = 1;
    std::vector<Card> cards = player.getCards();

    std::sort(cards.begin(), cards.end());
    Card& prev = cards.front();

    for (int i = 1; i < cards.size(); i++) {
        if(prev.getRank() == cards[i].getRank())
        {
            count++;
        }
        if(count > numDup)
        {
            numDup = count;
        }
        else
        {
            count = 1;
        }
        prev = cards[i];
    }
}

const int& CardHandScorer::getNumDup() const
{
    return numDup;
}

const int& CardHandScorer::getNumUnique() const
{
    return numUnique;
}

void CardHandScorer::printHand(const CardHand& player)
{
    const std::vector<Card> cards = player.getCards();
    for(const Card& card : cards)
    {
        std::cout<<card<<std::endl;
    }
}

bool CardHandScorer::isSameSuit(CardHand& cardHand)
{
    std::vector<Card> cards = cardHand.getCards();
    for(int i=0; i< cards.size(); i++)
    {
        if(cards[i].getSuit() != cards[i+1].getSuit())
            return false;
    }
    return true;
}

bool CardHandScorer::isSequential(CardHand& cardHand)
{
    std::vector<Card> cards =  cardHand.getCards();
    for(int i=0; i< cards.size(); i++)
    {
        if(cards[i].getRank() >= cards[i + 1].getRank())
            return false;
    }
    return true;
}

bool CardHandScorer::isRoyalFlush(CardHand& cardHand)
{
    return ((numUnique == 5) && (numDup==1) && isSequential(cardHand) && isSameSuit(cardHand) && (cardHand.getCards().front().getRank() == ACE) && (cardHand.getCards().back().getRank() == KING));
}

bool CardHandScorer::isStraightFlush(CardHand& cardHand)
{
    if(isSequential(cardHand) && isSameSuit(cardHand))
        return true;
    return false;
}

bool CardHandScorer::isFourKind()
{
    if((numUnique == 2) && (numDup == 4))
    {
        return true;
    }
    return false;
}

bool CardHandScorer::isFullHouse()
{
    if((numUnique == 2) && (numDup == 3))
    {
        return true;
    }
    return false;
}

bool CardHandScorer::isFlush(CardHand& cardHand)
{
    if((numUnique == 5) && !isSequential(cardHand) && isSameSuit(cardHand))
    {
        return true;
    }
    return false;
}

bool CardHandScorer::isStraight(CardHand& cardHand)
{
    if(isSequential(cardHand) && !isSameSuit(cardHand))
        return true;
    return false;
}

bool CardHandScorer::ThreeKind()
{
    if((numUnique == 3) && (numDup == 3))
        return true;
    return false;
}

bool CardHandScorer::TwoPair()
{
    if((numUnique == 3) && (numDup == 2))
        return true;
    return false;
}

bool CardHandScorer::OnePair()
{
    if((numDup == 2) && (numUnique == 4))
        return true;
    return false;
}

//std::vector<Card> CardHandScorer::getCardHand() const {
////    std::vector<Card> cards =  cardHand.getCards();
////    return cards;
//}

