#include "Set.h"

#define INITIAL_CAPACITY 8

struct set {
    int *arr;
    int nelems;
    int capacity;
};

// Creates a new empty set
Set SetNew(void) {
    Set s = malloc(sizeof(struct set));
    s->arr = malloc(INITIAL_CAPACITY * sizeof(int));
    s->nelems = 0;
    s->capacity = INITIAL_CAPACITY;
    return s;
}

// Frees memory allocated to the set
void SetFree(Set s) {
    free(s->arr);
    free(s);
}

// Inserts an element into the set
void SetInsert(Set s, int elem) {
    if (SetContains(s, elem)) return;

    if (s->nelems == s->capacity) {
        // expand our array
        s->capacity *= 2;
        s->arr = realloc(s->arr, s->capacity * sizeof(int));
    }

    s->arr[s->nelems++] = elem;
}

// Deletes an element from the set
void SetDelete(Set s, int elem) {}

// Returns true if the given element is in the set, and false otherwise
bool SetContains(Set s, int elem) {}

// Returns the number of elements in the set
int SetSize(Set s) {}