#include <stdio.h>
#include "mystrlen.h"
// #include "mystrlen.c"

int main(void) {
    char s[MAXLEN];
    // int len;

    printf("Enter a string: ");
    
    fgets(s, MAXLEN, stdin);

    while (s[0] != '\n') {    
        printf("%d\n", mystrlen(s));
        printf("Enter a string: ");
        fgets(s, MAXLEN, stdin);
    }

    printf("Goodbye!\n");


    return 0;
}

// scp lencalc.c z5114919@login.cse.unsw.edu.au:~/9024/pracs/prac_2