//
// Created by Nu lar on 11/2/23.
//
#include "CardGraphics.h"
#include "image.h"
#include "LetterBox.h"

CardGraphics::CardGraphics()
        : CardGraphics(ACE, HEARTS)
{

}

CardGraphics::CardGraphics(const Card& card)
        : CardGraphics(card.getRank(), card.getSuit())
{

}

CardGraphics::CardGraphics(Rank rank, Suit suit)
        : CardGraphics(image::getImage(), rank, suit)       //can use static functions without creating objs
{

}

CardGraphics::CardGraphics(sf::Texture& image, Rank rank, Suit suit)
{
    sf::IntRect intRect;
    intRect.width = image.getSize().x/13;
    intRect.height = image.getSize().y/4;
    intRect.left = intRect.width*rank;
    intRect.top = intRect.height*suit;
    sprite.setTexture(image);
    sprite.setTextureRect(intRect);
}

CardGraphics::CardGraphics(Rank rank, Suit suit, sf::Vector2f position)
    : CardGraphics(rank, suit)
{
    setPosition(position);
}


void CardGraphics::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(sprite);
}

void CardGraphics::setPosition(sf::Vector2f position)
{
    sprite.setPosition({position.x,position.y});
}

