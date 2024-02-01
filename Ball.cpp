#include "Ball.h"

void Ball::setRadius(float radius)
{
    circle.setRadius(radius);
    circle2.setRadius(20);
    circle2.setPosition((circle.getOrigin().x)+circle.getRadius()/2,(circle.getOrigin().y)+circle.getRadius()/2);
    letter.setPosition((circle2.getOrigin().x)+ circle2.getRadius()*2,(circle2.getOrigin().y)+circle2.getRadius()*2);
    letter.setCharacterSize(24);
}

void Ball::setBounds(float boundx, float boundy)
{
    this->boundx = boundx;
    this->boundy = boundy;
}

void Ball::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(circle);
    window.draw(circle2,states);
    window.draw(letter, states);
}

void Ball::bounce()
{
    if(circle.getPosition().y < 0)
    {
        speedy=-speedy;
        circle.setFillColor(sf::Color::Yellow);
        getLetter();
    }
    if (getPositionY() > boundy)
    {
        speedy = -speedy;
        circle.setFillColor(sf::Color::Blue);
        getLetter();
    }
    if (circle.getPosition().x < 0)
    {
        speedx = -speedx;
        circle.setFillColor(sf::Color::Red);
        getLetter();
    }
    if (getPositionX() > boundx)
    {
        speedx = -speedx;
        circle.setFillColor(sf::Color(75,0,130));
        getLetter();
    }
    circle.move(speedx,speedy);
    circle2.move(speedx,speedy);
    letter.move(speedx, speedy);
}

float Ball::getPositionY()
{
    return circle.getPosition().y + circle.getRadius()*2;
}

float Ball::getPositionX()
{
    return circle.getPosition().x + circle.getRadius()*2;
}

void Ball::setLetter(char letter)
{
    if(!font.loadFromFile("Font/OpenSans-Bold.ttf"))
        exit(28);

    this->letter.setString(std::string(1, letter));
    this->letter.setFont(font);
    this->letter.setFillColor(sf::Color::Black);
}

char Ball::getLetter()
{
    int rand_num = getRandomInt();
    switch(rand_num){
        case 1:
            setLetter('1');
            break;
        case 2:
            setLetter('2');
            break;
        case 3:
            setLetter('3');
            break;
        case 4:
            setLetter('4');
            break;
        case 5:
            setLetter('5');
            break;
        case 6:
            setLetter('6');
            break;
        case 7:
            setLetter('7');
            break;
        case 8:
            setLetter('8');
            break;
    }
    return letter.getString()[0];
}


int Ball::getRandomInt()
{
    return 1+ (rand() % 8);
}
//
//Ball::Ball(sf::Vector2f position) {
//    circle.setPosition(position);
//}

/*
void Ball::setRandomColor()
{
    std::srand(std::time(nullptr));

    int rand_num = getRandomInt();
    switch(rand_num){
        case 1:
            circle.setFillColor(sf::Color::Yellow);
        case 2:
            circle.setFillColor(sf::Color::Blue);
        case 3:
            circle.setFillColor(sf::Color::Red);
        case 4:
            circle.setFillColor(sf::Color(75,0,130));
        case 5:
            circle.setFillColor(sf::Color(255,140,0));
        case 6:
            circle.setFillColor(sf::Color::Green);
        case 7:
            circle.setFillColor(sf::Color(139,0,0));
        case 8:
            circle.setFillColor(sf::Color::Yellow);
        default:
            break;
    }
}*/
