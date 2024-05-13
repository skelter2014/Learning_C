#include <stdbool.h>

typedef enum { club = 1, diamond, heart, spade } SSuit;
typedef enum { one = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace } FFace;

typedef struct Card {
    SSuit suit;
    int suitValue;
    FFace face;
    int faceValue;
    bool isWild;
} aCard;

typedef struct Hand {
    int cardsDealt;
    aCard c1, c2, c3, c4, c5;
} aHand;


aHand addCard(aHand oldHand, aCard card);
void printCard (aCard);
void printHand(aHand);
void printHand2(aHand);


