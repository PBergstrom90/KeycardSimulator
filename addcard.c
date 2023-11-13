#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <time.h>
#include "addcard.h"
#include "safeinput.h"
#include "card.h"
#include "cardlist.h"
#include "adminmenu.h"
#include "fileio.h"

// Function to get a valid 4-digit card ID.
int getValidCardId() {
    int cardId;
    do {
        GetInputInt("\nEnter new Card-ID (4 digits): ", &cardId);
        if (cardId < 1000 || cardId > 9999) {
            printf("\nERROR: Card-ID must be exactly 4 digits. Please try again.\n");
        }
    } while (cardId < 1000 || cardId > 9999);
    return cardId;
}

void addCard(CARDLIST *cardList) {

    // Showing the current time, that will be implemented as a timestamp in the newCard.
    time_t current_time;
    struct tm* time_info;
    time(&current_time);
    time_info = localtime(&current_time);

    printf("\nSystem's current date: %d/%02d/%02d\n",
           time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday);
            
    // Initiate a new Card struct.
    CARD newCard;

    // Initiate a bool to check if the input cardid already exists.
    bool idExists;
    do {
        // Use the function to get 4 valid ID-digits.
        newCard.cardId = getValidCardId();

        // Loop through the cardlist, to check if the input matches an already existing cardid.
        idExists = false;
        for (int i = 0; i < cardList->count; i++) {
            if (cardList->list[i].cardId == newCard.cardId) {
                idExists = true;
                printf("\nERROR: Card-ID %d already exists. Please choose a different ID.\n", newCard.cardId);
                break;
            }
        }
    } while (idExists);

    // Asks the user if the new card should have access or not.
    newCard.accessGranted = GetBooleanInput("Should access be granted? (yes/no): ");

    // Setting current timestamp.
    strftime(newCard.timeStamp, sizeof(newCard.timeStamp), "%Y-%m-%d", time_info);
    
    // Resize the list with realloc to accommodate the new card.
    cardList->list = realloc(cardList->list, (cardList->count + 1) * sizeof(CARD));
    if (cardList->list == NULL) {
        // Handle memory allocation error.
        free(cardList->list);
        return;
    }
    
    // Add the new card to the list and increment the total count.
    cardList->list[cardList->count] = newCard;
    cardList->count++;

     // Save the updated card list to the .txt file.
    FILE *file = fopen("cardlist.txt", "a");
    if (file == NULL) {
        fprintf(stderr, "ERROR: Cannot open the file for writing.\n");
        free(cardList->list); // Free memory if file opening fails.
        return;
    }

    for (int i = 0; i < cardList->count; i++) {
    size_t write_size = fwrite(&(cardList->list[i]), sizeof(CARD), 1, file);
    if (write_size != 1) {
        fprintf(stderr, "ERROR: Cannot write card to file.\n");
        free(cardList->list); // Free memory if writing fails.
        break;
    }
}
    printf("\nNew card added successfully.\n");
    printf("\nTotal amount of cards in the system: %d\n", cardList->count);
    fclose(file);
}