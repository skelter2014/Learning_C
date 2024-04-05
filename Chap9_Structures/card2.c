#include <stdio.h>
#include <stdbool.h>

enum Suit { club = 1, diamond, heart, spade };

enum Face { one = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

struct Card {
    enum Suit suite;
    int suitValue;
    enum Face face;
    int faceValue;
    bool isWild;
};

bool isEqual( struct Card c1, struct Card c2){
    if(c1.suite != c2.suite) return false;
    if(c1.face != c2.face) return false;
    return true;
}

int sumCards(struct Card c1, struct Card c2){
    int faceValue = c1.faceValue + c2.faceValue;
    return faceValue;
}

void  main(void)
{

    struct Card card1 = {heart, (int)heart, king, (int)king, false};
    struct Card card2 = card1;

    struct Card card3 = {0};
    card3.suite = spade;
    card3.suitValue = (int)spade;
    card3.face = ace;
    card3.faceValue = (int)ace;

    bool cardsEqual = isEqual(card1, card2);
    printf( "card1 is %s equal to card2\n", cardsEqual ? "" : " not" );

    printf("The combined faceValue of card2(%d) + card3(%d) is %d\n\n", card2.faceValue, card3.faceValue, sumCards(card2, card3));



    printf ("enum Suit is %lu bytes\n", sizeof (enum Suit));
    printf ("enum Face is %lu bytes\n", sizeof (enum Face));
    printf (" int is %lu bytes\n", sizeof (int));
    printf (" bool is %lu bytes\n", sizeof (bool));

    printf (" struct Card is %lu bytes\n", sizeof (struct Card));
    printf (" card is %lu bytes\n", sizeof (card1));

}
