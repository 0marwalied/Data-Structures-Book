/*
 * Simple fixed-size circular queue (one-slot reserved convention)
 *
 * This file implements a minimal circular queue using a fixed array of
 * integers and two indices, `front` and `rear`. The implementation is
 * intentionally small and uses `insert` for enqueue and `dequeue` for
 * dequeue. No dynamic allocation or thread-safety is provided.
 */

#include <stdlib.h>
#include <stdio.h>

#define MAXQUEUE 100 /* capacity of the circular buffer */

/*
 * queue -- circular buffer backed by a fixed-size array
 * items[] : storage for elements
 * front   : index used by dequeue operations
 * rear    : index used by insert/enqueue operations
 *
 * Convention used here (one-slot reserved):
 *   - The queue is empty when front == rear.
 *   - The queue is full when (rear + 1) % MAXQUEUE == front.
 *
 * Note: This file follows the original example's naming. `insert` is an
 * enqueue operation and `dequeue` removes an element. The code purposely
 * keeps the original function names to match the example.
 */
struct queue {
  int items[MAXQUEUE];
  int front, rear;
};

/*
 * empty -- return non-zero when the queue contains no elements.
 * Input: pointer to a queue
 * Return: 1 if empty, 0 otherwise
 */
int empty(struct queue *q) {
  return q->front == q->rear;
}

/*
 * dequeue -- remove and return the element at the front of the queue.
 * Behavior:
 *   - If the queue is empty, prints an error and exits the program.
 *   - Otherwise, returns an integer from the buffer and advances `front`.
 *
 * Implementation note:
 *   - The current implementation reads items[q->front] and then advances
 *     `front`. Combined with the initialization front = rear = MAXQUEUE-1
 *     and the way `insert` advances `rear` before storing, this ordering
 *     can produce an off-by-one behavior on the first dequeue. See the
 *     repository overview for an explanation and suggested fixes. This
 *     function intentionally preserves the original ordering here.
 */
int dequeue(struct queue *q) {
  if (empty(q)) {
    printf("Queue is underflow\n");
    exit(1);
  }
  int item = q->items[q->front];
  q->front = (q->front + 1) % MAXQUEUE;
  return item;
}

/*
 * insert -- enqueue `item` at the rear of the queue.
 * Behavior:
 *   - If the queue is full (overflow), prints an error and exits.
 *   - Otherwise, advances `rear` and stores the item into the buffer.
 */
void insert(struct queue *q,int item) {
  if((q->rear+1)%MAXQUEUE==q->front) {
    printf("Queue is overflow\n");
    exit(1);
  }
  q->rear=(q->rear+1)%MAXQUEUE;
  q->items[q->rear]=item;
}

/*
 * main -- tiny driver used to demonstrate initialization and empty check.
 * The indices are initialized to MAXQUEUE-1 in the original example; this
 * keeps the same initialization so the program behaviour is unchanged.
 */
int main() {
  struct queue q;
  q.front = MAXQUEUE-1, q.rear = MAXQUEUE-1;
  printf("%d\n", empty(&q));
  return 0;
}