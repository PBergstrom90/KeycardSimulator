#include <stdio.h>
#include <dos.h>
#include "safeinput.h"
#ifndef __CARD_H
#define __CARD_H

typedef struct {
    char cardId[20];
    bool accessGranted;

} CARD;

#endif