#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "safeinput.h"
#ifndef __CARD_H
#define __CARD_H

typedef struct {
    char cardId[20];
    bool accessGranted;
    char timeStamp[40];

} CARD;

#endif