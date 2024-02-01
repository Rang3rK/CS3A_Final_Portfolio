//
// Created by Nu lar on 11/1/23.
//

#include "CardHand.h"

CardHand::CardHand()
{

}

Card& CardHand::addCard(Deck& deck)
{
    //for cards in playerhand
    //one card at a time
    Card temp = deck.drawCard();
    playerHand.push_back(temp);
    return playerHand.back();
}

const std::vector<Card>& CardHand::getCards() const
{
    return playerHand;
}

void CardHand::sortPlayerHand() {
    std::sort(playerHand.begin(), playerHand.end());
}

void CardHand::clearHand()
{
    playerHand.clear();
}