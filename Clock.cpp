//
// Created by Nu lar on 12/6/23.
//

#include "Clock.h"

Clock::Clock()
{

}


sf::RectangleShape Clock::createHand(sf::Vector2f size, sf::Vector2f position, sf::Vector2f origin ,sf::Color color)
{
    sf::RectangleShape hand;
    hand.setSize(size);
    hand.setFillColor(color);
    hand.setPosition(position);
    hand.setOrigin(origin);
    return hand;
}

sf::Text Clock::placeText(std::string& text, sf::Vector2f position)
{
    sf::Text t;
    t.setPosition(position);
    t.setCharacterSize(30);
    t.setFillColor(sf::Color::Red);
    t.setStyle(sf::Text::Bold);
    return t;
}

void Clock::run(sf::RenderWindow &window) {
    clockFace.setRadius(window.getSize().y/2);
    clockFace.setPosition(window.getSize().x/2, window.getSize().y/2);
    clockFace.setOrigin(clockFace.getRadius(),clockFace.getRadius());

    hourHand = createHand({clockFace.getRadius() * .3f, 5.f}, clockFace.getPosition(), {0.f,0.f},sf::Color::Black);
    minuteHand = createHand({clockFace.getRadius() * .6f, 4.f}, clockFace.getPosition(), {0.f,0.f}, sf::Color::Black);
    secondHand = createHand({clockFace.getRadius() * .7f, 3.f}, clockFace.getPosition(), {0.f,0.f}, sf::Color::Red);

}

void Clock::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(clockFace);
    window.draw(n1);
    window.draw(hourHand);
    window.draw(minuteHand);
    window.draw(secondHand);
}

void Clock::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

std::string Clock::getName() {
    return "Clock";
}

void Clock::update() {
    hourHand.rotate(0.0083333333);
    minuteHand.rotate(0.01);
    secondHand.rotate(0.06);
}

void Clock::run()
{

}

void Clock::insert_functionality(sf::RenderWindow& window) {

}
