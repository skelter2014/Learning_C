#ifndef _DECK_H
#define _DECK_H_
#include "card.h"


enum {
    kCardsInDeck = 52
};

typedef struct {
    Card Ordered[kCardsInDeck]; //this is an array of Cards, NOT pointers.
    Card* shuffled[kCardsInDeck]; // this is an array of POINTERS to the the Ordered deck of CARDS
    int numDealt;
    bool isShuffled;
} Deck;

//Deck
void InitializeDeck(Deck* pDeck);
void PrintDeck(Deck* pDeck);
void ShuffleDeck(Deck* pDeck);
Card* DealCardFromDeck(Deck* pDeck);

#endif