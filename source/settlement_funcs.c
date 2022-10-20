#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "main.h"

#define MAX_NAME_SIZE 21

int createSettlement(Settlement settlements[], int settlementCount) {

    if (settlementCount == 20) {
        printf("Settlment capacity reached!")
        return 20;
    }

    char settlementName[MAX_NAME_SIZE];
    printf("Please enter settlement name: ");
    fgets(settlementName, 20, stdin);
    printf("%s\n", settlementName);



    return settlementCount++;
}