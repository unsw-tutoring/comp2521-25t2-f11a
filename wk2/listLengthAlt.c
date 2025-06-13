#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
};

int doListLength(struct node *l) {
    if (l == NULL) return 0;
    return 1 + doListLength(l->next);
}

int listLength(struct list *l) {
    return doListLength(l->head);
}

void doListLength2(struct node *l, int *length) {
    if (l == NULL) return;
    (*length)++;
    doListLength2(l->next, length);
}

int listLength2(struct list *l) {
    int length = 0;
    doListLength2(l->head, &length);
    return length;
}
