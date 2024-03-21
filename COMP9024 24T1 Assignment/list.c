// You have been provided with a file list.h. Examine the file carefully. It provides the interface for an ADT that will provide Queue, Stack, and Set functionality.

// Your task is to implement the functions prototyped in the list.h header file within list.c.

// You must create the file list.c to implement this ADT.
// You must store string (char *) data within the ADT.
// You must allocate memory dynamically.
// You must not modify the list.h file.
// You must not modify the function prototypes declared in the list.h file.
// You may add utility functions to the list.c file.
// You may use the string.h library, and other standard libraries from the weekly exercises.
// You may reuse code previously submitted for weekly assessments and provided in the lectures.
// You may use whatever internal representation you like for your list ADT, provided it does not contradict any of the above.
// You may assume that any instance of your list ADT will only be used as a queue or a stack or a set.
// You should write programs that use your ADT to test and debug your code.
// You should use valgrind to verify that your ADT does not leak memory.
// As a reminder:

// Queue - First In, First Out
// Stack - First In, Last Out
// Set - Only stores unique values.
// See list.h for more information about each function that you are required to implement.

#include "list.h"
#include "string.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct Node {
    string data;
    struct Node *next;
} Node;

typedef struct List_Repr {
    struct Node *head;
    size_t size;
} List_Repr;


list list_create(void) {
    list l = malloc(sizeof(List_Repr));
    assert(l != NULL);

    l->head = NULL;
    l->size = 0;

    return l;
}

void list_destroy(list l) {
    // if(l != NULL || l->head == NULL);

    Node *curr = l->head;
    Node *prev = NULL;

    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    free(curr);
    l->size = 0;
}

bool list_is_empty(list l) {
    if (l->size == 0) return true;
    else return false;
}

size_t list_length(list l) {
    return l->size;
};


/****************************** STACK INTERFACE *******************************/
void list_push(list l, string s) {
    if (l == NULL || s == NULL) return;
    Node *new = malloc(sizeof(Node));
    assert(new != NULL);

    new->data = s;
    new->next = l->head;

    l->head = new;
    l->size++;
}

string list_pop(list l) {
    if (l == NULL || l->head == NULL) return NULL;

    Node *temp_head = l->head;
    string data = temp_head->data;

    l->head = l->head->next;
    l->size--;
    free(temp_head);
    
    return data;
}


/****************************** QUEUE INTERFACE *******************************/
void list_enqueue(list l, string s) {
    if (l == NULL || s == NULL) return;
    Node *new = malloc(sizeof(Node));
    assert(new != NULL);

    new->data = s;
    new->next = l->head;

    l->head = new;
    l->size++;
}

string list_dequeue(list l) {
    if (l == NULL || l->head == NULL) return NULL;

    Node *curr = l->head;

    while (curr->next->next != NULL) {
        curr = curr->next;
    }

    string data = curr->next->data;
    free(curr->next);
    curr->next = NULL;
    l->size--;
    
    return data;
}


/******************************* SET INTERFACE ********************************/
void list_add(list l, string s) {
    printf("TODO");
}

void list_remove(list l, string s) {
    printf("TODO");
}

bool list_contains(list l, string s) {
    return false;
}

// scp list.c z5114919@login.cse.unsw.edu.au:~/9024/assignment