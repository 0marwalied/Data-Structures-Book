#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* next;
};

typedef struct Node *NODEPTR;


NODEPTR getnode(void) {
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return p;
}

void freenode(NODEPTR p) {
    free(p);
}

void insafter(NODEPTR p, int x) {
    NODEPTR q;
    if (p == NULL) {
        printf("Invalid insertion\n");
        exit(1);
    }
    q = getnode();
    q->info = x;
    q->next = p->next;
    p->next = q;
}

void delafter(NODEPTR p, int *px) {
    NODEPTR q;
    if ((p == NULL) || (p->next == NULL)) {
        printf("Invalid deletion\n");
        exit(1);
    }
    q = p->next;
    *px = q->info;
    p->next = q->next;
    freenode(q);
}

int main() {

}