#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include "safeinput.h"
#include "card.h"
#include "cardlist.h"
#include "adminmenu.h"
#include "listcard.h"

void insertStartCards(CARDLIST *cardList) {
    
    time_t current_time;
    struct tm* time_info;
    time(&current_time);
    time_info = localtime(&current_time);
    
    CARD card1;
    card1.cardId = 1212;
    card1.accessGranted = true;
    snprintf(card1.timeStamp, sizeof(card1.timeStamp), "%d-%02d-%02d",
             time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday);

    CARD card2;
    card2.cardId = 1213;
    card2.accessGranted = false;
    struct tm* time_info2 = localtime(&current_time);
    snprintf(card2.timeStamp, sizeof(card2.timeStamp), "%d-%02d-%02d",
             time_info2->tm_year + 1900, time_info2->tm_mon + 1, time_info2->tm_mday);

    cardList->list = malloc(2 * sizeof(CARD));
    cardList->list[0] = card1;
    cardList->list[1] = card2;
    cardList->count = 2;
}

void PrintCard (const CARD *card){
    printf("Card ID: %d\nAccess Granted: %s\nTimestamp: %s\n",
    card->cardId, card->accessGranted ? "Yes" : "No", card->timeStamp);
}

void listCard(const CARDLIST *cardList) {

for (int i = 0; i < cardList->count;i++){
     printf("\t\n--- CARD NR %d --- \n", i+1);
     PrintCard(&(cardList->list[i]));
     }

    printf("\nTotal amount of cards in the system: %d\n", cardList->count);

}