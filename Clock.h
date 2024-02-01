//
// Created by Nu lar on 12/6/23.
//

#ifndef SFMLCLOCK_CLOCK_H
#define SFMLCLOCK_CLOCK_H
#include <SFML/Graphics.hpp>
#include "Project.h"

class Clock : public Project
{
private:
    sf::Clock clock;
    sf::CircleShape clockFace;
    sf::Text n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12;
    sf::RectangleShape hourHand, minuteHand, secondHand;
public:
    Clock();
    sf::RectangleShape createHand(sf::Vector2f size, sf::Vector2f position, sf::Vector2f origin, sf::Color color);
    sf::Text placeText(std::string& text, sf::Vector2f position);

    void run(sf::RenderWindow& window) override;
    void run() override;

    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;

    void insert_functionality(sf::RenderWindow& window) override;
    void update() override; //this is nothing
    std::string getName() override;

};


#endif //SFMLCLOCK_CLOCK_H
