
 //Created by Nu lar on 12/3/23.


#ifndef SNAKEGAME_SCREEN_H
#define SNAKEGAME_SCREEN_H
#include<SFML/Graphics.hpp>
#include "SnakeGame.h"
#include "Button.h"
#include "Project.h"

class Screen : public Project
{
private:
    Button start, quit, sn;
    SnakeGame game;
    sf::Text text_score;
    int score=0;
public:
    Screen();

    void setText(const std::string& text);
    void run(sf::RenderWindow& window) override;
    void run() override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;

    void insert_functionality(sf::RenderWindow& window) override;
    void update() override; //this is nothing
    std::string getName() override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
};


#endif //SNAKEGAME_SCREEN_H
