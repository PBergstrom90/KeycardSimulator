#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "cardaccess.h"
#include "safeinput.h"
#include "card.h"
#include "cardlist.h"

void cardAccess(CARDLIST *cardList) {
    
    int cardId = 0;
    GetInputInt("\nEnter the card ID-number: ", &cardId);

    // Search for the card ID in the list
    int index = -1;  // Default value indicating the card ID is not found
    for (int i = 0; i < cardList->count; i++) {
        if (cardList->list[i].cardId == cardId) {
            index = i;  // Card ID found
            break;
        }
    }
    if (index != -1) {
        // Card ID found, display current access status
        printf("\nCard ID: %d\nAccess Granted: %s\n", cardList->list[index].cardId,
               cardList->list[index].accessGranted ? "Yes" : "No");

        // Ask for confirmation to modify access. 
        // Adding a do-while to make sure, that the correct value (y/n) has been entered.
        char confirm[6];
        do {
            GetInput("\nShould access be granted? (yes/no): ", confirm, sizeof(confirm));
            // Convert the input to lowercase, for easy user input.
            for (int i = 0; confirm[i]; i++) {
                confirm[i] = tolower(confirm[i]);
            }
            if (strcmp(confirm, "yes") == 0) {
                // Toggle the accessGranted value
                cardList->list[index].accessGranted = true;
                printf("\nAccess modified successfully.\nCard ID: %d\nAccess Granted: Yes\n", cardList->list[index].cardId);
            } else if (strcmp(confirm, "no") == 0) {
                cardList->list[index].accessGranted = false;
                printf("\nAccess modified successfully.\nCard ID: %d\nAccess Granted: No\n", cardList->list[index].cardId);
            } else {
                printf("\nERROR: Invalid input. Please enter 'yes' or 'no'.\n");
            }
        } while (!(strcmp(confirm, "yes") == 0 || strcmp(confirm, "no") == 0));
    } else {
        printf("ERROR: Card ID not found. Please try again.\n");
    }
}
