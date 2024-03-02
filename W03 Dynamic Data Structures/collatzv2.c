#include <stdio.h>
#include <stdlib.h>

void collatz(int n);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [number]\n", argv[0]);
        return 0;
    } 

    printf("Numnber is %s\n", argv[1]);
    collatz(atoi(argv[1]));
    return 0;
}

void collatz(int n) {
    printf("Number = %d\n", n);
    if (n == 1) return;
    if (n % 2 == 0) collatz(n / 2);
    else collatz(3*n + 1);
}