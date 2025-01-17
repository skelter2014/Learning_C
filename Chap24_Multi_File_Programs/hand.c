#include "dealer.h"

// Initialize a hand by setting the number of cards dealt to 0 and all card pointers to NULL
void InitializeHand(Hand* pHand)
{
    pHand->cardsDealt = 0;
    for (int i = 0; i < kCardsInHand; i++) {
        pHand->hand[i] = NULL;
    }
}

// Add a card to the hand if there is space
void AddCardToHand(Hand* pHand, Card* pCard)
{
    int numInHand = pHand->cardsDealt;
    if (numInHand == kCardsInHand) return;

    // Set the next card in the hand to the incoming card pointer
    pHand->hand[pHand->cardsDealt] = pCard;
    pHand->cardsDealt++;
}

// Print the hand with a leading string
void PrintHand(Hand* pHand, char* pHandStr, char* pLeadStr)
{
    printf("%s%s\n", pLeadStr, pHandStr);
    for (int i = 0; i < kCardsInHand; i++) // 1..5
    {
        printf("%s", pLeadStr);
        PrintCard(pHand->hand[i]);
        printf("\n");
    }
}

// Print all hands with specific leading strings
void PrintAllHands(Hand* hands[kNumHands])
{
    PrintHand(hands[0], "Hand 1:", "              ");
    PrintHand(hands[1], "Hand 2:", "");
    PrintHand(hands[2], "Hand 3:", "                                  ");
    PrintHand(hands[3], "Hand 4:", "              ");
    printf("\n\n");
}


