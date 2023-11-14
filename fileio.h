#ifndef __FILEIO_H
#define __FILEIO_H
#include "cardlist.h"

int saveCardList(char *filename, const CARDLIST *cardList);
int loadCardList(const char* filename, CARDLIST* cardList);

#endif  // FILEIO_H
