#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isHeterogram(char A[]);

int main() {
    char str[63];
    printf("Enter a word or phrase: ");
    scanf("%[^\n]%*c",str);
    
    if (isHeterogram(str)) {
        printf("\"%s\" is a heterogram\n", str);
    } else {
        printf("\"%s\" is not a heterogram\n", str);
    }

    return 0;
}

bool isHeterogram(char A[]) {
    // A heterogram is a word, phrase, or sentence in which no letter of the alphabet
    // occurs more than once. For example, "until" is such a word, but "repeat" is not;
    // "the quick fox" is such a phrase, but "the quick brown fox" is not.

    // Approach 1
    // check int array of 26 
    // loop through word
    // Increment value in array position 'a' where a is the index of the character
    // 
    int letters_used[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int index;
    for (int i = 0; i < strlen(A); i++) {
        // printf("Checking %c\n", A[i]);
        if (A[i] == ' ') continue;
        index = (int) (A[i]) - 97;
        if (letters_used[index] == -1) {
            return false;
        } else {
            letters_used[index] = -1;
        }
    }
    return true;

}

// scp heterogram.c z5114919@login.cse.unsw.edu.au:~/9024/pracs/prac_3