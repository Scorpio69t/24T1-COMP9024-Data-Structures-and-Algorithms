#include <stdio.h>

int main(void)
{
    // There is a 5-digit number that satisfies 4·abcde = edcba, that is, when multiplied by 4 yields the same number read backwards.
    // Write a C-program to find this number.
    // Hint: Only use arithmetic operations; do not use any string operations.

    for (int i = 1000; i < 2500; i++)
    {
        
        int reverse = i * 4;
        // printf("%d, %d, %d, %d\n", i/1000%10, i/100%10, i/10%10, i%10);
        // printf("%d, %d, %d, %d\n", reverse/1000%10, reverse/100%10, reverse/10%10, reverse%10);

        if (i / 1000 % 10 == reverse % 10 && i / 100 % 10 == reverse / 10 % 10 && i / 10 % 10 == reverse / 100 % 10 && i % 10 == reverse / 1000 % 10)
        {
            printf("%d --> %d\n", i, reverse);
        }
    }

    return 0;
}