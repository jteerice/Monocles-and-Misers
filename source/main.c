#include <stdio.h>
#include <stdlib.h>
#include "settlement_funcs.h"
// HEADER
#include <stdbool.h>
#include <string.h>

#define MAX_SETTLEMENTS 20

// Function prototypes
int getChoice();
void clear();
void initUnionFind(int UF[], int max);
// HEADER
void buildRoad(int UF[], settlement *head);
bool getName(settlement *head, char *settlementName);
void connect(int UF[], settlement *head, char *settlement1, char *settlement2);

int main () {

    int choice = 0;
    settlement *head = NULL;
    int settlementCount = 0; // This will be used to assign an ID to each node, and subsequently be used in the Union-Find datastructure for linking.
    int *UF = (int*)malloc(sizeof(int) * MAX_SETTLEMENTS);

    initUnionFind(UF, MAX_SETTLEMENTS); // Initialize Union-Find data structure with the the the index as the dereferenced value

    printf("+-------------------------------Welcome to Monocles and Misers!---------------------------------+\n");
    printf("|                                                                                               |\n");
    printf("| In this game, you will play the role of a curmudgeonly rich miser.                            |\n");
    printf("| Your objective will be to create and develop settlements in order to fatten your own pockets. |\n");
    printf("| In anycase, lets get started. Time is money after all!                                        |\n");
    printf("|                                                                                               |\n");
    printf("|                                                                                               |\n");
    printf("+-----------------------------------------------------------------------------------------------+\n\n");

    printf("Are you ready? ( Enter 1 for Yes ): ");
    while (choice != 1) {
        choice = getChoice();
        if (choice == 1) break;
        else printf("Please enter 1 to continue.\n");
    }

    while (1) {
        printf("\n+-----------What would you like to do?----------+\n");
        printf("|                                               |\n");
        printf("| 1) Retrive a list of settlements              |\n");
        printf("| 2) Create a new settlement (Max 20)           |\n");
        printf("| 3) Build a road between two settlements       |\n");
        printf("| 4) Develop settlement                         |\n");
        printf("| 5) Retrieve current income from settlements   |\n");
        printf("| 6) Quit                                       |\n");
        printf("+-----------------------------------------------+\n");

            printf("\nPlease enter a choice between 1 and 6: ");
            switch (getChoice()) {
                case 1:
                    printSettlements(head);
                    break;
                case 2:
                    head = createSettlement(head, &settlementCount);
                    break;
                case 3:
                    buildRoad(UF, head);
                    break;
                case 4:
                    //developSettlement();
                    break;
                case 5:
                    //retrieveIncome();
                    break;
                case 6:
                    printf("Thank you for playing..\n");
                    printf("Goodbye!\n");
                    exit(1);
                default:
                    printf("Please select valid option: \n");
                    clear();
                    break;
            }
    }
    
    return 0;
}

int getChoice() {

    char buf[5];
    int choice = 0;

    fgets(buf, 5, stdin);
    sscanf(buf, "%d", &choice);
    
    return choice;
}

void initUnionFind(int UF[], int max) {

    for (int i = 0; i < max; i++) {
        UF[i] = i;
    }
}

void clear() {
    while (getchar() != '\n');
}

void buildRoad(int UF[], settlement *head) {

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

void connect(int UF[], settlement *head, char *settlement1, char *settlement2) {

}

