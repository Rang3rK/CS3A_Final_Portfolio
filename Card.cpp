//
// Created by Nu lar on 11/1/23.
//

#include "Card.h"

Card::Card()
{

}

Card::Card(Rank rank, Suit suit)
        : rank(rank), suit(suit)
{

}

//friend function
std::ostream& operator<<(std::ostream& out, const Card& card)
{
    return out<<card.rankToString()<<" of "<<card.suitToString();
}

bool operator==(const Card& card1, const Card& card2)
{
    return ((card1.rank == card2.rank));
}

bool operator!=(const Card& card1, const Card& card2)
{
    return !operator==(card1,card2);
}

bool operator <(const Card& card1, const Card& card2)
{
    return card1.rank < card2.rank;
}

bool operator >(const Card& card1, const Card& card2)
{
    return card1.rank > card2.rank;
}



Card Card::operator++(int)
{
    this->rank = static_cast<Rank>((rank+1) % (KING +1));
    return *this;
}

const Suit& Card::getSuit() const
{
    return suit;
}

const Rank& Card::getRank() const
{
    return rank;
}

void Card::setSuit(Suit suit)
{
    this->suit = suit;
}

void Card::setRank(Rank rank)
{
    this->rank = rank;
}

/*int Card::getRankValue() const
{
    if(rank < TEN)
        return rank + 1;
    else return 10;
}*/

std::string Card::rankToString() const{
    switch(rank)
    {
        case ACE: return "Ace";
        case TWO: return "Two";
        case THREE: return "Three";
        case FOUR: return "Four";
        case FIVE: return "Five";
        case SIX: return "Six";
        case SEVEN: return "Seven";
        case EIGHT: return "Eight";
        case NINE: return "Nine";
        case TEN: return "Ten";
        case JACK: return "Jack";
        case QUEEN: return "Queen";
        case KING: return "King";
        default: return "INVALID";
    }
}

std::string Card::suitToString() const
{
    switch(suit)
    {
        case HEARTS: return "Hearts";
        case CLUBS: return "Clubs";
        case DIAMONDS: return "Diamonds";
        case SPADES: return "Spades";
        default : return "INVALID";
    }
}
