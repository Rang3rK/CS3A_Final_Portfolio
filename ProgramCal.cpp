////
//// Created by Nu lar on 12/8/23.
////

#include "ProgramCal.h"

ProgramCal::ProgramCal()
{

}


void ProgramCal::eventHandler(sf::RenderWindow& window, sf::Event event)
{
    cal.eventHandler(window,event);
}

void ProgramCal::update()
{
    cal.update();
}


void ProgramCal::run(sf::RenderWindow &window)
{

}

void ProgramCal::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(cal);
}


std::string ProgramCal::getName()
{
    return "Calculator";
}

void ProgramCal::insert_functionality(sf::RenderWindow& window) {

}

void ProgramCal::run() {

}
