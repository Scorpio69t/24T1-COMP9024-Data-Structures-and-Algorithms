#include <stdio.h>
#include <stdlib.h>



int main() {
    int m = 4, n = 2;

   float **matrix; // a pointer to a pointer 

   // **matrix = [*ptr1, *ptr2, *ptr3]
   
   // *ptr1 --> [2.0][2.0][3.0]
   // *ptr2 --> [2.0][2.0][3.0]
   // *ptr3 --> [2.0][2.0][3.0]

   matrix = malloc(m * sizeof(float *)); // size = m * 8 bytes
   assert(matrix != NULL);

   int i;
   for (i = 0; i < m; i++) {
    matrix[i] = malloc(n * sizeof(float)); // size = m * (n * 4 bytes)
    assert(matrix[i] != NULL);
   }
    return 0;
}