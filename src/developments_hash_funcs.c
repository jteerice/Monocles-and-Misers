#include "../header/developments_hash_funcs.h"

void createDevelopment(development* hashTable) {

    development* new = (development*)malloc(sizeof(development));
    char* developmentName = (char*)malloc(sizeof(char) * MAX_NAME_SIZE);
    char* buf = (char*)malloc(sizeof(char) * BUFFER_SIZE);
    unsigned int hashVal = 0;
    unsigned int income = 0;

    // Retrieve development data
    printf("What type of development will this be? (School, Market, Hospital.. ) ");
    fgets(developmentName, MAX_NAME_SIZE, stdin);
    printf("How much income will this development produce? ($1-9999) ");
    fgets(buf, BUFFER_SIZE, stdin);
    sscanf(buf, "%u", &income);
    hashVal = hash(developmentName);

    // Copy data into development struct
    strncpy(new->developmentName, developmentName, MAX_NAME_SIZE);
    new->income = income;
    new->hash = hashVal;

    //hashTable[hashVal] = 

}

unsigned int hash(char* developmentName) {

    unsigned int len = strnlen(developmentName, MAX_NAME_SIZE);
    unsigned int hashVal = 0;
    int i = 0;

    for (i = 0; i < len; i++) {
        hashVal += developmentName[i];
        hashVal = (hashVal * developmentName[i]) % TABLE_SIZE;
    }

    return hashVal;
}
