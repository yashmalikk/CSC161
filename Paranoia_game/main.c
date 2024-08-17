/*
* A program to simulate the game assassin.
  * Author: Yash Malik
* Class: CSC161 w/ Prof. Jimenez 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player_list.h"

int main() {

    player_list_t target_ring;
    player_list_t tagged_list;
    player_list_init(&target_ring);
    player_list_init(&tagged_list);


    printf("Enter a player's name (press enter to begin game): ");
    fflush(stdout);

    char* line = NULL;
    size_t line_capacity = 0;
    ssize_t line_length;


    while ((line_length = getline(&line, &line_capacity, stdin)) != -1) {

        line[line_length - 1] = '\0';

        if (strcmp(line, "") == 0) {        //if block for user input of names
            break;
        } else {
            player_list_append(&target_ring, line);
            printf("Enter another player's name: ");
            fflush(stdout);
        }
    }


    printf("Target Ring:\n");
    print_as_target_ring(&target_ring);

    printf("\nThere are %zu people left.\n", player_list_length(&target_ring));


    while (player_list_length(&target_ring) > 1) {

        printf("\nEnter a target: ");
        fflush(stdout);


        if ((line_length = getline(&line, &line_capacity, stdin)) != -1) { // if block for target selector

            line[line_length - 1] = '\0';


            if (player_list_remove(&target_ring, line)) {
                printf("%s was tagged\n", line);
                player_list_append(&tagged_list, line);
            } else {
                printf("%s is not a target\n", line);
            }
        } else {
            break;  
        }


        printf("Target Ring:\n");
        print_as_target_ring(&target_ring);


        printf("Tagged list:\n");
        if (player_list_length(&tagged_list) == 0) {    // if blockt to print tagged list
            printf(" No people have been tagged yet.\n");
        } 
        else {
            player_node_t* current = tagged_list.head;
            while (current != NULL) {
                printf(" %s\n", current->value);
                current = current->next;
            }
            printf("\n");
        }
        printf("\nThere are %zu people left.\n", player_list_length(&target_ring));
    }


    if (player_list_length(&target_ring) == 1) {
        printf("%s is the final person remaining. \n", target_ring.head->value);
    }

    if (player_list_length(&tagged_list) == 0) {
        printf("No people have been tagged yet.\n");
    }


    player_list_destroy(&target_ring);
    player_list_destroy(&tagged_list);
    free(line);
    return 0;
}
