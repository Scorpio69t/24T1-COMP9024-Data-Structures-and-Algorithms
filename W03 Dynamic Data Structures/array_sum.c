#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool array_sum_possible(int *numbers, int target_sum, int len);

int main() {
    int numbers[6] = {1, 2, 3, 4, 5};
    int *num_ptr = numbers;
    int target_sum = 7;
    array_sum_possible(numbers, target_sum, sizeof(numbers) / sizeof(int));
    
    return 0;
}

bool array_sum_possible(int *numbers, int target_sum, int len) {
    // loop through an array
    // for each element
        // find required number to sum to target sum: req_num = target sum - number
        // loop through remaining elements to find the required number
        // if found, return, else continue
    
    for (int i = 0; i < len; i++) {
        int req_num = target_sum - numbers[i];
        printf("Number = %d, Required Number = %d\n", numbers[i], req_num);
        for (int j = i; j < len; j++) {
            printf("%d\n", numbers[j]);
            if (numbers[j] == req_num) {
                printf("Required Number Found, Returning True\n");
                return true;
            }
        }
    }
    printf("No number found, returning false\n");
    return false;
}

// 3^n = O(^n)
// 20n = O(n)