#ifndef _HAND_H_
#define _HAND_H_

#include "card.h"

enum {
    kCardsInHand = 5,
    kNumHands = 4
};

typedef struct
{
    int   cardsDealt;
    Card* hand[kCardsInHand]; //array hand of 52 Card pointers.

} Hand;

//Hand
void InitializeHand(Hand* pHand);
void AddCardToHand(Hand* pHand, Card* pCard);
void PrintHand(Hand* pHand, char* pHandStr, char* pLeadStr);
void PrintAllHands(Hand* hands[kNumHands]);



#endif