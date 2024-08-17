#include "player_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void player_list_init(player_list_t* lst) {
    lst->head = NULL;
}

void player_list_destroy(player_list_t* lst) {
    player_node_t* current = lst->head;
    while (current != NULL) {
        player_node_t* next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
    lst->head = NULL;
}

void player_list_append(player_list_t* lst, char* name) {
    player_node_t* new_node = malloc(sizeof(player_node_t));

    new_node->value = strdup(name);

    new_node->next = NULL;

    if (lst->head == NULL) {
        lst->head = new_node;
    } else {
        player_node_t* current = lst->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

bool player_list_remove(player_list_t* lst, char* name) {
    if (lst == NULL || lst->head == NULL) {
        return false;
    }

    player_node_t* current = lst->head;
    player_node_t* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->value, name) == 0) {
            if (prev == NULL) {
                lst->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->value);
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

size_t player_list_length(const player_list_t* lst) {
    size_t length = 0;
    player_node_t* current = lst->head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

void print_as_target_ring(const player_list_t* lst) {
    const player_node_t* cur = lst->head;
    const player_node_t* first = lst->head;
    const player_node_t* prev;
    if (cur == NULL) {
        printf("No people have been tagged yet.\n");
        return;
    }
  while(cur != NULL){
    prev = cur;
    cur = cur->next;
    if (cur!=NULL){
      printf("  %s is stalking %s\n",prev->value, cur->value);
    }
  }
  printf("  %s is stalking %s\n",prev->value, first->value);
}
