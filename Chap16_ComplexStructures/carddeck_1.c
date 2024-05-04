#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef enum { club = 1, diamond, heart, spade } Suit;
typedef enum { two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace } Face;
enum {
    kCardsinDeck = 52,
    kCardsinHand = 5,
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

void PrintCard(Card* pCard);
void CardToString(Card* pCard, char pCardStr[20]);
void InitializeCard(Card* pCard, Suit s, Face f, bool wild);
void InitializeDeck(Card* pDeck);
void PrintDeck(Card* pDeck);

int  main(void)
{
    Card deck[kCardsinDeck];
    InitializeDeck(deck);
    PrintDeck(deck);
    printf("\n");
}

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
