#include "dealer.h"

void PrintCard(Card* pCard)
{
    char cardStr[20] = { 0 };
    CardToString(pCard, cardStr);
    printf("%18s", cardStr);
}
void CardToString(Card* pCard, char pCardStr[20])
{
    switch (pCard->face) {
        case two: strcpy(pCardStr, "2 "); break;
        case three: strcpy(pCardStr, "3 "); break;
        case four: strcpy(pCardStr, "4 "); break;
        case five: strcpy(pCardStr, "5 "); break;
        case six: strcpy(pCardStr, "6 "); break;
        case seven: strcpy(pCardStr, "7 "); break;
        case eight: strcpy(pCardStr, "8 "); break;
        case nine: strcpy(pCardStr, "9 "); break;
        case ten: strcpy(pCardStr, " 10 "); break;
        case jack: strcpy(pCardStr, " Jack "); break;
        case queen: strcpy(pCardStr, " Queen "); break;
        case king: strcpy(pCardStr, " King "); break;
        case ace: strcpy(pCardStr, " Ace "); break;
        default: strcpy(pCardStr, " ??? "); break;
    }
    switch (pCard->suit) {
        case spade: strcat(pCardStr, "of Spades");break;
        case heart: strcat(pCardStr, "of Hearts");break;
        case diamond: strcat(pCardStr, "of Diamonds");break;
        case club: strcat(pCardStr, "of Clubs");break;
        default: strcat(pCardStr, "of ???");break;
    }

}
void InitializeCard(Card* pCard, Suit s, Face f, bool wild)
{
    pCard->suit = s;
    pCard->suitValue = (int)s;
    pCard->face = f;
    pCard->faceValue = (int)f;
    pCard->isWild = wild;
}

