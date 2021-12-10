#include <stdio.h>
#include <stdlib.h>

// Karten struct 
typedef struct Card {
    int id;
    struct Card* pNext;
} Card;

// Funktionen
Card* createCard(int value, Card*  pNext);
Card* createDeck();
void splitDeck(Card* pDeck, Card* pHandPlayer1, Card* pHandPlayer2);
Card* appendCard(Card* pCardList, Card* pCard);
int getListLength(Card* pFirstCard);
void removeCardFromList(Card* pCardList, Card* pCard);
void moveCardFromListToList(Card* pRemovingFrom, Card* pAppandingTo, Card* pCard);

//log Deck
// log cards
void logCards(Card* pCard) {
    while (pCard != NULL) {
        printf("%d ", pCard->id);
        pCard = pCard->pNext;
    }
    printf("\n");
}

int main()
{
    Card* pDeck = createDeck();
    Card* pHandPlayer1 = NULL;
    Card* pHandPlayer2 = NULL;
    logCards(pDeck);
    splitDeck(pDeck, pHandPlayer1, pHandPlayer2);
    logCards(pHandPlayer1);
    logCards(pHandPlayer2);

    system("pause");
    return 0;
}

/** 
 * Teilt ein Deck zufälig in zwei Hände auf.
 * 
 * @param pDeck, Pointer auf die ersete Karte des Decks
 * @param pHandPlayer1, Pointer auf die erste Hand
 * @param pHandPlayer2, Pointer auf die zweite Hand
 */
void splitDeck(Card* pDeck, Card* pHandPlayer1, Card* pHandPlayer2)
{
    int deckLength = getListLength(pDeck);
    for (int i = 0; i < deckLength / 2; i++)
    {
        Card* pTemp = pDeck;
        pDeck = pDeck->pNext;
        printf("%i", (rand() % getListLength(pTemp)));
        int xCardInDeck = rand() % getListLength(pTemp);
        for (int d = 0; d < xCardInDeck; d++)
        {
            pTemp = pTemp->pNext;
        }
        moveCardFromListToList(pDeck, pHandPlayer1, pTemp);

    }
    pHandPlayer2 = pDeck;
    
    logCards(pHandPlayer1);
    logCards(pHandPlayer2);
}

/** 
 * Geht durch die Karten und fügt eine Karte am ende der Kartenliste an
 * 
 * @param pRemovingFrom, Pointer auf eine Liste von welcher die Karte entfernt werden soll
 * @param pAppandingTo, Pointer auf eine Liste an welche angefühgt werden soll
 * @param pCard, Karte die angefügt und entfernt werden soll
 */
void moveCardFromListToList(Card* pRemovingFrom, Card* pAppandingTo, Card* pCard)
{
    Card* pTemp = pRemovingFrom;
    while (pTemp->pNext != pCard)
    {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pCard->pNext;
}

/** 
 * Geht durch die Karten und fügt eine Karte am ende der Kartenliste an
 * 
 * @param pCardList, Pointer auf eine Liste an welche angefühgt werden soll
 * @param pCard, Karte die angefügt werden soll
 * @return Pointer auf die Liste
 */
Card* appendCard(Card* pCardList, Card* pCard)
{
    if(pCardList == NULL){
        pCard->pNext = NULL;
        return pCard;
    } else {
        Card* pTemp = pCardList;
        while (pTemp->pNext != NULL) {
            pTemp = pTemp->pNext;
        }
        pCard->pNext = NULL;
        pTemp->pNext = pCard;
        return pCardList;
    }
    
}

/** 
 * Gibt die Länge der Kartenliste zurück
 * 
 * @param pCardList, Pointer auf die erste Karte der Liste
 * @param pCard, die zu entfernende Karte
 */
void removeCardFromList(Card* pCardList, Card* pCard)
{
    while (pCardList->pNext != NULL && pCardList->pNext != pCard)
    {
        pCardList = pCardList->pNext;
    }
    if(pCardList->pNext == pCard){
        pCardList->pNext = pCard->pNext;
        pCard->pNext = NULL;
    }
}

/*
 * Gibt die Länge der Kartenliste zurück
 *
 * @param pFirstCard, Pointer auf eine Liste
*/
int getListLength(Card* pFirstCard)
{
    Card* pTemp = pFirstCard;
    int length = 0;
    while (pTemp != NULL) {
        length++;
        pTemp = pTemp->pNext;
    }
    return length;
}

/**
 * Erstellt eine Linked List aus Karten
 * 
 * @return Pointer auf die erste Karte der Liste
 */
Card* createDeck() {
    return createCard(1, createCard(2, createCard(3, createCard(4, createCard(5, createCard(6, createCard(7, createCard(8, createCard(9, createCard(10, NULL))))))))));
}

/**
 * Erstellt einen Karte mit einer Id und dem Pointer auf das Nächste element.
 * 
 * @param id, id der neuen Karte.
 * @param pNext, ein Pointer auf die nächst Karte.
 * @return Pointer auf die neue Karte.
 */
Card* createCard(int id, Card* pNext) {
    Card* pCard = (Card*)malloc(sizeof(Card));
    pCard->id = id;
    pCard->pNext = pNext;
    return pCard;
}