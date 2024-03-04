#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day, month; // 2x ints, 8 bytes
} DateT;

typedef struct {
    int hour, minute; // 2x ints, 8 bytes
} TimeT;

typedef struct {
    char plate[7]; // 7 bytes - 1 per character
    double speed; // 8 bytes 24 + 
    DateT d; // 8 bytes
    TimeT t; // 8 bytes
} TicketT; // 

int main() {
    int num_tickets = 1000;
    TicketT *tickets; // Create a pointer to tickets
    tickets = malloc(num_tickets * sizeof(TicketT));  // malloc allocates a portion of memory and returns a pointer to it
    free(tickets);
}