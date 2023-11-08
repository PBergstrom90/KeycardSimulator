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
#include "listcard.h"

void PrintCard (const CARD *p){
    printf("CARD ID: %s\n", p->cardId);
    if(p->accessGranted == true){
    printf("ACCESS: GRANTED\n");
    } else {
        printf("ACCESS: DENIED\n");
    } 
    printf("TIMESTAMP: %s\n", p->timeStamp);
}

void listCard(const CARDLIST *cardList) {

for (int i = 0; i < cardList->count;i++){
     printf("\nCARD NR %d: \n", i+1);
     PrintCard(&(cardList->list[i]));
     }

}