#include <stdio.h>
#include <string.h>
#include "fileio.h"
#include "card.h"
#include "cardlist.h"

int loadCardList(const char* filename, CARDLIST* cardList) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        // Return 1 to indicate failure
        return 1;
    }

    // Initialize the card list
    cardList->list = NULL;
    cardList->count = 0;

    char line[250];

    // Read each line from the file
    while (fgets(line, sizeof(line), file) != NULL) {
        // Check if the line starts with "--- CARD NR"
        if (strncmp(line, "--- CARD NR", 11) == 0) {
            // Parse the card information
            CARD card;
            // Read the next three lines for card ID, access granted, and timestamp
            if (fgets(line, sizeof(line), file) != NULL) {
                sscanf(line, "Card ID: %d", &(card.cardId));  // Adjusted format specifier
            }
            if (fgets(line, sizeof(line), file) != NULL) {
                sscanf(line, "Access Granted: %s", line);
                // Convert the accessGranted field to a boolean
                card.accessGranted = (strcmp(line, "Yes") == 0) ? true : false;
            }
            if (fgets(line, sizeof(line), file) != NULL) {
                sscanf(line, "Timestamp: %s", card.timeStamp);  // Adjusted format specifier
                // Increment the card count and reallocate the list
                cardList->list = realloc(cardList->list, (cardList->count + 1) * sizeof(CARD));
                cardList->list[cardList->count] = card;
                cardList->count++;
            }
        }
    }

    fclose(file);
    // Return 2 to indicate success.
    return 2;
}

int saveCardList(char* filename, const CARDLIST* cardList) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("ERROR: Cannot open file for writing");
        // Return 1 to indicate failure
        return 1;
    }

    // Iterate through each card and write its information as a string to the file
    for (int i = 0; i < cardList->count; i++) {
        fprintf(file, "--- CARD NR %d ---\n", i + 1);
        fprintf(file, "Card ID: %d\nAccess Granted: %s\nTimestamp: %s\n",
                cardList->list[i].cardId,
                cardList->list[i].accessGranted ? "Yes" : "No",
                cardList->list[i].timeStamp);
    }

    fclose(file);
    // Return 2 to indicate success.
    return 2;
}

