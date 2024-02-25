
#include "mystrlen.h"

// The function must be implemented in a file mystrlen.c. ✅
// mystrlen.c must #include "mystrlen.h". ✅
// mystrlen.c must not #include any files other than mystrlen.h. ✅
// mystrlen.h must not be modified. ✅
// mystrlen.c must not define any functions other than mystrlen. ✅

int mystrlen(char *s){
    // your code here to implement mystrlen
    for (int i = 0; i < MAXLEN; i++){
        if (s[i] == '\0') {
            return i;
        }
        // printf("%c\n", s[i]);
    }
    return MAXLEN;
}

// int main(void)
// {
//     // your code here to test mystrlen
//     char str[] = "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678"; // 13 cahers
//     // printf("With main function = %lu\n", strlen(str));
//     printf("With my function = %d\n", mystrlen(str));
// }

// scp mystrlen.c z5114919@login.cse.unsw.edu.au:~/9024/pracs/prac_2