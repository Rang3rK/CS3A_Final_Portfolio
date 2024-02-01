//
// Created by Nu lar on 11/1/23.
//
#include "Deck.h"

Deck::Deck()
{
    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int rank = ACE; rank <= KING; rank++) {
            deck.push_back(Card(static_cast<Rank>(rank), static_cast<Suit>(suit)));
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
    //use for loop to print the deck and its contents
    //return cards
    for(const Card& card : deck.deck)
    {
        out<<card<<std::endl;
    }
    return out;
}

//draw 1 card at a time
//cannot deal with DECK_SIZE being const
Card Deck::drawCard()
{
    shuffle();
    Card temp = deck.back();
    deck.pop_back();
    return temp;
}

// puts cards in random order
void Deck::shuffle()
{
    for(int i=0;i<deck.size();i++)
    {
        int j = rand() % deck.size();
        swap(deck[i], deck[j]);
    }
}

void Deck::swap(Card& card1, Card& card2)
{
    Card tmp = card1;
    card1 = card2;
    card2 = tmp;
}

bool Deck::empty()
{
    return deck.empty();
}
