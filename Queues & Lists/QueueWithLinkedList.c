#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

typedef struct Node *NODEPTR;

struct Queue {
  NODEPTR front, rear;
};

NODEPTR getnode(void) {
  NODEPTR p = (NODEPTR)malloc(sizeof(struct Node));
  return p;
}

int empty(struct Queue* q) {
  return q->front == NULL;
}

void insert(struct Queue* q, int x) {
  NODEPTR newNode = getnode();
  newNode->data = x;
  newNode->next = NULL;
  if (q->rear == NULL) {
    q->front = q->rear = newNode;
    return;
  }
  q->rear->next = newNode;
  q->rear = newNode;
}

void freenode(NODEPTR p) {
  free(p);
}

int remove(struct Queue* q) {
  if (empty(q)) {
    printf("Queue is underflow\n");
    exit(1);
  }
  NODEPTR temp = q->front;
  int item = temp->data;
  q->front = q->front->next;
  if (q->front == NULL) {
    q->rear = NULL;
  }
  freenode(temp);
  return item;
}

int main() {

}