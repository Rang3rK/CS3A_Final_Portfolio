//////
////// Created by Nu lar on 12/8/23.
//////

#ifndef FINALPORTFOLIO_PROGRAMCAL_H
#define FINALPORTFOLIO_PROGRAMCAL_H
#include <SFML/Graphics.hpp>
#include "Calculator.h"
#include "Project.h"

class ProgramCal : public Project {
private:
    Calculator cal;
public:
    ProgramCal();
    void run(sf::RenderWindow& window) override;
    void run() override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void insert_functionality(sf::RenderWindow& window) override;
    void update() override; //this is nothing
    std::string getName() override;
};


#endif //FINALPORTFOLIO_PROGRAMCAL_H
