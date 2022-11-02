#include "../header/union_find.h"

/* Union-Find Functions */

void buildRoad(int size[], int UF[], settlement *head) {

    char *settlement1 = (char*)malloc(sizeof(char) * MAX_NAME_SIZE);
    char *settlement2 = (char*)malloc(sizeof(char) * MAX_NAME_SIZE);
    bool set1 = true;
    bool set2 = true;

    printf("Please enter the first settlement you would like to connect: ");
    set1 = getName(head, settlement1);
    while (set1 == false) {
        printf("That settlement doesn't exist! Please enter a valid settlement: ");
        set1 = getName(head, settlement1);
    }
    printf("Please enter the second settlement you would like to connect: ");
    set2 = getName(head, settlement2);
    while (settlement2 == false) {
        printf("That settlement doesn't exist! Please enter a valid settlement: ");
        set1 = getName(head, settlement2);
    }

    connect(size, UF, head, settlement1, settlement2);
    printf("%s and %s have been connected with a road!\n", settlement1, settlement2);
    free(settlement1);
    free(settlement2);
}

bool getName(settlement *head, char *settlementName) {

    fgets(settlementName, MAX_NAME_SIZE, stdin);
    settlementName[strcspn(settlementName, "\n")] = '\0';

    settlement *tmp = head;
    while (tmp != NULL) {
        if (strcmp(tmp->name, settlementName) == 0) return true;
        tmp = tmp->next;
    }
    return false;
}

void connect(int size[], int UF[], settlement *head, char *settlement1, char *settlement2) {

    int id1 = find(settlement1, head);
    int id2 = find(settlement2, head);
    int root1 = findRoot(UF, id1);
    int root2 = findRoot(UF, id2);
    Union(size, UF, root1, root2);

}

int find(char *settlementName, settlement *head) {

    settlement *tmp = head;
    while (tmp != NULL) {
        if (strcmp(tmp->name, settlementName)) return tmp->id;
        tmp = tmp->next;
    }
    return -1;
}

int findRoot(int UF[], int id) {

    int i = id;
    int j;
    int k;

    while (UF[i] != i) {
        i = UF[i];
    }
    j = i;
    
    // Path compression loop
    i = id;
    while (UF[i] != i) {
        k = UF[i];
        UF[i] = j;
        i = k;
    }

    return j;
}

void Union(int size[], int UF[], int id1, int id2) {

    int i = findRoot(UF, id1);
    int j = findRoot(UF, id2);

    if (i == j) {
        printf("Already connected!\n");
    }
    else if (size[i] < size[j]) {
        UF[i] = j;
        size[j] += size[i];
    }
    else {
        UF[j] = i;
        size[i] += size[j];
    }
}

void printConnectedSettlements(int UF[], settlement* head) {

    char* settlementName1 = (char*)malloc(sizeof(char) * MAX_NAME_SIZE);
    char* settlementName2 = (char*)malloc(sizeof(char) * MAX_NAME_SIZE);
    bool set1 = true;
    bool set2 = true;
    int id1;
    int id2;
    int i;
    int j;

    printf("Please enter the first settlement: ");
    set1 = getName(head, settlementName1);
    while (set1 == false) {
        printf("That settlement doesn't exist! Please enter a valid settlement: ");
        set1 = getName(head, settlementName1);
    }

    printf("Please enter the second settlement: ");
    set2 = getName(head, settlementName2);
    while (set2 == false) {
        printf("That settlement doesn't exist! Please enter a valid settlement: ");
        set1 = getName(head, settlementName1);
    }

    id1 = find(settlementName1, head);
    id2 = find(settlementName2, head);
    i = findRoot(UF, id1);
    j = findRoot(UF, id2);

    if (i == j) printf("%s and %s are connected.\n", settlementName1, settlementName2);
    else printf("%s and %s are not connected.\n", settlementName1, settlementName2); 
}