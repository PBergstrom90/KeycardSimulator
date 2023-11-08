#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <time.h>
#include "safeinput.h"
#include "card.h"
#include "cardlist.h"
#include "adminmenu.h"


void addCard(CARDLIST *cardList) {

    time_t current_time;
    struct tm* time_info;
    time(&current_time);
    time_info = localtime(&current_time);

    printf("\nSystem's current date and time: %d/%02d/%02d %02d:%02d\n",
           time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday,
           time_info->tm_hour, time_info->tm_min);
            
    // Define a new CARD structure and populate it with user input.
    CARD newCard;
    GetInput("Enter new Card-ID (4 digits): ", newCard.cardId, sizeof(newCard.cardId));
    
    // NEEDS TO FIX
    // Similar steps for accessGranted and timeStamp.
    
    // Resize the list to accommodate the new card.
    cardList->list = realloc(cardList->list, (cardList->count + 1) * sizeof(CARD));
    if (cardList->list == NULL) {
        // Handle memory allocation error.
        return;
    }
    
    // Add the new card to the list and increment the count.
    cardList->list[cardList->count] = newCard;
    cardList->count++;

    printf("Total amount of cards in the system: %d\n", cardList->count);
}