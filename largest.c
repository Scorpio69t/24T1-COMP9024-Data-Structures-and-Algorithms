#include <stdio.h>

// Write a C-function that takes 3 integers as arguments and returns the largest of them. The following restrictions apply:

// You are not permitted to use if statements.
// You are not permitted to use loops (e.g. while).
// You are not permitted to call any function.
// You are only permitted to use data and control structures introduced in Week 1's lecture.

int largest(int a, int b, int c) {

    // int a_sum = ((a > b) && (a > c))*a;
    // int b_sum = ((b > a) && (b > c))*b;
    // int c_sum = ((c > b) && (c > a))*c;

    // printf("sum a = %d\n", a_sum);
    // printf("sum b = %d\n", b_sum);
    // printf("sum c = %d\n", c_sum);
    
    return ((a > b) && (a > c))*a + ((b > a) && (b > c))*b + ((c > b) && (c > a))*c;
    
}

int main(void)
{
    // Write a C-program that outputs, in alphabetical order, all strings that use each of the characters 'c', 'a', 't', 'd', 'o', 'g' exactly once.

    // How many strings does your program generate?

    // Hint: Find a simple algorithm to solve this specific problem only. Do not use any functions from the string library.
    printf("%d\n", largest(1, 4, 8));

    return 0;
}

