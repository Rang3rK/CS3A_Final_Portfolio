//
// Created by Nu lar on 11/1/23.
//

#ifndef SFMLMIDTERM_CARDHAND_H
#define SFMLMIDTERM_CARDHAND_H

#include "Deck.h"
//#include <algorithm>

class CardHand {
private:
    std::vector<Card> playerHand;
public:
    CardHand();
    Card& addCard(Deck& deck);
    void clearHand();
    const std::vector<Card>& getCards() const;

    void sortPlayerHand();


};


#endif //SFMLMIDTERM_CARDHAND_H
