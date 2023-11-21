#include <stdio.h>
#include <string.h>
#include "fileio.h"
#include "listcard.h"
#include "card.h"
#include "cardlist.h"

// Added function definition at the top, to resolve warnings in the initializeCardList-function.
void insertStartCards(CARDLIST *cardList);
void writeCardToFile(const CARDLIST *cardList, const char *filename);



/*  This following function is designed to run at the start of the program.
    The purpose is to check if there is an existing cardlist.txt-file from before, 
    or if a new file has to be created. */
void initializeCardList(CARDLIST *cardList) {
    // Initialize the card list
    cardList->list = NULL;
    cardList->count = 0;
    
// Check if the program can load an existing cardlist.txt, or have to create a new one. 
// loadCardList-function in fileio.c.
int loadResult = loadCardList("cardlist.txt", cardList);

// Check the load result.
if (loadResult == 0) {
    // No textfile exists yet, insert default startcards and save.
    printf("\nNo existing card list found. Initializing with default cards...\n");
    insertStartCards(cardList);
    writeCardToFile(cardList, "cardlist.txt");
} else if (loadResult == 1) {
    // "cardfile.txt" exists. Load it and read from it.
    printf("\nCard list found.\nCard list loaded successfully.\n");
} else {
    // Error loading the file. Print an error message and exit the program.
    fprintf(stderr, "ERROR: Cannot load the card list from file.\n");
    exit(EXIT_FAILURE);
    }
}

/*  This following function goes through all saved CARDs in the initiated CARDLIST. 
    Calculates buffersize and then allocates memory for the CARD-string. 
    Each CARD in the CARDLIST is then formated and printed to the file. */
void writeCardToFile(const CARDLIST *cardList, const char *filename) {
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

// Function for loading all info from "cardlist.txt".
int loadCardList(const char* filename, CARDLIST* cardList) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        // Return 0 to indicate failure.
        return 0;
    }
    // Initialize the card list.
    cardList->list = NULL;
    cardList->count = 0;
    char line[250];
    // Read each line from the file.
    while (fgets(line, sizeof(line), file) != NULL) {
        // Check if the line starts with "--- CARD NR".
        if (strncmp(line, "--- CARD NR", 11) == 0) {
            // Parse the card information.
            CARD card;
            // Read the next three lines for card ID, access granted, and timestamp.
            if (fgets(line, sizeof(line), file) != NULL) {
                sscanf(line, "Card ID: %d", &(card.cardId));  // Adjusted format specifier
            }
            if (fgets(line, sizeof(line), file) != NULL) {
                sscanf(line, "Access Granted: %s", line);
                // Convert the accessGranted field to a boolean.
                card.accessGranted = (strcmp(line, "Yes") == 0) ? true : false;
            }
            if (fgets(line, sizeof(line), file) != NULL) {
                sscanf(line, "Timestamp: %s", card.timeStamp);  // Adjusted format specifier.
                // Increment the card count and reallocate the list.
                cardList->list = realloc(cardList->list, (cardList->count + 1) * sizeof(CARD));
                cardList->list[cardList->count] = card;
                cardList->count++;
            }
        }
    }
    fclose(file);
    // Return 1 to indicate success.
    return 1;
}

// Function to save all CARDS in CARDLIST to "cardfile.txt".
int saveCardList(char* filename, const CARDLIST* cardList) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("ERROR: Cannot open file for writing");
        // Return 0 to indicate failure.
        return 0;
    }
    // Iterate through each card and write its information as a string to the file.
    for (int i = 0; i < cardList->count; i++) {
        fprintf(file, "--- CARD NR %d ---\n", i + 1);
        fprintf(file, "Card ID: %d\nAccess Granted: %s\nTimestamp: %s\n",
                cardList->list[i].cardId,
                cardList->list[i].accessGranted ? "Yes" : "No",
                cardList->list[i].timeStamp);
    }
    fclose(file);
    // Return 1 to indicate success.
    return 1;
}