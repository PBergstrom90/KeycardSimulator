#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "cardlist.h"
#include "scancard.h"
#include "safeinput.h"
// Using red/green-light and delay-function from remotedoor.c
#include "remotedoor.h"

void scanCard(CARDLIST *cardList) {
    int cardId;
    GetInputInt("\nEnter the card ID-number: ", &cardId);

    int index = -1;  // Default value indicating the card ID is not found
    for (int i = 0; i < cardList->count; i++) {
        if (cardList->list[i].cardId == cardId) {
            index = i;  // Card ID found
            break;
        }
    }

    if (index != -1) {
        // Card ID found
        printf("\nCard ID %d found.\n", cardId);
        if (cardList->list[index].accessGranted) {
            // Access is granted, simulate a green lamp
            printf("Access: GRANTED.\n");
            printf("\nDoor is opening...\n");
            simulateGreenLamp();
            printf("\n- Countdown - \n");
            printf("3...\n");
            delay(1000);
            printf("2...\n");
            delay(1000);
            printf("1...\n");
            delay(1000);

            printf("\nDoor is now locked.\n");
            simulateRedLamp();
        } else {
            // Access is denied, simulate red lamp
            printf("Access: DENIED.\n");
            printf("\nDoor is locked...\n");
            simulateRedLamp();
        }
    } else {
        // Card ID not found
        printf("\nERROR: Card ID %d not found.\nAccess: DENIED.\n", cardId);
        printf("\nDoor is locked...\n");
        simulateRedLamp();
    }
}
