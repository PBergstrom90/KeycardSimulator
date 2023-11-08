#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <conio.h>
#include <time.h>
#include "safeinput.h"
#include "card.h"
#include "cardlist.h"
#include "adminmenu.h"
#include "addcard.h"
#include "remotedoor.h"

// Använd "return" för att komma ur en meny while-loop.
// Anropa inte funktionen på nytt (stackoverflow).

void insertStartCards(CARDLIST *cardList) {
    CARD card1;
    strcpy(card1.cardId, "1212");
    card1.accessGranted = true;
    strcpy(card1.timeStamp, "timestamp_for_card1");

    CARD card2;
    strcpy(card2.cardId, "1213");
    card2.accessGranted = false;
    strcpy(card2.timeStamp, "timestamp_for_card2");

    cardList->list = malloc(2 * sizeof(CARD));
    cardList->list[0] = card1;
    cardList->list[1] = card2;
    cardList->count = 2;
}

int main (){   

    CARDLIST cardList;

    insertStartCards(&cardList);
    
    adminMenu(&cardList);

    free(cardList.list);
    
    return 0;
}