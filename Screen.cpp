//Created by Nu lar on 12/3/23.

#include "Screen.h"

Screen::Screen()
{
    game.generateFruit();

    start.setRadius(35);
    start.setText("Start");
    sn.setCharSize(15);
    start.setDefaultColor(sf::Color::Red);
    start.setPosition({200,300});

    quit.setRadius(35);
    quit.setText("Quit");
    sn.setCharSize(15);
    quit.setDefaultColor(sf::Color::Red);
    quit.setPosition({450, 300});

    sn.setRadius(0);
    sn.setText("Snake Game\n\nCS3A\nFINAL PROJECT");
    sn.setCharSize(30);
    sn.setPosition({300,100});
}

void Screen::draw(sf::RenderTarget &window, sf::RenderStates) const
{
    //window.draw(start);
    //window.draw(quit);
    window.draw(game);
}

void Screen::run() {
    ///no need

}

std::string Screen::getName() {
    return "Snake Game";
}

void Screen::update() {
    game.game_update();

}

void Screen::eventHandler(sf::RenderWindow &window, sf::Event event) {
///no need

}

void Screen::run(sf::RenderWindow &window) {
///no need

}

void Screen::insert_functionality(sf::RenderWindow& window)
{
    game.generateFruit();
    bool isMenu = true;
    while (isMenu)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (MouseEvent::isHovered(start.getCircle(), window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    isMenu = false;
                }
                else if (MouseEvent::isHovered(quit.getCircle(), window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    exit(0);
            }
        }
        window.clear();
        window.draw(start);
        window.draw(quit);// Draw the menu screen
        window.draw(sn);
        window.display();
    }
    ///might need
}

