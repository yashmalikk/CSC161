
/*
* A program to make and store a grocery list.
* Author: Yash Malik
* Class: CSC161 w/ Prof. Jimenez 
* Date: April. 22nd, 2024
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 128
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int count;
} GItem;

void add(GItem **groceryList, int *listSize);
void lookup(GItem *groceryList, int listSize);
void print(GItem *groceryList, int listSize);

int main() {
    GItem *GItem = NULL;
    int listSize = 0;

    while (1) {
        char command[MAX_INPUT_LENGTH];
        printf("What do you want to do? Type one of the following commands:\n"
               "add: add an item\n"
               "lookup: look up an item\n"
               "print: print the list\n"
               "exit: exit the program\n"
               "Command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            add(&GItem, &listSize);
        } else if (strcmp(command, "lookup") == 0) {
            lookup(GItem, listSize);
        } else if (strcmp(command, "print") == 0) {
            print(GItem, listSize);
        } else if (strcmp(command, "exit") == 0) {
            free(GItem );
            break;
        } else {
            printf("Unrecognized command.\n");
        }
    }

    return 0;
}

void add(GItem **groceryList, int *listSize) {
    char itemName[MAX_NAME_LENGTH];
    int itemCount;

    printf("What item would you like to add?\n>> ");
    scanf("%s", itemName);

    printf("How many would you like?\n>> ");
    while (scanf("%d", &itemCount) != 1 || itemCount < 0) {
        printf("Invalid Number. Try again.\nHow many would you like?\n");
        while (getchar() != '\n'); 
    }

    
    int i;
    for (i = 0; i < *listSize; i++) {
        if (strcmp((*groceryList)[i].name, itemName) == 0) {
            (*groceryList)[i].count += itemCount;
            printf("Item added successfully.\n");
            return;
        }
    }

    
    *listSize += 1;
    *groceryList = realloc(*groceryList, sizeof(GItem) * (*listSize));
    if (*groceryList == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    
    strcpy((*groceryList)[*listSize - 1].name, itemName);
    (*groceryList)[*listSize - 1].count = itemCount;

    printf("Item added successfully.\n");
}

void lookup(GItem *groceryList, int listSize) {
    char itemName[MAX_NAME_LENGTH];
    printf("What item are you looking for?\n>> ");
    scanf("%s", itemName);

    int i;
    for (i = 0; i < listSize; i++) {
        if (strcmp(groceryList[i].name, itemName) == 0) {
            printf("You need %d %s\n", groceryList[i].count, groceryList[i].name);
            return;
        }
    }

    printf("I didn't find %s on the list.\n", itemName);
}

void print(GItem *groceryList, int listSize) {
    if (listSize == 0) {
        printf("The list is empty.\n");
    } else {
        printf("Grocery List:\n");
        int i;
        for (i = 0; i < listSize; i++) {
            printf("- %d %s\n", groceryList[i].count, groceryList[i].name);
        }
    }
}
