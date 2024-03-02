#include <stdio.h>
#include <stdlib.h>

void collatz(int n);;

int main() {
    int *number = malloc(sizeof(int));
    printf("Input a number: ");
    scanf("%d", number);
    printf("Numnber is %d\n", *number);
    collatz(*number);
    free(number);
}

void collatz(int n) {
    printf("Number = %d\n", n);
    if (n == 1) return;
    if (n % 2 == 0) collatz(n / 2);
    else collatz(3*n + 1);
}