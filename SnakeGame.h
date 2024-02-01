//
// Created by Nu lar on 11/18/23.
//

#ifndef SNAKEGAME_SNAKEGAME_H
#define SNAKEGAME_SNAKEGAME_H

#include "SnakeFunction.h"
#include "Snake.h"
#include "Fruit.h"

#include <iostream>
#include <SFML/Graphics.hpp>

class SnakeGame : public SnakeFunction
{
private:
    SnakeFunction snakef;
    std::vector<Fruit> fruits;

    sf::Text text_score;
    int score=0;
    sf::Font font;
public:

    SnakeGame();
    void game_update();
    void generateFruit();
    void checkFruitCollision(std::vector<Fruit>& fruits);
    int x_coord;
    int y_coord;

    void setText(const std::string& text);
    int getScore();

    sf::Text getString();

    bool gamecheck();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

};


#endif //SNAKEGAME_SNAKEGAME_H
