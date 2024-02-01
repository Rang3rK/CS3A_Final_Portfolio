//
// Created by Nu lar on 11/2/23.
//

#include "scoreText.h"

//important to declare static member variables, otherwise will end up linker error***
std::vector<std::string>scoreText::storeScores;

scoreText::scoreText()
    : scoreText("ROYAL_FLUSH")
{

}

scoreText::scoreText(const std::string& str)
    : scoreText("ROYAL_FLUSH", {10.f,10.f})
{

}

scoreText::scoreText(const std::string& str, sf::Vector2f position)
{
    font.loadFromFile("Font/OpenSans-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(position);
    text.setString(str);
}

void scoreText::calculate()
{
    for(int i = ROYAL_FLUSH; i <= HIGH_CARD; i++)
    {
        int final = ScoreCard::getScoresV(static_cast<Scores>(HIGH_CARD))/ScoreCard::getScoresV(static_cast<Scores>(i));
        storeScores.push_back(std::to_string(final) + " : 1");
    }
    for (const std::string& score : storeScores)
    {
        std::cout << score << std::endl;
    }
}


void scoreText::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(text,states);
}


