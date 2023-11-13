#include <stdio.h>
#include "fileio.h"
#include "card.h"
#include "cardlist.h"

int saveCardList(const char* filename, const CARDLIST* cardList) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("ERROR: Cannot open file for writing");
        // Return 1 to indicate failure
        return 1;
    }

    fwrite(cardList, sizeof(CARDLIST), 1, file);
    fclose(file);
    // Return 2 to indicate success.
    return 2;
}

int loadCardList(const char* filename, CARDLIST* cardList) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        // Return 1 to indicate failure
        return 1;
    }

    fread(cardList, sizeof(CARDLIST), 1, file);

    fclose(file);
    // Return 2 to indicate success.
    return 2;
}