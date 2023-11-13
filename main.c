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
#include "remotedoor.h"
#include "listcard.h"
#include "scancard.h"

// Added function definition, to resolve warnings during compilation.
void insertStartCards(CARDLIST *cardList);

int main (){   

    CARDLIST cardList;

    insertStartCards(&cardList);
    adminMenu(&cardList);
    free(cardList.list);
    
    return 0;
}