#include "dealer.h"

int main(void)
{
    Deck deck;
    Deck* pDeck = &deck;

    InitializeDeck(pDeck);
    PrintDeck(pDeck);

    ShuffleDeck(pDeck);
    PrintDeck(pDeck);

    Hand h1, h2, h3, h4;
    Hand* hands[] = { &h1,&h2,&h3,&h4 };

    for (int i = 0; i < kNumHands; i++) {
        InitializeHand(hands[i]);
    }


    for (int i = 0; i < kCardsInHand; i++) {
        for (int j = 0; j < kNumHands; j++) {
            Card* aCard = DealCardFromDeck(pDeck);
            AddCardToHand(hands[j], aCard);
        }
    }
    PrintAllHands(hands);
    PrintDeck(pDeck);
}

