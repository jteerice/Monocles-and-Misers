#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "settlement_funcs.h"

settlement *createSettlement(settlement *head, int *settlementCount) {

    if (*settlementCount == 20) {
        printf("Settlement capacity reached!\n");
        return head;
    }
    head = addToBack(head, initSettlement(*settlementCount));
    settlementCount++;
    
    return head;
}

// Add to back so nodes will be ordered by index
settlement *addToBack(settlement *head, settlement *new) {

    settlement *tmp = head;

    if (tmp == NULL) head = new;
    else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
    return head;
}

settlement *initSettlement(int settlementCount) {

    char nameBuff[MAX_NAME_SIZE];

    printf("Please enter a name for your settlement (20 or less characters): ");
    fgets(nameBuff, MAX_NAME_SIZE, stdin);
    nameBuff[strcspn(nameBuff, "\n")] = '\0';

    settlement *new = (settlement*)malloc(sizeof(settlement));
    strncpy(new->name, nameBuff, MAX_NAME_SIZE);
    new->id = settlementCount;
    new->income = 100; // Base income is $100 for all settlements
    new->next = NULL;

    return new;  
}

void printSettlements(settlement *head) {
    printf("\n");
    while (head != NULL) {
        printf("%s\n", head->name);
        head = head->next;
    }
}