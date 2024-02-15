#include <stdio.h>

void generate_permutations(char *str, int end, int* index) {
    printf("%c\n", str[0]);
    printf("%c\n", str[1]);
    printf("%c\n", str[2]);
    printf("%c\n", str[3]);
    printf("%c\n", str[4]);
    printf("%c\n", str[5]);
    printf("%c\n", str[6]);
}

int main(void)
{
    // Write a C-program that outputs, in alphabetical order, all strings that use each of the characters 'c', 'a', 't', 'd', 'o', 'g' exactly once.

    // How many strings does your program generate?

    // Hint: Find a simple algorithm to solve this specific problem only. Do not use any functions from the string library.

    // This is a combinations question
    char str[] = "catdog";
    int end = sizeof(str)/sizeof(char) - 1; // = 6
    int index = 0;
    int used[6] = {0, 0, 0, 0, 0, 0};

    generate_permutations(str, end, used);

    return 0;
}

