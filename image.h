//
// Created by Nu lar on 11/2/23.
//

#ifndef SFMLMIDTERM_IMAGE_H
#define SFMLMIDTERM_IMAGE_H
#include<SFML/Graphics.hpp>

class image {

private:
    static sf::Texture texture;     //static as we only want to create one
    static void loadTexture();      //doesn't need object to use it
public:
    static sf::Texture& getImage();
};

#endif //SFMLMIDTERM_IMAGE_H
