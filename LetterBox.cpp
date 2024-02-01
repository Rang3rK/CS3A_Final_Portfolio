//
// Created by Nu lar on 11/2/23.
//

#include "LetterBox.h"

LetterBox::LetterBox()
        : LetterBox("Hands")
{

}
LetterBox::LetterBox(const std::string& letter)
        : LetterBox(letter, 24)
{

}
LetterBox::LetterBox(const std::string& letter, unsigned int characterSize)
        : LetterBox(letter, 24, sf::Color::White)
{

}
LetterBox::LetterBox(const std::string& letter, unsigned int characterSize, sf::Color textColor)
    : LetterBox (letter, 24, sf::Color::White, {10.f, 10.f})
{

}

LetterBox::LetterBox(const std::string& letter, unsigned int characterSize,sf::Color textColor, sf::Vector2f position)
{
    if(!font.loadFromFile("Font/OpenSans-Bold.ttf"))
        exit(28);

    this->letter.setFont(font);
    this->letter.setCharacterSize(characterSize);
    this->letter.setFillColor(textColor);
    this->letter.setPosition(position);
    setLetter(letter);
}

void LetterBox::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(letter);
}

void LetterBox::setLetter(const std::string& letter)
{
    this->letter.setString(letter);
}

