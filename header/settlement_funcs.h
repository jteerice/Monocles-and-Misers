#ifndef SETTLEMENT_FUNCS_H
#define SETTLEMENT_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_SIZE 21
#define MAX_SETTLEMENTS 20

typedef struct settlement_def {

    char name[MAX_NAME_SIZE]; // Limited to 20 characters
    int id;
    int income;
    struct settlement_def *next;

} settlement;

settlement *createSettlement(settlement *head, int *settlementCount);
void printSettlements(settlement *head);
settlement *addToBack(settlement *head, settlement *new);
settlement *initSettlement(int settlementCount);

void buildRoad(int size [], int UF[], settlement *head);
bool getName(settlement *head, char *settlementName);
void connect(int size[], int UF[], settlement *head, char *settlement1, char *settlement2);
int find(char *settlementName, settlement *head);
int findRoot(int UF[], int id);
void Union(int size[], int UF[], int id1, int id2);

#endif