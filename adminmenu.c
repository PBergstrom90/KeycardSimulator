#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include "safeinput.h"
#include "card.h"
#include "cardlist.h"
#include "cardaccess.h"
#include "adminmenu.h"
#include "addcard.h"
#include "remotedoor.h"
#include "listcard.h"
#include "scancard.h"

void adminMenu(CARDLIST *cardList) {
    
    bool isRunning = true;
    while(isRunning){
    printf("\n\t--- ADMIN MENU ---\n");
    printf("1. Remote Door Access.\n");
    printf("2. List All Cards In System\n");
    printf("3. Add New Card\n");
    printf("4. Add/Remove Card Access\n");
    printf("5. Scan Card\n");
    printf("6. Exit\n");
    int select = 0;
    GetInputInt("Choose: ", &select);
    switch(select){
    
    case 1: 
        // Simulating opening a locked door.
        printf("\n\t--- REMOTE DOOR ACCESS ---\n");
        remoteDoor();
    break;
    
    case 2: 
        // List all the registered cards. 2 cards are added by default.
        printf("\n\t--- LIST CARDS IN SYSTEM ---\n");
        listCard(cardList);
    break;
    
    case 3:
        // Let the user add a new card.
        printf("\n\t--- ADD NEW CARD ---\n");
        addCard(cardList);
    break;

    case 4: 
        // Let the user modify specific card access.
        printf("\n\t--- ADD/REMOVE CARD ACCESS ---\n");
        cardAccess(cardList);
    break; 
    
    case 5:
        // Use cardID from the register to simulate a doorscanner.
        printf("\n\t--- SCAN CARD ---\n");
        scanCard(cardList);
    break;
    
    case 6: 
        // Exit the program.
        printf("\nProgram closing...\n");
        isRunning = false;
    break;
    
    default:
        // In case of input failure.
        printf("\nERROR: Wrong entry. Please try again.\n");
    break; 
    }
}
}