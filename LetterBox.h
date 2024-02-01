//
// Created by Nu lar on 11/2/23.
//

#ifndef SFMLMIDTERM_LETTERBOX_H
#define SFMLMIDTERM_LETTERBOX_H

#include <SFML/Graphics.hpp>
#include <string>

class LetterBox : public sf::Drawable
{
private:
    sf::Text letter;
    sf::Font font;
public:
    LetterBox();
    LetterBox(const std::string& letter);
    LetterBox(const std::string& letter, unsigned int characterSize);
    LetterBox(const std::string& letter, unsigned int characterSize,sf::Color textColor);
    LetterBox(const std::string& letter, unsigned int characterSize,sf::Color textColor, sf::Vector2f position);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setLetter(const std::string& letter);
};


#endif //SFMLMIDTERM_LETTERBOX_H
