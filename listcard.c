#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <time.h>
#include "listcard.h"
#include "addcard.h"
#include "safeinput.h"
#include "card.h"
#include "cardlist.h"
#include "adminmenu.h"
#include "fileio.h"

void insertStartCards(CARDLIST *cardList) {
    
    // Initializing 2 default cards, presented the briefing of the project.
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

/*  This following function goes through all saved CARDs in the initiated CARDLIST. 
    Calculates buffersize and then allocates memory for the CARD-string. 
    Each CARD in the CARDLIST is then formated and printed to the file. */

void listCardToFile(const CARDLIST *cardList, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("ERROR: Cannot open file for writing");
        return;
    }
    // Print the header.
    fprintf(file, "--- CARD LIST ---\n");
    // Iterate through each card in the cardList.
    for (int i = 0; i < cardList->count; i++) {
        char *cardString = NULL;
        // Calculate the size needed for the string. The final + 1 is for null termination ('\0').
        size_t bufferSize = snprintf(NULL, 0, "--- CARD NR %d ---\nCard ID: %d\nAccess Granted: %s\nTimestamp: %s\n",
        i + 1, cardList->list[i].cardId, cardList->list[i].accessGranted ? "Yes" : "No", cardList->list[i].timeStamp) + 1;
        // Allocate memory for the string.
        cardString = malloc(bufferSize);
        if (cardString == NULL) {
            fprintf(stderr, "ERROR: Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        // Format the string.
        snprintf(cardString, bufferSize, "--- CARD NR %d ---\nCard ID: %d\nAccess Granted: %s\nTimestamp: %s\n",
        i + 1, cardList->list[i].cardId, cardList->list[i].accessGranted ? "Yes" : "No", cardList->list[i].timeStamp);
        // Write to the file.
        fprintf(file, "%s", cardString);
        // Free the dynamically allocated memory.
        free(cardString);
    }
    // Print the total count.
    fprintf(file, "\nTotal amount of cards in the system: %d\n", cardList->count);
    fclose(file);
}

// The following short functions: printCard and listCard, are used to present cards to the user in the console.

void printCard (const CARD *card){
    if (card == NULL) {
        printf("ERROR: Invalid card pointer.\n");
        return;
    }
    printf("Card ID: %d\nAccess Granted: %s\nTimestamp: %s\n",
    card->cardId, card->accessGranted ? "Yes" : "No", card->timeStamp);
}

void listCard(const CARDLIST *cardList) { 

// For every card in the list, use the PrintCard-function.
for (int i = 0; i < cardList->count;i++){
     printf("\t\n--- CARD NR %d --- \n", i+1);
     printCard(&(cardList->list[i]));
     }

    printf("\nTotal amount of cards in the system: %d\n", cardList->count);

}