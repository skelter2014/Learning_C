#include "dealer.h"

int main(void)
{
    Deck deck;
    Deck* pDeck = &deck;

    // Initialize the deck of cards
    InitializeDeck(pDeck);
    // Print the initialized deck
    PrintDeck(pDeck);

    // Shuffle the deck of cards
    ShuffleDeck(pDeck);
    // Print the shuffled deck
    PrintDeck(pDeck);

    Hand h1, h2, h3, h4;
    Hand* hands[] = { &h1,&h2,&h3,&h4 };

    // Initialize each hand
    for (int i = 0; i < kNumHands; i++) {
        InitializeHand(hands[i]);
    }

    // Deal cards to each hand
    for (int i = 0; i < kCardsInHand; i++) {
        for (int j = 0; j < kNumHands; j++) {
            Card* aCard = DealCardFromDeck(pDeck);
            AddCardToHand(hands[j], aCard);
        }
    }
    // Print all hands
    PrintAllHands(hands);
    // Print the remaining deck
    PrintDeck(pDeck);
}

