#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/// ------------------ for testing only, remove these ------------------

typedef struct Node {
    string data;
    struct Node *next;
} Node;

typedef struct List_Repr {
    struct Node *head;
    struct Node *tail;
    size_t size;
} List_Repr;

void list_show(list l) {
    if (l == NULL) return;
    Node *curr = l->head;
    while (curr->next != NULL) {
        printf("[%s]-->", curr->data);
        curr = curr->next;
    }
    printf("[%s]\n", curr->data);
}

/// ------------------ for testing only, remove these ------------------

int main () {
    // printf("Hello World!\n");
    list l = list_create();
    list_push(l, "1");
    list_push(l, "2");
    list_push(l, "3");
    list_push(l, "4");
    list_show(l);
    list_pop(l);
    list_pop(l);
    list_show(l);

    list_enqueue(l, "7");
    list_enqueue(l, "8");
    list_show(l);
    list_dequeue(l);
    list_show(l);





    return 0;
}

