#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "remotedoor.h"
#include "safeinput.h"

    // Declaring a function for a timedelay, to let the door be open for 3 seconds.
    void delay(unsigned int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / 1000);
    }

    void remoteDoor() {
        
        int openDoor = 0;
        printf("\nDo you wish to open the door? \n1. Yes\n2. No\n");
        GetInputInt("\nEnter: ", &openDoor);
        if(openDoor == 1){
            printf("\nDoor is opening...\n");
            printf("Currently the lamp is: ");
            printf("\033[1;32m"); 
            printf("GREEN\n"); 
            printf("\033[0m");
            printf("\n- Countdown - \n");
            printf("3...\n");
            delay(1000);
            printf("2...\n");
            delay(1000);
            printf("1...\n");
            delay(1000);

            printf("\nDoor is now locked.\n");
            printf("Currently the lamp is: ");
            printf("\033[1;31m"); 
            printf("RED\n"); 
            printf("\033[0m");

        } else if (openDoor == 2){
            printf("\nDoor is locked...\n");
            printf("Currently the lamp is: ");
            printf("\033[1;31m"); 
            printf("RED\n"); 
            printf("\033[0m");
        } else {
            printf("\nAn error has occured. Please try again.\n");
        }
    }