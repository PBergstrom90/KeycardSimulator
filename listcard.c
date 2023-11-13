#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include "listcard.h"
#include "safeinput.h"
#include "card.h"
#include "cardlist.h"
#include "adminmenu.h"
#include "fileio.h"

void insertStartCards(CARDLIST *cardList) {
    
    // Initializing 2 default cards, presented at the beginning of the project.
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

void PrintCardToString(const CARD *card, char *output, size_t outputSize) {
    // Check for NULL pointers or insufficient output buffer size
    if (card == NULL || output == NULL || outputSize < 100) {
        printf("ERROR: Invalid input or insufficient buffer size.\n");
        return;
    }

    snprintf(output, outputSize,
             "--- CARD NR %d ---\nCard ID: %d\nAccess Granted: %s\nTimestamp: %s\n",
             card->cardId, card->accessGranted ? 1 : 0, card->timeStamp);
}

void listCardToFile(const CARDLIST *cardList, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("ERROR: Cannot open file for writing");
        return;
    }

    // Print the header
    fprintf(file, "--- CARD LIST ---\n");

    // For every card in the list, use the PrintCardToString function.
    for (int i = 0; i < cardList->count; i++) {
        for (int i = 0; i < cardList->count; i++) {
        char cardString[100];
        PrintCardToString(&(cardList->list[i]), cardString, sizeof(cardString));
        fprintf(file, "%s", cardString);
        fprintf(file, "\n");  // Add a new line to separate each card entry
}
}

    // Print the total count
    fprintf(file, "\nTotal amount of cards in the system: %d\n", cardList->count);

    fclose(file);
}

void PrintCard (const CARD *card){
    if (card == NULL) {
        printf("ERROR: Invalid card pointer.\n");
        return;
    }
    if (card->timeStamp != NULL) {
    printf("Card ID: %d\nAccess Granted: %s\nTimestamp: %s\n",
    card->cardId, card->accessGranted ? "Yes" : "No", card->timeStamp);
    } else {
        printf("ERROR: Invalid timestamp pointer.\n");
    }
}

void listCard(const CARDLIST *cardList) { 

// For every card in the list, use the PrintCard-function.
for (int i = 0; i < cardList->count;i++){
     printf("\t\n--- CARD NR %d --- \n", i+1);
     PrintCard(&(cardList->list[i]));
     }

    printf("\nTotal amount of cards in the system: %d\n", cardList->count);

}