#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "settlement_funcs.h"

#define MAX_NAME_SIZE 21
#define MAX_SETTLEMENTS 20

void buildRoad(int size [], int UF[], settlement *head);
bool getName(settlement *head, char *settlementName);
void connect(int size[], int UF[], settlement *head, char *settlement1, char *settlement2);
int find(char *settlementName, settlement *head);
int findRoot(int UF[], int id);
void Union(int size[], int UF[], int id1, int id2);
void printConnectedSettlements(int UF[], settlement* head);

#endif

