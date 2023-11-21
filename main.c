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

// Added function definition at the top, to resolve warnings during compilation.
// initializeCardList-function exists in fileio.c.
void initializeCardList(CARDLIST *cardList);

int main (){   

    printf("\n\t--- KEYCARD READER ---\n");

    // Initialize a list for saving and presenting, all saved keycards.
    CARDLIST cardList;

    // Initialize and load the card list.
    initializeCardList(&cardList);
    
    // Main Menu-function.
    adminMenu(&cardList);

    // After the user has quit the Admin Menu, save the textfile.
    // saveCardList-function in fileio.c.
    int saveResult = saveCardList("cardlist.txt", &cardList);
    if (saveResult == 1) {
        printf("Card list saved successfully.\n");
    } else {
        fprintf(stderr, "ERROR: Cannot save card list to file.\n");
        return 0;  // Exit with an error code
    }

    // Free up any used memory from the heap.
    free(cardList.list);
    return 0;
}