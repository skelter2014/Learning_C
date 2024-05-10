#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
    Card* pCard1;
    Card* pCard2;
    Card* pCard3;
    Card* pCard4;
    Card* pCard5;
} Hand;

void PrintCard(Card* pCard);
void CardToString(Card* pCard, char pCardStr[20]);
void InitializeCard(Card* pCard, Suit s, Face f, bool wild);
void InitializeDeck(Card* pDeck);
void PrintDeck(Card* pDeck);
void InitializeHand(Hand* pHand);
void AddCardToHand(Hand* pHand, Card* pCard);
void PrintHand(Hand* pHand, char* pLeadStr);
Card** GetCardInHand(Hand* pHand, int cardIndex);


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
void InitializeDeck(Card* pDeck)
{
    Face f[] = { two, three, four,five,six,seven,eight,nine,ten,jack,queen,king,ace };
    Card* pCard;
    for (int i = 0; i < kCardsinSuit; i++) {
        pCard = &(pDeck[i + (0 * kCardsinSuit)]);
        InitializeCard(pCard, spade, f[i], false);

        pCard = &(pDeck[i + (1 * kCardsinSuit)]);
        InitializeCard(pCard, heart, f[i], false);

        pCard = &(pDeck[i + (2 * kCardsinSuit)]);
        InitializeCard(pCard, diamond, f[i], false);

        pCard = &(pDeck[i + (3 * kCardsinSuit)]);
        InitializeCard(pCard, club, f[i], false);
    }

}
void PrintDeck(Card* pDeck)
{
    printf(" %d cards in the deck\n\n", kCardsinDeck);
    printf("The ordered deck: \n");
    for (int i = 0; i < kCardsinSuit; i++) {
        int index = i + (0 * kCardsinSuit);
        printf("  (%2d)", index + 1);
        PrintCard(&(pDeck[index]));

        index = i + (1 * kCardsinSuit);
        printf("  (%2d)", index + 1);
        PrintCard(&(pDeck[index]));

        index = i + (2 * kCardsinSuit);
        printf("  (%2d)", index + 1);
        PrintCard(&(pDeck[index]));

        index = i + (3 * kCardsinSuit);
        printf("  (%2d)", index + 1);
        PrintCard(&(pDeck[index]));

        printf("\n");
    }
    printf("\n\n");
}

void InitializeHand(Hand* pHand)
{
    pHand->cardsDealt = 0;
    pHand->pCard1 = NULL;
    pHand->pCard2 = NULL;
    pHand->pCard3 = NULL;
    pHand->pCard4 = NULL;
    pHand->pCard5 = NULL;
}

Card** GetCardInHand(Hand* pHand, int cardIndex)
{
    Card** ppC;
    switch (cardIndex) {
        case 0:  ppC = &(pHand->pCard1); break;
        case 1:  ppC = &(pHand->pCard2); break;
        case 2:  ppC = &(pHand->pCard3); break;
        case 3:  ppC = &(pHand->pCard4); break;
        case 4:  ppC = &(pHand->pCard5); break;
    }
    return ppC;
}
void AddCardToHand(Hand* pHand, Card* pCard)
{
    int numInHand = pHand->cardsDealt;
    if (numInHand == kCardsInHand) return;

    Card** ppC = GetCardInHand(pHand, numInHand);
    *ppC = pCard;

    pHand->cardsDealt++;
}
void PrintHand(Hand* pHand, char* pLeadStr)
{
    for (int i = 0; i < kCardsInHand; i++) // 1..5
    {
        Card** ppCard = GetCardInHand(pHand, i);
        printf("%s", pLeadStr);
        PrintCard(*ppCard);
        printf("\n");
    }
}
Card* DealCardFromDeck(Card deck[], int index)
{
    Card* pCard = &deck[index];
    return pCard;
}
int main(void)
{
    Card deck[kCardsinDeck];
    Card* pDeck = deck;

    InitializeDeck(&deck[0]);

    Hand h1, h2, h3, h4;
    InitializeHand(&h1);
    InitializeHand(&h2);
    InitializeHand(&h3);
    InitializeHand(&h4);

    for (int i = 0; i < kCardsInHand; i++)
    {
        AddCardToHand(&h1, DealCardFromDeck(pDeck, i));
        AddCardToHand(&h2, DealCardFromDeck(pDeck, i + 13));
        AddCardToHand(&h3, DealCardFromDeck(pDeck, i + 26));
        AddCardToHand(&h4, DealCardFromDeck(pDeck, i + 39));
    }
    printf("                  Hand 1: \n");
    PrintHand(&h1, "                  ");
    printf("Hand 2: \n");
    PrintHand(&h2, "  ");
    printf("                                    Hand 3: \n");
    PrintHand(&h3, "                                    ");
    printf("                  Hand 4: \n");
    PrintHand(&h4, "                  ");



}

