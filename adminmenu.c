#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <conio.h>
#include "safeinput.h"
#include "card.h"
#include "cardlist.h"
#include "addcard.h"
#include "adminmenu.h"
#include "remotedoor.h"

void adminMenu(CARDLIST *cardList) {
    
    bool isRunning = true;
    while(isRunning){
    printf("\n\t--- ADMIN MENU ---\n");
    printf("1. Remote Door Access.\n");
    printf("2. List All Cards In System\n");
    printf("3. Add New Card\n");
    printf("4. Add/Remove Card Access\n");
    printf("5. Fake Test Scan Card\n");
    printf("6. Exit\n");
    int sel = 0;
    GetInputInt("Choose: ", &sel);
    switch(sel){
    
    case 1: 
        printf("\n\t--- REMOTE DOOR ACCESS ---\n");
        remoteDoor();
    break;
    
    case 2: 
        printf("\n\t--- LIST CARDS IN SYSTEM ---\n");
        listCard(&cardList);
    break;
    
    case 3:
        printf("\n\t--- ADD NEW CARD ---\n");
        addCard(&cardList);
    break;

    case 4: 
        printf("\n\t--- ADD/REMOVE CARD ACCESS ---\n");
        cardAccess(&cardList);
    break; 
    
    case 5:
        printf("\n\t--- FAKE TEST SCAN CARD ---\n");
        scanCard(&cardList);
    break;
    
    case 6: 
        printf("\nProgram closing...\n");
        printf("Bye!\n");
        free(cardList);
        isRunning = false;
    break;
    
    default:
        printf("\nWrong entry. Please try again.\n");
    break; 
    }
}
}