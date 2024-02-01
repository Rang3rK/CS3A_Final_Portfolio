//
// Created by Nu lar on 12/4/23.
//

#include "Portfolio.h"

Portfolio::Portfolio()
    : left("<"), right(">")
{
    ///implement buttons here;
    ///when clicked, call ;
    left.setText("<");
    right.setText(">");
    left.setPosition({50,650});
    right.setPosition({920,650});
    left.setRadius(20);
    right.setRadius(20);
    left.setDefaultColor(sf::Color::Black);
    right.setDefaultColor(sf::Color::Black);

    portfolio_text.setPosition({850,20});
    portfolio_text.setCharacterSize(20);
    portfolio_text.setFillColor(sf::Color::White);
    portfolio_text.setFont(Font::getFont(OPEN_SANS));
}

void Portfolio::load(Project& programs)
{
    this->project.push_back(&programs);
}

void Portfolio::eventHandler(sf::RenderWindow& window, sf::Event event) {

    left.eventHandler(window,event);
    right.eventHandler(window,event);

    if(MouseEvent::isClicked(left.getCircle(),window))
    {
        if(iter != project.begin())
        {
            --iter;
        }
    }
    else if(MouseEvent::isClicked(right.getCircle(), window))
    {
        if (iter != project.end())
        {
            iter++;
        }
    }

}

void Portfolio::drawproject(Drawable& drawable, sf::RenderWindow window)
{
    window.draw(drawable);
}

void Portfolio::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(*(*iter));

}


void Portfolio::run() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Khant's Portfolio");
    window.setFramerateLimit(60);

    window.setKeyRepeatEnabled(false);
    iter = project.begin();

    while(window.isOpen()) {
        (*(*iter)).insert_functionality(window);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                (*iter)->eventHandler(window, event);
                eventHandler(window, event);
                //menu();
                (*(*iter)).run(window);
                (*(*iter)).run();
            }

            (*iter)->update();
            update();

            portfolio_text.setString((*iter)->getName());

            window.clear();

            window.draw(*(*iter));
            window.draw(left);
            window.draw(right);
            window.draw(portfolio_text);
            window.display();
        }
    }
}

void Portfolio::update() {
    left.update();
    right.update();
    //(**iter).update();
    //menu();
}

std::string Portfolio::getName(Nameable &nameable) {
    return (*(*iter)).getName();
}

void Portfolio::menu() {
    for(auto& x : project)
        std::cout<<"Project: "<<getName(*x)<<std::endl;
}
