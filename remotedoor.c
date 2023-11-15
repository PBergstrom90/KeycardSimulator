#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "remotedoor.h"
#include "safeinput.h"

    // Declaring a function for a timedelay, to let the door be open for 3 seconds.
    void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / 1000);
    }

    // Green doorlight, when the door is opening.
    void simulateGreenLamp() {
    printf("Currently the lamp is: ");
    printf("\033[1;32m");
    printf("GREEN\n");
    printf("\033[0m");
}

    // Red doorlight, when the door is locked.
    void simulateRedLamp() {
    printf("Currently the lamp is: ");
    printf("\033[1;31m");
    printf("RED\n");
    printf("\033[0m");
}
    // Simple function to simulate a remote door operation.
    void remoteDoor() {
        
        int openDoor = 0;
        printf("\nDo you wish to open the door? \n1. Yes\n2. No\n");
        GetInputInt("\nEnter: ", &openDoor);
        if(openDoor == 1){
            printf("\nDoor is opening...\n");
            simulateGreenLamp();
            printf("\n- Countdown - \n");
            printf("3...\n");
            delay(1000);
            printf("2...\n");
            delay(1000);
            printf("1...\n");
            delay(1000);

            printf("\nDoor is now locked.\n");
            simulateRedLamp();

        } else if (openDoor == 2){
            printf("\nDoor is locked...\n");
            simulateRedLamp();
        } else {
            printf("\nERROR: Enter '1' or '2'. Please try again.\n");
        }
    }