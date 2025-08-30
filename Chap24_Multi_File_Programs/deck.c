#include "dealer.h"

// Initialize the deck with ordered cards
void InitializeDeck(Deck* pDeck)
{
    // Define the faces of the cards
    Face f[] = { two, three, four,five,six,seven,eight,nine,ten,jack,queen,king,ace };
    Card* pC;
    // Loop through each face value
    for (int i = 0; i < kCardsInSuit; i++) {
        // Initialize spades
        pC = &(pDeck->Ordered[i + (0 * kCardsInSuit)]);
        InitializeCard(pC, spade, f[i], false);

        // Initialize hearts
        pC = &(pDeck->Ordered[i + (1 * kCardsInSuit)]);
        InitializeCard(pC, heart, f[i], false);

        // Initialize diamonds
        pC = &(pDeck->Ordered[i + (2 * kCardsInSuit)]);
        InitializeCard(pC, diamond, f[i], false);

        // Initialize clubs
        pC = &(pDeck->Ordered[i + (3 * kCardsInSuit)]);
        InitializeCard(pC, club, f[i], false);
    }
    // Create an array of pointers to the physical card deck
    for (int i = 0; i < kCardsInDeck; i++) {
        pDeck->shuffled[i] = &(pDeck->Ordered[i]);
    }
    pDeck->isShuffled = false; // Deck is initially not shuffled
    pDeck->numDealt = 0; // No cards have been dealt yet
}

// Print the current state of the deck
void PrintDeck(Deck* pDeck)
{
    printf("%d cards in the deck\n", kCardsInDeck);
    printf("Deck %s shuffled\n", pDeck->isShuffled ? "is" : "is not");
    printf("%d cards dealt into %d hands\n", pDeck->numDealt, kNumHands);

    if (pDeck->isShuffled == true) {
        if (pDeck->numDealt > 0) {
            printf("The remaining shuffled deck:\n\n");
        }
        else {
            printf("The full shuffled deck:\n\n");
        }
        // Print the shuffled deck
        for (int i = pDeck->numDealt, j = 0; i < kCardsInDeck; i++, j++) {
            printf("  (%2d)", i + 1);
            PrintCard(pDeck->shuffled[i]);
            if (j == 3) {
                printf("\n");
                j = -1;
            }
        }
        printf("\n\n");
    }
    else { // Deck is NOT shuffled
        printf("The ordered deck: \n");
        // Print the ordered deck
        for (int i = 0; i < kCardsInSuit; i++) {
            int index = i + (0 * kCardsInSuit);
            printf("  (%2d)", index + 1);
            PrintCard(&(pDeck->Ordered[index]));

            index = i + (1 * kCardsInSuit);
            printf("  (%2d)", index + 1);
            PrintCard(&(pDeck->Ordered[index]));

            index = i + (2 * kCardsInSuit);
            printf("  (%2d)", index + 1);
            PrintCard(&(pDeck->Ordered[index]));

            index = i + (3 * kCardsInSuit);
            printf("  (%2d)", index + 1);
            PrintCard(&(pDeck->Ordered[index]));

            printf("\n");
        }
        printf("\n\n");
    }
}

// Shuffle the deck
void ShuffleDeck(Deck* pDeck)
{
    long randIndex;
    srand(time(NULL)); // Seed the random number generator
    Card* pTmpCard;

    // Swap each card with a random card
    for (int i = 0; i < kCardsInDeck; i++) {
        randIndex = rand() % kCardsInDeck; // between 0..52
        pTmpCard = pDeck->shuffled[i];
        pDeck->shuffled[i] = pDeck->shuffled[randIndex];
        pDeck->shuffled[randIndex] = pTmpCard;
    }
    pDeck->isShuffled = true; // Mark the deck as shuffled
}

// Deal a card from the deck
Card* DealCardFromDeck(Deck* pDeck)
{
    Card* pCard = pDeck->shuffled[pDeck->numDealt]; // Get the next card to be dealt
    pDeck->shuffled[pDeck->numDealt] = NULL; // card is gone.
    pDeck->numDealt++; // increment num cards in play
    return pCard; // Return the dealt card
}
