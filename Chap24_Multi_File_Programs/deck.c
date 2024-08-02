#include "dealer.h"

void InitializeDeck(Deck* pDeck)
{
    Face f[] = { two, three, four,five,six,seven,eight,nine,ten,jack,queen,king,ace };
    Card* pC;
    for (int i = 0; i < kCardsInSuit; i++) {
        pC = &(pDeck->Ordered[i + (0 * kCardsInSuit)]);
        InitializeCard(pC, spade, f[i], false);

        pC = &(pDeck->Ordered[i + (1 * kCardsInSuit)]);
        InitializeCard(pC, heart, f[i], false);

        pC = &(pDeck->Ordered[i + (2 * kCardsInSuit)]);
        InitializeCard(pC, diamond, f[i], false);

        pC = &(pDeck->Ordered[i + (3 * kCardsInSuit)]);
        InitializeCard(pC, club, f[i], false);
    }
    for (int i = 0; i < kCardsInDeck; i++) {
        pDeck->shuffled[i] = &(pDeck->Ordered[i]); // create an array of pointers to the physical card deck.
    }
    pDeck->isShuffled = false;
    pDeck->numDealt = 0;

}
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
        for (int i = pDeck->numDealt, j = 0; i < kCardsInDeck; i++, j++) {
            printf("  (%2d)", i + 1);
            PrintCard(pDeck->shuffled[i]);
            if (j == 3) {
                printf("\n");
                j = -1;
            }
            else {
                //printf("\t");
            }
        }
        printf("\n\n");
    }
    else { //deck is NOT shuffled

        printf("The ordered deck: \n");
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
void ShuffleDeck(Deck* pDeck)
{
    long randIndex;
    srand(time(NULL));
    Card* pTmpCard;

    for (int i = 0; i < kCardsInDeck; i++) {
        randIndex = rand() % kCardsInDeck; // between 0..52
        pTmpCard = pDeck->shuffled[i];
        pDeck->shuffled[i] = pDeck->shuffled[randIndex];
        pDeck->shuffled[randIndex] = pTmpCard;
    }
    pDeck->isShuffled = true;
}

Card* DealCardFromDeck(Deck* pDeck)
{
    Card* pCard = pDeck->shuffled[pDeck->numDealt];
    pDeck->shuffled[pDeck->numDealt] = NULL; // card is gone.
    pDeck->numDealt++; //increment num cards in play
    return pCard;
}
