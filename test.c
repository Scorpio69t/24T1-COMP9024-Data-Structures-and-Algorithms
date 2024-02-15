#include <stdio.h>

int main(void)
{
    #define MAX 20

    int i;           // integer value used as index
    int fact[MAX];   // array of 20 integer values

    fact[0] = 1;
    for (i = 1; i < MAX; i++) {
        fact[i] = i * fact[i-1];
        printf("%d\n", fact[i]);
    }
}

