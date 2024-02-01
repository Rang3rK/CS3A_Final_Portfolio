//
// Created by Nu lar on 12/7/23.
//

#ifndef FINALPORTFOLIO_GREENCIRCLE_H
#define FINALPORTFOLIO_GREENCIRCLE_H
#include "Project.h"

//deleted sf::Drawable
class GreenCircle : public Project {
private:
    sf::CircleShape shape;
public:

    GreenCircle(); ///green circle
    void run(sf::RenderWindow& window) override;
    void run() override;
    void insert_functionality(sf::RenderWindow& window) override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;


    void update() override; //this is nothing
    std::string getName() override;
};


#endif //FINALPORTFOLIO_GREENCIRCLE_H
