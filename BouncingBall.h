//
// Created by Nu lar on 12/7/23.
//

#ifndef BOUNCING_BOUNCINGBALL_H
#define BOUNCING_BOUNCINGBALL_H
#include "Ball.h"
#include "Project.h"

class BouncingBall : public Project {
private:

    Ball ball;

public:
    BouncingBall();
    void run(sf::RenderWindow& window) override;
    void run() override;

    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;

    void insert_functionality(sf::RenderWindow& window) override;
    void update() override; //this is nothing
    std::string getName() override;

};


#endif //BOUNCING_BOUNCINGBALL_H
