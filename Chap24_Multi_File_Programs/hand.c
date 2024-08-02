#include "dealer.h"

void InitializeHand(Hand* pHand)
{
    pHand->cardsDealt = 0;
    for (int i = 0; i < kCardsInHand; i++) {
        pHand->hand[i] = NULL;
    }
}
void AddCardToHand(Hand* pHand, Card* pCard)
{
    int numInHand = pHand->cardsDealt;
    if (numInHand == kCardsInHand) return;

    //set the next card in the hand incoming card pointer.
    pHand->hand[pHand->cardsDealt] = pCard;
    pHand->cardsDealt++;
}
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
void PrintAllHands(Hand* hands[kNumHands])
{
    PrintHand(hands[0], "Hand 1:", "              ");
    PrintHand(hands[1], "Hand 2:", "");
    PrintHand(hands[2], "Hand 3:", "                                  ");
    PrintHand(hands[3], "Hand 4:", "              ");
    printf("\n\n");
}


