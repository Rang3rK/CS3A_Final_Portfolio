//
// Created by Nu lar on 12/7/23.
//

#include "BouncingBall.h"

BouncingBall::BouncingBall()
//    : ball({200,200})
{
    ball.setRadius(50);
}


void BouncingBall::run(sf::RenderWindow& window)
{

    ball.setBounds(window.getSize().x,window.getSize().y);
}

std::string BouncingBall::getName()
{
    return "Bouncing Ball";
}

void BouncingBall::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(ball);
}

void BouncingBall::eventHandler(sf::RenderWindow& window, sf::Event event)
{

}

void BouncingBall::update()
{
    ball.bounce();

}

void BouncingBall::run() {

}

void BouncingBall::insert_functionality(sf::RenderWindow& window) {

}
