#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_SIZE 21

typedef struct settlement_def {

    char name[MAX_NAME_SIZE]; // Limited to 20 characters
    int id;
    int income;
    struct settlement *next;

} settlement;

void getString(char nameBuff[]);
settlement *addSettlement(settlement *head, settlement *new);

settlement *createSettlement(settlement *head, int *settlementCount) {
    
    char *nameBuff = malloc(sizeof(char) * 21);
    settlement *new = malloc(sizeof(settlement));

    printf("Please enter a name for your settlement (20 or less LETTERS): ");
    getString(nameBuff);

    strncpy(new->name, nameBuff, MAX_NAME_SIZE);
    new->id = *settlementCount;
    new->income = 100;
    new->next = NULL;

    head = addSettlement(head, new);
    printSettlements(head);

    settlementCount++;
    return head;
}

void printSettlements(settlement *head) {
    while (head != NULL) {
        printf("%s\n", head->name);
        head = head->next;
    }
}

void getString(char nameBuff[]) {

    fgets(nameBuff, MAX_NAME_SIZE, stdin);
    nameBuff[strcspn(nameBuff, "\n")] = '\0';
    for (int i = 0; i < strlen(nameBuff); i++) {
        if (!isalpha(nameBuff[i])) {
            printf("Please enter a valid name (Only letters and 20 or less characters): ");
            getString(nameBuff);
        }
    }
}

settlement *addSettlement(settlement *head, settlement *new) {

    new->next = head;
    head = new;

    return head;
}



