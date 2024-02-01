//
// Created by Nu lar on 11/2/23.
//

#include "image.h"

sf::Texture image::texture;

void image::loadTexture()
{
    if(!texture.loadFromFile("board.png"))
        exit(20);
}

sf::Texture& image::getImage()
{
    loadTexture();
    return texture;
}