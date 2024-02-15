#include <stdio.h>

int sum(int vec[] , int dim) {
    int sum = 0;
    for (int i = 0; i < dim; i++) {
        sum += vec[i];
    }
    return sum;
}

int main(void)
{
    return 0;
}

