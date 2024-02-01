#ifndef BOUNCING_BALL_H
#define BOUNCING_BALL_H
#include <SFML/Graphics.hpp>
#include<ctime>

//polymorphism, child of Drawable
class Ball : public sf::Drawable
{
private:
    sf::CircleShape circle;
    sf::CircleShape circle2;
    sf::Text letter;
    sf::Font font;
    float boundx, boundy;
    float speedx=5, speedy=5;
public:
    //Ball(sf::Vector2f position);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void setRadius(float radius);

    void setSpeed();
    float getSpeed();

    void setBounds(float boundx, float boundy);

    float getPositionX();
    float getPositionY();
/*
    int getRandomInt();
    void setRandomColor();
*/
    void setLetter(char letter);
    char getLetter();

    int getRandomInt();

    void bounce();
};


#endif //BOUNCING_BALL_H
