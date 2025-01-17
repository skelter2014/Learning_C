#include "dealer.h"
/**
 * To build/debug this file, use the directory build task instead of the file build task.:
 * "name": "C/C++: gcc build and debug directory", -- note this is in the drop down menu from the run and debug
 * function of Code on the left hand side.
 * 
 * the project root folder should also be the Learning_C folder rather than one level up
 */

// Print a card by converting it to a string and printing the string
void PrintCard(Card* pCard)
{
    char cardStr[20] = { 0 };
    CardToString(pCard, cardStr);
    printf("%18s", cardStr);
}

// Convert a card to a string representation
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

// Initialize a card with a suit, face, and wild status
void InitializeCard(Card* pCard, Suit s, Face f, bool wild)
{
    pCard->suit = s;
    pCard->suitValue = (int)s;
    pCard->face = f;
    pCard->faceValue = (int)f;
    pCard->isWild = wild;
}

