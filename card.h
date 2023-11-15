#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "safeinput.h"
#ifndef __CARD_H
#define __CARD_H

typedef struct {
    int cardId;
    bool accessGranted;
    char timeStamp[20];
} CARD;

#endif