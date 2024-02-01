//
// Created by Nu lar on 12/4/23.
//

#ifndef FINALPORTFOLIO_PORTFOLIO_H
#define FINALPORTFOLIO_PORTFOLIO_H
#include "Project.h"
#include "EventHandlerable.h"
#include "Updateable.h"
#include "Runable.h"
#include "Nameable.h"
#include "Button.h"

#include <vector>
#include <iostream>

///similar to
class Portfolio : public sf::Drawable {
private:
    Button left, right;
    std::vector<Project*>project;
    std::vector<Project*>::iterator iter;
    void menu();
    sf::Text portfolio_text;
public:
    Portfolio();

    void drawproject(Drawable& drawable, sf::RenderWindow window);
    void load(Project& programs);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void run();
    void update();
    std::string getName(Nameable& nameable);

    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
};


#endif //FINALPORTFOLIO_PORTFOLIO_H
