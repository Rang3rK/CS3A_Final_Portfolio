//
// Created by Nu lar on 11/2/23.
//

#ifndef SFMLMIDTERM_SCORETEXT_H
#define SFMLMIDTERM_SCORETEXT_H
#include <SFML/Graphics.hpp>
#include "ScoreCard.h"

class scoreText : public sf::Drawable {
public:

    static std::vector<std::string>storeScores;

    sf::Text text;
    sf::Font font;

    scoreText();
    scoreText(const std::string& str);
    scoreText(const std::string& str, sf::Vector2f position);
    static void calculate();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //const static std::string getFinal(Scores score);
};


#endif //SFMLMIDTERM_SCORETEXT_H
