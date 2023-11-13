#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <time.h>
#include "safeinput.h"
#include "card.h"
#include "cardlist.h"
#include "adminmenu.h"
#include "addcard.h"
#include "listcard.h"

// Added function definition, to resolve warnings during compilation.
void insertStartCards(CARDLIST *cardList);

int main (){   

    // Initialize a list for saving and presenting, all saved keycards.
    CARDLIST cardList;

    // Initialize 2 default keycards. Function presented in listcard.c.
    insertStartCards(&cardList);
    
    // Main Menu-function.
    adminMenu(&cardList);
    
    // Free up any used memory from the heap.
    free(cardList.list);
    
    return 0;
}