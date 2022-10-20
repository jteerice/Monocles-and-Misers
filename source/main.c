#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_SIZE 21

// Settlement struct
typedef struct settlement_def {

    char name[MAX_NAME_SIZE]; // Limited to 20 characters
    int id;
    int income;
    struct settlement_def *next;

} settlement;

// Function prototypes
int getChoice();
void clear();
settlement *createSettlement(settlement *head, int *settlementCount);
void printSettlements(settlement *head);
settlement *addToBack(settlement *head, settlement *new);
settlement *initSettlement(int settlementCount);

int main () {

    int choice = 0;
    settlement *head = NULL;
    int settlementCount = 0;

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
        printf("| 2) Create a new settlement                    |\n");
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
                    //buildRoad();
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

void clear() {
    while (getchar() != '\n');
}

