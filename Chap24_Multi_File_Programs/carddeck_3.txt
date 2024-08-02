#include <stdbool.h>   // for Boolean
#include <stdio.h>     // for printf()
#include <string.h>    // for strcpy() and strcat()
#include <stdlib.h>    // for rand() and srand()
#include <time.h>      // for date().

typedef enum { club = 1, diamond, heart, spade } Suit;
typedef enum { two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace } Face;
enum {
    kCardsinDeck = 52,
    kCardsInHand = 5,
    kCardsinSuit = 13,
    kNumHands = 4
};

typedef struct Card {
    Suit suit;
    int suitValue;
    Face face;
    int faceValue;
    bool isWild;
} Card;

typedef struct
{
    int   cardsDealt;
    Card* hand[kCardsInHand]; //array hand of 52 Card pointers.

} Hand;
typedef struct {
    Card Ordered[kCardsinDeck]; //this is an array of Cards, NOT pointers.
    Card* shuffled[kCardsinDeck]; // this is an array of POINTERS to the the Ordered deck of CARDS
    int numDealt;
    bool isShuffled;
} Deck;

/***********************************************************/
/* Function Protytypes*/
/***********************************************************/
//Card
void PrintCard(Card* pCard);
void CardToString(Card* pCard, char pCardStr[20]);
void InitializeCard(Card* pCard, Suit s, Face f, bool wild);
Card** GetCardInHand(Hand* pHand, int cardIndex);

//Hand
void InitializeHand(Hand* pHand);
void AddCardToHand(Hand* pHand, Card* pCard);
void PrintHand(Hand* pHand, char* pHandStr, char* pLeadStr);
void PrintAllHands(Hand* hands[kNumHands]);

//Deck
void InitializeDeck(Deck* pDeck);
void PrintDeck(Deck* pDeck);
void ShuffleDeck(Deck* pDeck);
Card* DealCardFromDeck(Deck* pDeck);

/***********************************************************/
/*Function Definitions*/
/***********************************************************/
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
void InitializeDeck(Deck* pDeck)
{
    Face f[] = { two, three, four,five,six,seven,eight,nine,ten,jack,queen,king,ace };
    Card* pC;
    for (int i = 0; i < kCardsinSuit; i++) {
        pC = &(pDeck->Ordered[i + (0 * kCardsinSuit)]);
        InitializeCard(pC, spade, f[i], false);

        pC = &(pDeck->Ordered[i + (1 * kCardsinSuit)]);
        InitializeCard(pC, heart, f[i], false);

        pC = &(pDeck->Ordered[i + (2 * kCardsinSuit)]);
        InitializeCard(pC, diamond, f[i], false);

        pC = &(pDeck->Ordered[i + (3 * kCardsinSuit)]);
        InitializeCard(pC, club, f[i], false);
    }
    for (int i = 0; i < kCardsinDeck; i++) {
        pDeck->shuffled[i] = &(pDeck->Ordered[i]); // create an array of pointers to the physical card deck.
    }
    pDeck->isShuffled = false;
    pDeck->numDealt = 0;

}
void PrintDeck(Deck* pDeck)
{
    printf("%d cards in the deck\n", kCardsinDeck);
    printf("Deck %s shuffled\n", pDeck->isShuffled ? "is" : "is not");
    printf("%d cards dealt into %d hands\n", pDeck->numDealt, kNumHands);

    if (pDeck->isShuffled == true) {
        if (pDeck->numDealt > 0) {
            printf("The remaining shuffled deck:\n\n");
        }
        else {
            printf("The full shuffled deck:\n\n");
        }
        for (int i = pDeck->numDealt, j = 0; i < kCardsinDeck; i++, j++) {
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
        for (int i = 0; i < kCardsinSuit; i++) {
            int index = i + (0 * kCardsinSuit);
            printf("  (%2d)", index + 1);
            PrintCard(&(pDeck->Ordered[index]));

            index = i + (1 * kCardsinSuit);
            printf("  (%2d)", index + 1);
            PrintCard(&(pDeck->Ordered[index]));

            index = i + (2 * kCardsinSuit);
            printf("  (%2d)", index + 1);
            PrintCard(&(pDeck->Ordered[index]));

            index = i + (3 * kCardsinSuit);
            printf("  (%2d)", index + 1);
            PrintCard(&(pDeck->Ordered[index]));

            printf("\n");
        }
        printf("\n\n");

    }
}
void InitializeHand(Hand* pHand)
{
    pHand->cardsDealt = 0;
    for (int i = 0; i < kCardsInHand; i++) {
        pHand->hand[i] = NULL;
    }
}
// Card** GetCardInHand(Hand* pHand, int cardIndex)
// {
//     Card** ppC;
//     switch (cardIndex) {
//         case 0:  ppC = &(pHand->pCard1); break;
//         case 1:  ppC = &(pHand->pCard2); break;
//         case 2:  ppC = &(pHand->pCard3); break;
//         case 3:  ppC = &(pHand->pCard4); break;
//         case 4:  ppC = &(pHand->pCard5); break;
//     }
//     return ppC;
// }
void AddCardToHand(Hand* pHand, Card* pCard)
{
    int numInHand = pHand->cardsDealt;
    if (numInHand == kCardsInHand) return;

    //set the next card in the hand incoming card pointer.
    pHand->hand[pHand->cardsDealt] = pCard;
    pHand->cardsDealt++;
}
void PrintAllHands(Hand* hands[kNumHands])
{
    PrintHand(hands[0], "Hand 1:", "              ");
    PrintHand(hands[1], "Hand 2:", "");
    PrintHand(hands[2], "Hand 3:", "                                  ");
    PrintHand(hands[3], "Hand 4:", "              ");
    printf("\n\n");
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

void ShuffleDeck(Deck* pDeck)
{
    long randIndex;
    srand(time(NULL));
    Card* pTmpCard;

    for (int i = 0; i < kCardsinDeck; i++) {
        randIndex = rand() % kCardsinDeck; // between 0..52
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

