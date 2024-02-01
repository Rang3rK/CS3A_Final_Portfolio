#include "Circle.h"

CircleBox::CircleBox()
    : CircleBox('8')
{
}

CircleBox::CircleBox(char letter)
        : CircleBox(letter, 20)
{

}

CircleBox::CircleBox(char letter, float size)
    : CircleBox(letter, size, 24, sf::Color(255,193,203), sf::Color::White)
{

}

CircleBox::CircleBox(char letter, float size, unsigned int characterSize, sf::Color circleColor, sf::Color textColor)
{
    circle2.setRadius(size);
    circle2.setFillColor(circleColor);

    if(!font.loadFromFile("Font/OpenSans-Bold.ttf"))
        exit(28);

    //text
    this->letter.setFont(font);
    this->letter.setCharacterSize(characterSize);
    this->letter.setFillColor(textColor);
    setLetter(letter);
}

void CircleBox::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    states.transform = circle2.getTransform();
    window.draw(circle2);   //draw letter first on purpose
    window.draw(letter);
}

char CircleBox::getLetter()
{
    return letter.getString()[0];
}

void CircleBox::setLetter(char letter)
{
    this->letter.setString(std::string(1, letter));
}
void CircleBox::move(sf::Vector2f velocity)
{
    circle2.move(velocity);
    letter.move(velocity);
}