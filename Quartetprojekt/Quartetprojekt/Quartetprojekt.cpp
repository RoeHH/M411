#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Karten struct 
typedef struct Card {
    char bezeichnung[50];
    int leistung; //In PS
    double hubraum; //In Liter
    struct Card* pNext;
} Card;

typedef struct PlayerHands {
    struct Card* pHandPlayer;
    struct Card* pHandComputer;
} PlayerHands;

// Funktionen
void startGame();
void printHandSizes(Card* pCard);
void printCard(Card* pCard);
Card* createCard(const char bezeichnung[50], int leistung, double hubraum, Card* pNext);
Card* createDeck();
PlayerHands* createPlayerHands();
PlayerHands* getPlayerHands();
void appendCard(Card* pCardList, Card* pCard);
int getListLength(Card* pFirstCard);
void removeCardFromList(Card** pCardList, Card* pCard);
void moveCardFromListToList(Card** pRemovingFrom, Card* pAppandingTo, Card* pCard);
bool newGamePrompt(bool printText);
void playTurn(PlayerHands* pPlayerHands);
bool selectAttributPrompt(PlayerHands* pPlayerHands, bool printText);
void moveCardFromFrontOfAListToTheBack(Card** pList);
int getStringLength(char* pStr);
bool endGamePromt(bool printText);

int main()
{
    time_t t;
    srand((unsigned) time(&t));
    startGame();
    return 0;
}

/** 
 * Startet das Spiel und ruft sich am ende bei wunsch wieder auf
 */
void startGame() {
    PlayerHands* playerHands = getPlayerHands();
    bool gameEnded = false;
    playTurn(playerHands);//Hier wird eine runde gestartet um die Frage zu beenden erst nach der ersten runde aufzurufen 
    while (playerHands->pHandComputer != NULL && playerHands->pHandPlayer != NULL) {
        if(endGamePromt(true)) { //Frage ob das Spiel beendet werden soll
            playTurn(playerHands);
        }else{
            gameEnded = true;
            break;
        }
    }
    if(!gameEnded){
        if (playerHands->pHandComputer == NULL) {
            printf("Sie haben gewonnen supper gemacht.\n");
        }
        else {
            printf("Sie haben leider verloren versuchen sie es doch erneut.\n");
        }
    }
    if(newGamePrompt(true)) { //Frage nach einem neuen Spiel
        startGame();
    }
}

/** 
 * Fragt den User ob er dies Runde beenden möchte
 *
 * @param printText, wenn true wird der text "Wollen sie diese Runde fortfahren? J f\x81r Ja und N f\x81r Nein: " ausgegeben.
 * 
 * @return bool, true wenn diese Spiel beendet werden soll, false wenn nicht
 */
bool endGamePromt(bool printText){
    if (printText) {
        printf("Wollen sie diese Runde fortfahren? J f\x81r Ja und N f\x81r Nein: ");
    }
    char c = getchar();
    if(c == 'J' || c == 'j') {
        return true;

    }
    else if (c == 'N' || c == 'n') {
        return false;

    }
    else {
        return endGamePromt(false);
    }
}

/**
 * Geht durch einen Zug des Spieles
 *
 * @param pPlayerHands Pointer auf die HandKarten des Spielers und des Computers
 */
void playTurn(PlayerHands* pPlayerHands){
    system("cls");
    printHandSizes(pPlayerHands->pHandPlayer); // Consolen Ausgabe der Anzahl Handkarten des Spielers
    printCard(pPlayerHands->pHandPlayer); // Consolen Ausgabe der Handkarten des Spielers
    if (selectAttributPrompt(pPlayerHands, true)) { //Wenn der Spiler gewint verschieben wir die erste Karte beider Listen hinten an seine Liste
        printf("Supper sie hatten denn besseren Wagen :)\n");
        moveCardFromListToList(&pPlayerHands->pHandComputer, pPlayerHands->pHandPlayer, pPlayerHands->pHandComputer); // Karte des Computers -> Hand des Spielers
        moveCardFromFrontOfAListToTheBack(&pPlayerHands->pHandPlayer); // Karte des Spielers -> Hand des Spielers
    }
    else { // Hat der Computer gewonnen werden die Karten zu ihm verschoben
        printf("Ohhh nein der Computer hatte den besseren Wert :(\n");
        moveCardFromListToList(&pPlayerHands->pHandPlayer, pPlayerHands->pHandComputer, pPlayerHands->pHandPlayer); // Karte des Spilers -> hand des Computers
        moveCardFromFrontOfAListToTheBack(&pPlayerHands->pHandComputer); // Karte des Computers -> Hand des Computers
    }
}

/**
 * Läst den Spieler sein Atribut auswählen und startet die Überprüfung ob er diesen Zug gewint oder verliert.
 *
 * @param pPlayerHands Pointer auf die HandKarten des Spielers und des Computers
 * @param, printText, wenn true wird der text "Wollen sie die Leistung...." ausgegeben.
 * 
 * @return bool, gibt true zurück wenn der spieler seine Kartebehält, false wenn nicht
 */
bool selectAttributPrompt(PlayerHands* pPlayerHands, bool printText) {
    if (printText) {
        printf("Wollen sie die Leistung oder den Hubraum vergleichen? \n"
            "Geben sie L f\x81r Leistung ein oder H f\x81r Hubraum: ");
    }
    char c = getchar();
    if(c == 'L' || c == 'l') {
        printf("------------------------------------\n");
        printf("| Leistung Spieler: %d PS        |\n", pPlayerHands->pHandPlayer->leistung);
        printf("| Leistung Computer: %d PS       |\n", pPlayerHands->pHandComputer->leistung);
        printf("------------------------------------\n");
        return (pPlayerHands->pHandPlayer->leistung > pPlayerHands->pHandComputer->leistung);
    } 
    else if(c == 'H' || c == 'h') {
        printf("------------------------------------\n");
        printf("| Hubraum Spieler: %.2f Liter     |\n", pPlayerHands->pHandPlayer->hubraum);
        printf("| Hubraum Computer: %.2f Liter    |\n", pPlayerHands->pHandComputer->hubraum);
        printf("------------------------------------\n");
        return (pPlayerHands->pHandPlayer->hubraum > pPlayerHands->pHandComputer->hubraum);

    } 
    else {
        return selectAttributPrompt(pPlayerHands, false);
    }
}

/**
 * Gibt die Anzahl der Karten der beiden Handen aus
 *
 * @param pCard Pointer auf die erste Karte des Spielers 
 */
void printHandSizes(Card* pCard){
    printf("------------------------------------\n");
    int anzahlKartenSpieler = getListLength(pCard);
    printf("| Anzahl Karten Spieler:  %d        | \n", anzahlKartenSpieler);
    printf("| Anzahl Karten Computer: %d        | \n", (10 - anzahlKartenSpieler));
}


/**
 * Gibt eine Karte in die Konsole aus
 *
 * @param pCard Pointer auf die Karte
 */
void printCard(Card* pCard) 
{
    printf("------------------------------------\n");
    printf("| Ihre Karte:                      |\n");
    printf("------------------------------------\n");
    printf("| %s", pCard->bezeichnung);
    for (int i = getStringLength(pCard->bezeichnung); i < 33; i++) {
        printf(" ");
    }
    printf("|\n");
    printf("| Leistung: %d PS                |\n", pCard->leistung);
    printf("| Hubraum: %.2f Liter             |\n", pCard->hubraum);
    printf("------------------------------------\n");
}

/**
 * Gibt die länge eines Strings zurück
 *
 * @param pStr pointer auf einen string
 *
 * @return count of chars in string
 */
int getStringLength(char* pStr)
{
    int count = 0;
    while (*pStr != '\0')
    {
        count++;
        *pStr++;
    }
    return(count);
}

/** 
 * Fragt den User ob er eine neues Spiel starten möchte
 *
 * @param printText, wenn true wird der text "Wollen sie noch einmal Spielen? J f\x81r Ja und N f\x81r Nein: " ausgegeben.
 * 
 * @return bool, true wenn ein neues Spiel gestartet werden soll, false wenn nicht
 */
bool newGamePrompt(bool printText) {
    if (printText) {
        printf("Wollen sie noch einmal Spielen? J f\x81r Ja und N f\x81r Nein: ");
    }
    char c = getchar();
    if(c == 'J' || c == 'j') {
        return true;

    }
    else if (c == 'N' || c == 'n') {
        return false;

    }
    else {
        return newGamePrompt(false);
    }
}

/** 
 * Erstellt ein Deck und teilt dies zufällig in zwei Hände auf.
 * 
 * @return playerhands, ein PlayerHand struct
 */
PlayerHands* getPlayerHands()
{
    Card* pDeck = createDeck(); //Deck erstellen
    Card* pHandPlayer = NULL; 
    int deckLength = getListLength(pDeck); 
    for (int i = 0; i < deckLength / 2; i++)
    {
        Card* pTemp = pDeck;
        int xCardInDeck = rand() % getListLength(pTemp); //Hier ermitteln wir welche Karte aus dem Deck genommen werden soll
        for (int d = 0; d < xCardInDeck; d++) //Wir verschieben denn Pointer zu diesem Element
        {
            pTemp = pTemp->pNext;
        }

        if (pHandPlayer == NULL) { // Wenn der erste Spieler noch keine Karten hat wird seine Hand erstellt durch eine direkte zugweisung, die Karte wird aus dem Deck entfernt
            removeCardFromList(&pDeck, pTemp);
            pHandPlayer = pTemp;
        }
        else { // Wenn der erste Spieler schon Karten hat wird die Karte an die Hand angehängt, die Karte wird auch aus dem Deck entfernt
            moveCardFromListToList(&pDeck, pHandPlayer, pTemp);
        }
    }
    PlayerHands* pHands = createPlayerHands();
    pHands->pHandPlayer = pHandPlayer; // Die im Loop erstellte hand wird im PlayerHands struct gespeichert
    pHands->pHandComputer = pDeck; // Die restliche Karten werden dem Computer zugewiesen
    return pHands;
}

/** 
 * Geht durch die Karten und fügt eine Karte am ende der Kartenliste an
 * 
 * @param pRemovingFrom, Pointer auf eine Liste von welcher die Karte entfernt werden soll
 * @param pAppandingTo, Pointer auf eine Liste an welche angefügt werden soll
 * @param pCard, Karte die angefügt und entfernt werden soll
 * 
 * @return pRemovingFrom, gibt denn Pointer auf die Liste zurück von welcher das element entfernt wurde da wenn das erste element entfernt wurde dies sonst zu Fehler führt.
 */
void moveCardFromListToList(Card** pRemovingFrom, Card* pAppandingTo, Card* pCard)
{
    removeCardFromList(pRemovingFrom, pCard);
    appendCard(pAppandingTo, pCard);
} 

/**
 * Verschiebt die erste Karte der Liste and das ende der Liste
 *
 * @param pList, Pointer auf die erste Karte einer Liste auf welcher die Operation durchgeführt werden soll.
 *
 * @return pList, gibt denn Pointer auf die Liste zurück von welcher das element entfernt wurde da wenn das erste element entfernt wurde dies sonst zu Fehler führt.
 */
void moveCardFromFrontOfAListToTheBack(Card** pList)
{
    Card* pTempCard = *pList;
    Card* pTempList = *pList;
    *pList = (*pList)->pNext;
    while (pTempList->pNext != NULL) {
        pTempList = pTempList->pNext;
    }
    pTempCard->pNext = NULL;
    pTempList->pNext = pTempCard;
}

/** 
 * Geht durch die Karten und fügt eine Karte am ende der Kartenliste an
 * 
 * @param pCardList, Pointer auf eine Liste an welche angefühgt werden soll
 * @param pCard, Karte die angefügt werden soll
 * @return Pointer auf die Liste
 */
void appendCard(Card* pCardList, Card* pCard)
{
    Card* pTemp = pCardList;
    while (pTemp->pNext != NULL) {
        pTemp = pTemp->pNext;
    }
    pCard->pNext = NULL;
    pTemp->pNext = pCard;
}

/** 
 * Gibt die Länge der Kartenliste zurück
 * 
 * @param pCardList, Pointer auf die erste Karte der Liste
 * @param pCard, die zu entfernende Karte, wird zu einer karte mit NULL in pNext
 * 
 * @return pCardList, Pointer auf die erste Karte der Liste, da wenn das erste element entfernt wurde dies sonst zu Fehler führt.
 */
void removeCardFromList(Card** pCardList, Card* pCard)
{
    if (*pCardList == pCard) {
        *pCardList = pCard->pNext;
        pCard->pNext = NULL;
    }
    else {
        Card* pTemp = *pCardList;
        while (pTemp->pNext != NULL && pTemp->pNext != pCard)
        {
            pTemp = pTemp->pNext;
        }
        if (pTemp->pNext == pCard) {
            pTemp->pNext = pCard->pNext;
        }
        pCard->pNext = NULL;    }
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
    return createCard("Audi R8", 4320, 32.906,
            createCard("Mercedes-Benz SLR McLaren", 6456, 29.906, 
                createCard("Ferrari 458 Italia", 8536, 26.906,
                    createCard("Porsche 911", 1056, 23.906, 
                        createCard("Lamborghini Aventador", 1256, 17.906,
                            createCard("Bugatti Veyron", 1456, 20.906,
                                createCard("Ferrari F40", 1656, 14.906,
                                    createCard("Lamborghini Huracan", 1856, 11.906,
                                        createCard("Porsche Panamera", 2056, 28.906,
                                            createCard("Ferrari F50", 2256, 14.163, NULL))))))))));
}

/**
 * Erstellt einen Karte mit einer einem namen einem Leistungsattribut, einem Hubraumattribut und dem Pointer auf das Nächste element.
 * 
 * @param bezeichnung, name der neuen Karte.
 * @param leistung, leistung der neuen Karte.
 * @param hubraum, hubraum der neuen Karte.
 * @param pNext, ein Pointer auf die nächst Karte.
 * 
 * @return Pointer auf die neue Karte.
 */
Card* createCard(const char bezeichnung[50], int leistung, double hubraum, Card* pNext) {
    Card* pCard = (Card*)malloc(sizeof(Card));
    strcpy_s(pCard->bezeichnung, bezeichnung);
    pCard->leistung = leistung;
    pCard->hubraum = hubraum;
    pCard->pNext = pNext;
    return pCard;
}

/**
 * Erstellt einen PlayerHands Struct mit zwei Händen.
 */
PlayerHands* createPlayerHands() {
    PlayerHands* pHands = (PlayerHands*)malloc(sizeof(PlayerHands));
    return pHands;
}