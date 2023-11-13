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
    int sel = 0;
    GetInputInt("Choose: ", &sel);
    switch(sel){
    
    case 1: 
        // (OK)
        printf("\n\t--- REMOTE DOOR ACCESS ---\n");
        remoteDoor();
    break;
    
    case 2: 
        // (OK)
        printf("\n\t--- LIST CARDS IN SYSTEM ---\n");
        listCard(cardList);
    break;
    
    case 3:
        // (OK)
        printf("\n\t--- ADD NEW CARD ---\n");
        addCard(cardList);
    break;

    case 4: 
        // (OK)
        printf("\n\t--- ADD/REMOVE CARD ACCESS ---\n");
        cardAccess(cardList);
    break; 
    
    case 5:
        // (OK)
        printf("\n\t--- SCAN CARD ---\n");
        scanCard(cardList);
    break;
    
    case 6: 
        // (OK)
        printf("\nProgram closing...\n");
        free(cardList);
        isRunning = false;
    break;
    
    default:
        printf("\nERROR: Wrong entry. Please try again.\n");
    break; 
    }
}
}