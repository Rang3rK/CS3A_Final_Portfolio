//
// Created by Nu lar on 12/4/23.
//

#ifndef FINALPORTFOLIO_PROJECT_H
#define FINALPORTFOLIO_PROJECT_H
#include "EventHandlerable.h"
#include "Runable.h"
#include "Updateable.h"
#include "Nameable.h"

//Polymorphism
class Project : public sf::Drawable, public Runable, public Nameable, public EventHandlerable, public Updateable {

};


#endif //FINALPORTFOLIO_PROJECT_H
