#include "SnakeFunction.h"


int SnakeFunction::init_size=5;

SnakeFunction::SnakeFunction()
    : direction(Direction::UP)
{
    init_snake();
}

void SnakeFunction::init_snake()
{
    //center
    for (int i = 0; i < SnakeFunction::init_size; i++)
    {
        snake.push_back(Snake(sf::Vector2f(
                Snake::window_Width / 2 - Snake::snake_width / 2,
                Snake::window_Height / 2 - (Snake::snake_height / 2) + (Snake::snake_height * i))));
    }

}

void SnakeFunction::key()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        direction = Direction::UP;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        direction = Direction::DOWN;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        direction = Direction::LEFT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        direction = Direction::RIGHT;
    }
}

//void SnakeFunction::move_snakeDirection() {
//
//    for (int i = snake.size(); i > 0; i--)
//    {
//        //snake[i] = snake[i - 1];
//    }
//
//    switch (direction)
//    {
//        case Direction::UP :
//            snake[0].move_snake(0, -speed_x);
//            break;
//        case Direction::DOWN :
//            snake[0].move_snake(0, speed_x);
//            break;
//        case Direction::LEFT :
//            snake[0].move_snake(-speed_y, 0);
//            break;
//        case Direction::RIGHT :
//            snake[0].move_snake(speed_y, 0);
//            break;
//    }
//}

void SnakeFunction::move_snakeDirection()
{

    switch (direction)
    {
        case Direction::UP :
            snake[0].move_snake(0, -speed_x);
            break;
        case Direction::DOWN :
            snake[0].move_snake(0, speed_x);
            break;
        case Direction::LEFT :
            snake[0].move_snake(-speed_y, 0);
            break;
        case Direction::RIGHT :
            snake[0].move_snake(speed_y, 0);
            break;
    }

    for(int i=1; i<snake.size(); i++)
    {
        sf::Transform  p = snake[0].getTransform();
        sf::Vector2f pos = p.transformPoint(snake[i].getPosition());
        snake[i].translate(pos);
    }
}

void SnakeFunction::grow()
{
    sf::Vector2f f = snake.back().getPosition();
    switch(direction) {
        case Direction::UP:
            snake.emplace_back(Snake(sf::Vector2f(f.x, f.y + Snake::snake_height)));
            snake.emplace_back(Snake(sf::Vector2f(f.x, f.y + Snake::snake_height)));
            snake.emplace_back(Snake(sf::Vector2f(f.x, f.y + Snake::snake_height)));


            //std::cout<<"increased 1 up direction, "<<snake.back().getPosition().x << ", " << snake.back().getPosition().y<<std::endl;
        case Direction::DOWN:
            snake.emplace_back(Snake(sf::Vector2f(f.x, f.y - Snake::snake_height)));
            snake.emplace_back(Snake(sf::Vector2f(f.x, f.y - Snake::snake_height)));
            snake.emplace_back(Snake(sf::Vector2f(f.x, f.y - Snake::snake_height)));

            //std::cout<<"increased 1 down direction, "<<snake.back().getPosition().x<<std::endl;
            break;
        case Direction::LEFT:
            snake.emplace_back(Snake(sf::Vector2f(f.x - Snake::snake_width, f.y)));
            snake.emplace_back(Snake(sf::Vector2f(f.x - Snake::snake_width, f.y)));
            snake.emplace_back(Snake(sf::Vector2f(f.x - Snake::snake_width, f.y)));

            //std::cout<<"increased 1 left direction, "<<snake.back().getPosition().x<<std::endl;
            break;
        case Direction::RIGHT:
            snake.emplace_back(Snake(sf::Vector2f(f.x + Snake::snake_width, f.y)));
            snake.emplace_back(Snake(sf::Vector2f(f.x + Snake::snake_width, f.y)));
            snake.emplace_back(Snake(sf::Vector2f(f.x + Snake::snake_width, f.y)));

            //std::cout<<"increased 1 right direction, "<<snake.back().getPosition().x<<std::endl;
            break;
    }
}

//die if hit wall
void SnakeFunction::checkBoundCollision()
{
    check = false;
    if(snake[0].getPosition().x > Snake::window_Width)
    {
        //std::cout << "Hit right wall x" << std::endl;
        check = true;
        exit(0);
    }
    else if (snake[0].getPosition().x < 0)
    {
        //std::cout << "Hit left wall" << std::endl;
        check = true;
        exit(0);

    }
    else if (snake[0].getPosition().y > Snake::window_Height)
    {
        //std::cout << "Hit bottom wall" << std::endl;
        check = true;
        exit(0);
    }
    else if (snake[0].getPosition().y < 0)
    {
        //std::cout << "Hit top wall" << std::endl;
        check = true;
        exit(0);
    }

}

void SnakeFunction::checkSelfCollision()
{
    //{
//        if((snake[0].getPosition().x == snake[snake.size()-1].getPosition().y))
//            exit(1); ///quit
    //}
    Snake& headNode = snake[0];
    for (int i= 1; i < snake.size(); ++i)
    {
        if (headNode.getPosition() == snake[i].getPosition())
        {
            hitItself =true;
        }
    }
    //std::cout<<hitItself<<std::endl;
}

int SnakeFunction::getSize() {
    return snake.size();
}

void SnakeFunction::update()
{
    key();
    move_snakeDirection();
    checkSelfCollision();
    checkBoundCollision();
}

sf::FloatRect SnakeFunction::getHeadBounds() {
    return snake[0].getBounds();
}

void SnakeFunction::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for(auto &x : snake)
    {
        window.draw(x);
    }
}

int SnakeFunction::getSpeedX() {
    return speed_x;
}

int SnakeFunction::getSpeedY()
{
    return speed_y;
}

void SnakeFunction::setSpeedX(int a) {
    speed_x = a;
}

void SnakeFunction::setSpeedY(int a) {
    speed_y = a;
}

bool SnakeFunction::checkstatus() const {
    return check;
}

