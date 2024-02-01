#ifndef BOUNCING_CIRCLE_H
#define BOUNCING_CIRCLE_H
#include <SFML/Graphics.hpp>
#include <string>

class CircleBox : public sf::Drawable {
private:
    sf::CircleShape circle2;
    sf::Text letter;
    sf::Font font;

public:
    CircleBox();
    CircleBox(char letter);
    CircleBox(char letter, float size);
    CircleBox(char letter, float size, unsigned int characterSize, sf::Color circleColor, sf::Color textColor);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    char getLetter();
    void setLetter(char letter);
    void move(sf::Vector2f velocity);
};


#endif //BOUNCING_CIRCLE_H
