#include "settlement_funcs.h"

settlement *createSettlement(settlement *head, int *settlementCount) {

    head = addToBack(head, initSettlement(*settlementCount));
    settlementCount++;
    
    return head;
}

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
    new->income = 100;
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