#ifndef DEVELOPMENT_HASH_FUNCS_H
#define DEVELOPMENT_HASH_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_SIZE 21
#define MAX_SETTLEMENTS 20
#define TABLE_SIZE 20
#define BUFFER_SIZE 100

typedef struct {

    char developmentName[MAX_NAME_SIZE];
    unsigned int hash;
    unsigned int income;
    struct development* next;

} development;

void createDevelopment(development* hashTable);
unsigned int hash(char* developmentName);

#endif