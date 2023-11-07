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
#include "addcard.h"
#include "remotedoor.h"

// Använd "return" för att komma ur en meny while-loop.
// Anropa inte funktionen på nytt (stackoverflow).

int main (){   

    CARDLIST cardList;
    adminMenu(&cardList);
    
    return 0;
}