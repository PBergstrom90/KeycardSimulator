#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "card.h"
#ifndef __CARDLIST_H
#define __CARDLIST_H

typedef struct {
    CARD *list;
    int count;
} CARDLIST;

#endif