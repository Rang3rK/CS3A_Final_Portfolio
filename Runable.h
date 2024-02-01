//
// Created by Nu lar on 11/28/23.

#ifndef PORTFOLIO_RUNABLE_H
#define PORTFOLIO_RUNABLE_H
#include <SFML/Graphics.hpp>
//similar to measurable class
//pure virtual class

class Runable
{
public:
    virtual void insert_functionality(sf::RenderWindow& window)=0;
    virtual void run(sf::RenderWindow& window)=0;
    virtual void run()=0;
};

#endif //PORTFOLIO_RUNABLE_H
