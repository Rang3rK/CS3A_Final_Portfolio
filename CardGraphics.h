//
// Created by Nu lar on 11/2/23.
//
#ifndef SFMLMIDTERM_CARDGRAPHICS_H
#define SFMLMIDTERM_CARDGRAPHICS_H
#include "CardHandScorer.h"

#include <SFML/Graphics.hpp>

class CardGraphics : public sf::Drawable
{
private:
    sf::Sprite sprite;
public:
    CardGraphics();
    CardGraphics(const Card& card);

    CardGraphics(Rank rank, Suit suit);
    CardGraphics(sf::Texture& image, Rank rank, Suit suit);
    CardGraphics(Rank rank, Suit suit, sf::Vector2f position);

    void setPosition(sf::Vector2f position);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif //SFMLMIDTERM_CARDGRAPHICS_H
