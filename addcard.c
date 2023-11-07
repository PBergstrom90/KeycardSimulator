#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <conio.h>
#include <time.h>
#include "safeinput.h"
#include "card.h"
#include "cardlist.h"
#include "adminmenu.h"

void addCard(CARDLIST *cardList) {

    time_t current_time;
    struct tm* time_info;
    time(&current_time);
    time_info = localtime(&current_time);

    printf("\nSystem's current date and time: %d/%02d/%02d %02d:%02d\n",
           time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday,
           time_info->tm_hour, time_info->tm_min);
            
   /* if(cardList->count == 0){
             CARDLIST cardList->list = (CARDLIST *)malloc(sizeof(CARDLIST));
             cardList->count++;
         } else {
             cardList->count++;
             cardList = (CARDLIST *)realloc(list, sizeof(CARDLIST) * cardList->count);
         }
             GetInput("\nEnter new Card-ID: ",cardList[count-1]->cardId, 20);
    */
}