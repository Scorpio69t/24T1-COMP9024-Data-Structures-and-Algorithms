#include <stdio.h>

int main(void) {
    int s1, s2, s3;

    // Read 3 integers from standard input (e.g. keyboard)
    scanf("%d %d %d", &s1, &s2, &s3);

    // Ancient Greek mathematician Euclid defined three types of triangle 
    // according to the lengths of their sides:
    // - An equilateral triangle has three sides of the same length
    // - An isosceles triangle has two sides of equal length
    // - A scalene triangle has all its sides of different lengths

    if (s1 + s2 < s3 || s2 + s3 < s1 || s3 + s2 < s1) {
        printf("Not a triangle\n");
    }
    else if (s1 <= 0 || s2 <= 0 || s3 <= 0) {
        printf("Not a triangle\n");
    }
    else if (s1 == s2 && s2 == s3) {
        printf("Equilateral triangle\n");
    } else if (s1 == s2 || s2 == s3 || s1 == s3) {
        printf("Isosceles triangle\n");
    } else {
        printf("Scalene triangle\n");
    }

    return 0;
}