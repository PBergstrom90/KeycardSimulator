#include <stdio.h>
#include "safeinput.h"
// including remotedoor.h to access the red/green light and delay-functions.
#include "remotedoor.h"

#ifndef __SCAN_CARD_H
#define __SCAN_CARD_H

void simulateGreenLamp();
void simulateRedLamp();
void delay();
void scanCard(CARDLIST *cardList);


#endif