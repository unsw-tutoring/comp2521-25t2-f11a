#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(char *str) {
    int length = strlen(str);  // O(n)
    // pair up letters in opposite positions
    for (int i = 0; i < length / 2; i++) {  // runs O(n) times
        // if any pairs are not matching return false
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}
