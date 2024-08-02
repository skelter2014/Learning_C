/*
card.h:23:6: error: conflicting types for ‘InitializeCard’; have ‘void(Card *, Suit,  Face,  _Bool)’
   23 | void InitializeCard(Card* pCard, Suit s, Face f, bool wild);
      |      ^~~~~~~~~~~~~~
In file included from dealer.h:7,
                 from hand.c:1:
card.h:23:6: note: previous declaration of ‘InitializeCard’ with type ‘void(Card *, Suit,  Face,  _Bool)’
   23 | void InitializeCard(Card* pCard, Suit s, Face f, bool wild);*/
   

#ifndef _CARD_H_
#define _CARD_H_ ////NOTE: this was producing a compile error because I left off the last underscore.
enum {
    kNotWildCard = 0,
    kWildCard = 1, 
    kCardsInSuit = 13
};

typedef enum { club = 1, diamond, heart, spade } Suit;
typedef enum { two = 2, three, four, five, six, seven, 
    eight, nine, ten, jack, queen, king, ace } Face;

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


#endif