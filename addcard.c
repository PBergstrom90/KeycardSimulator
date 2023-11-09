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

    // Using a do-while loop, to confirm that the user is actually only entering 4 characters.
    do {
        GetInput("\nEnter new Card-ID (4 digits): ", newCard.cardId, sizeof(newCard.cardId));
        if (strlen(newCard.cardId) != 4) {
            printf("\nERROR: Card-ID must be exactly 4 digits. Please try again.\n");
        }
    } while (strlen(newCard.cardId) != 4);

    // Asks the user if the new card should have access or not.
    newCard.accessGranted = GetBooleanInput("Should access be granted? (yes/no): ");

    // Setting current timestamp.
    strftime(newCard.timeStamp, sizeof(newCard.timeStamp), "%Y-%m-%d", time_info);
    
    // Resize the list with realloc to accommodate the new card.
    cardList->list = realloc(cardList->list, (cardList->count + 1) * sizeof(CARD));
    if (cardList->list == NULL) {
        // Handle memory allocation error.
        return;
    }
    
    // Add the new card to the list and increment the total count.
    cardList->list[cardList->count] = newCard;
    cardList->count++;

    printf("\nCard added successfully.\n");
    printf("\nTotal amount of cards in the system: %d\n", cardList->count);
}