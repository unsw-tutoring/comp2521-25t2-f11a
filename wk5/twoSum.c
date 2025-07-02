#include <stdbool.h>
#include <stdio.h>

#include "BST.h"

// return whether there are two numbers in the array that sum to 'sum'
// n = size of the array
// O(n^2) solution
// 1,2,3,4,5; target = 9 -> true
// 1,2,3,4,5; target = 10 -> false
bool hasTwoSum(int *arr, int n, int sum) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                return true;
            }
        }
    }
    return false;
}

// use a binary search tree
// overall time complexity: O(n log n)
bool hasTwoSum(int *arr, int n, int sum) {
    // use a bst as a set
    BSTree bst = BSTNew();  // O(1)

    // O(n log n)
    for (int i = 0; i < n; i++) {  // runs O(n) times
        int other = sum - arr[i];
        if (BSTSearch(bst, arr[i])) {  // O(log n)
            BSTFree(bst);              // O(n)
            return true;
        }

        BSTInsert(bst, arr[i]);  // O(log n)
    }

    BSTFree(bst);  // O(n)

    return false;
}
