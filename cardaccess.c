#include <stdio.h>
#include <stdbool.h>
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
        char confirm;
        do {
            GetInputChar("Do you want to modify access? (y/n): ", &confirm);
        } while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N');

        if (confirm == 'y' || confirm == 'Y') {
            // Toggle the accessGranted value
            cardList->list[index].accessGranted = !cardList->list[index].accessGranted;
            printf("Access modified successfully.\nCard ID: %d\nAccess Granted: %s\n", cardList->list[index].cardId, cardList->list[index].accessGranted ? "Yes" : "No");
        } else {
            printf("Access not modified. Returning...\n");
        }
    } else {
        printf("Card ID not found. Please try again.\n");
    }
}
