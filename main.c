#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <unistd.h> // For access function.
#include <time.h>
#include "safeinput.h"
#include "card.h"
#include "cardlist.h"
#include "adminmenu.h"
#include "addcard.h"
#include "listcard.h"
#include "fileio.h"

// Added function definition, to resolve warnings during compilation.
void insertStartCards(CARDLIST *cardList);
void listCardToFile(const CARDLIST *cardList, const char *filename);

// Function to initialize and load the card list from file.
void initializeCardList(CARDLIST *cardList) {
    // Initialize the card list
    cardList->list = NULL;
    cardList->count = 0;
    
    // Load the card list from a file.
    int loadResult = loadCardList("cardlist.txt", cardList);

    // Check the load result.
    if (loadResult == 1) {
        // File doesn't exist, insert default cards and save.
        printf("\nNo existing card list found. Initializing with default cards...\n");
        insertStartCards(cardList);
        listCardToFile(cardList, "cardlist.txt");
        //saveCardList("cardlist.txt", cardList);
    } else if (loadResult == 2){
        printf("\nCard list found.\nCard list loaded successfully.\n");
    } else {
        // Error loading the file. Print an error message and exit the program.
        fprintf(stderr, "ERROR: Cannot load the card list from file.\n");
        exit(EXIT_FAILURE);
    }
}

int main (){   

    // Initialize a list for saving and presenting, all saved keycards.
    CARDLIST cardList;

    // Initialize and load the card list
    initializeCardList(&cardList);

    // Main Menu-function.
    adminMenu(&cardList);

    int saveResult = saveCardList("cardlist.txt", &cardList);
    
    if (saveResult == 2) {
        printf("Card list saved successfully.\n");
    } else {
        fprintf(stderr, "ERROR: Cannot save card list to file.\n");
        return 0;  // Exit with an error code
    }

    // Free up any used memory from the heap.
    free(cardList.list);
    
    return 0;
}