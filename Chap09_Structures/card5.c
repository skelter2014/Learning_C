#include "card.h"
#include <stdio.h>


int  main(void)
{

    aHand h = { 0 };
    aCard c1 = { spade, (int)spade, ten, (int)ten, false };
    aCard c2 = { heart, (int)heart, queen, (int)queen, false };
    aCard c3 = { diamond, (int)diamond, five, (int)five, false };
    aCard c4 = { club, (int)club, ace, (int)ace, false };
    aCard c5 = { heart, (int)heart, jack, (int)jack, false };
    aCard c6 = { club, (int)club, two, (int)two, false };


    h = addCard(h, c1);
    h = addCard(h, c2);
    h = addCard(h, c3);
    h = addCard(h, c4);
    h = addCard(h, c5);
    h = addCard(h, c6);

    printHand(h);
    printf("\n");
    printHand2(h);
    return 0;

}

void printHand(aHand h)
{
    for (int i = 1; i < h.cardsDealt + 1; i++) {
        aCard c;
        switch (i) {
            case 1: c = h.c1; break;
            case 2: c = h.c2; break;
            case 3: c = h.c3; break;
            case 4: c = h.c4; break;
            case 5: c = h.c5; break;
            default: return; break;
        }
        printCard(c);
    }
}
void printHand2(aHand h)
{
    int dealt = h.cardsDealt;
    if (dealt == 0) return;
     printCard(h.c1); if (dealt == 1) return;
     printCard(h.c2); if (dealt == 2) return;
     printCard(h.c3); if (dealt == 3) return;
     printCard(h.c4); if (dealt == 4) return;
     printCard(h.c5);  return;
}


aHand addCard(aHand oldHand, aCard card)
{
    aHand newHand = oldHand;
    switch (newHand.cardsDealt) {
        case 0: newHand.c1 = card; newHand.cardsDealt++; break;
        case 1: newHand.c2 = card; newHand.cardsDealt++; break;
        case 2: newHand.c3 = card; newHand.cardsDealt++; break;
        case 3: newHand.c4 = card; newHand.cardsDealt++; break;
        case 4: newHand.c5 = card; newHand.cardsDealt++; break;
        default: newHand = oldHand;
            break;
    }
    return newHand;
}


void printCard(aCard c)
{
    switch (c.face) {
        case two: printf("2\t");break;
        case three: printf("3\t");break;
        case four: printf("4\t");break;
        case five: printf("5\t");break;
        case six: printf("6\t");break;
        case seven: printf("7\t");break;
        case eight: printf("8\t");break;
        case nine: printf("9\t");break;
        case ten: printf("10\t");break;
        case jack: printf("Jack\t");break;
        case queen: printf("Queen\t");break;
        case king: printf("King\t");break;
        case ace: printf("Ace\t");break;
        default: printf(" ??? "); break;

    }
    switch (c.suit) {

        case spade: printf(" of Spades\n");break;
        case heart: printf(" of Hearts\n");break;
        case diamond: printf(" of Diamonds\n");break;
        case club: printf(" of Clubs\n");break;
        default: printf(" of ???\n");break;
    }

};
