//
// Created by Nu lar on 12/7/23.
//

#include "GreenCircle.h"

GreenCircle::GreenCircle()
    :   shape(300.f)
{
    shape.setFillColor(sf::Color(100, 250, 50));

}

void GreenCircle::run(sf::RenderWindow& window)
{

}


void GreenCircle::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    //draw each proj
    //sf::CircleShape shape(300.f);
    window.draw(shape);
}

void GreenCircle::update()
{

}

void GreenCircle::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

std::string GreenCircle::getName() {
    return "Green Circle";
}

void GreenCircle::run() {

}

void GreenCircle::insert_functionality(sf::RenderWindow& window) {

}
