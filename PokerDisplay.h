//
// Created by Nu lar on 12/7/23.

#ifndef SFMLMIDTERM_POKERDISPLAY_H
#define SFMLMIDTERM_POKERDISPLAY_H

#include "CardGraphics.h"
#include "LetterBox.h"
#include "scoreText.h"
#include "Project.h"

class PokerDisplay : public Project {
private:
    CardHand players[5];
    CardHandScorer scoreHand;
    CardGraphics cards[50] = {
            CardGraphics(ACE, SPADES),  //ROYAL
            CardGraphics(TEN, SPADES),
            CardGraphics(JACK, SPADES),
            CardGraphics(QUEEN, SPADES),
            CardGraphics(KING, SPADES),
            CardGraphics(TWO, SPADES),  //STRAIGHT FLUSH
            CardGraphics(THREE, SPADES),
            CardGraphics(FOUR, SPADES),
            CardGraphics(FIVE, SPADES),
            CardGraphics(SIX, SPADES),
            CardGraphics(TEN, SPADES),  //FOUR KIND
            CardGraphics(TEN, DIAMONDS),
            CardGraphics(TEN, CLUBS),
            CardGraphics(TEN, HEARTS),
            CardGraphics(THREE, SPADES),
            CardGraphics(ACE, SPADES),  //FULLHOUSE
            CardGraphics(ACE, CLUBS),
            CardGraphics(ACE, HEARTS),
            CardGraphics(KING, DIAMONDS),
            CardGraphics(KING, SPADES),
            CardGraphics(FIVE, SPADES),  //FLUSH
            CardGraphics(TWO, SPADES),
            CardGraphics(SIX, SPADES),
            CardGraphics(NINE, SPADES),
            CardGraphics(KING, SPADES),
            CardGraphics(SEVEN, SPADES),  //STRAIGHT
            CardGraphics(EIGHT, HEARTS),
            CardGraphics(NINE, DIAMONDS),
            CardGraphics(TEN, HEARTS),
            CardGraphics(JACK, SPADES),
            CardGraphics(QUEEN, HEARTS),  //THREE KIND
            CardGraphics(QUEEN, DIAMONDS),
            CardGraphics(QUEEN, CLUBS),
            CardGraphics(FIVE, HEARTS),
            CardGraphics(SEVEN, SPADES),
            CardGraphics(FOUR, DIAMONDS),  //TWO PAIR
            CardGraphics(FOUR, SPADES),
            CardGraphics(FOUR, HEARTS),
            CardGraphics(FOUR, CLUBS),
            CardGraphics(KING, SPADES),
            CardGraphics(ACE, SPADES),  //One Pair
            CardGraphics(ACE, CLUBS),
            CardGraphics(TWO, DIAMONDS),
            CardGraphics(NINE, HEARTS),
            CardGraphics(TEN, SPADES),
            CardGraphics(THREE, HEARTS),  //High
            CardGraphics(TEN, SPADES),
            CardGraphics(JACK, DIAMONDS),
            CardGraphics(SEVEN, CLUBS),
            CardGraphics(EIGHT, SPADES),
    };
public:
    PokerDisplay();

    void run(sf::RenderWindow& window) override;
    void run() override;

    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void insert_functionality(sf::RenderWindow& window) override;

    void update() override; //this is nothing
    std::string getName() override;
};


#endif //SFMLMIDTERM_POKERDISPLAY_H
