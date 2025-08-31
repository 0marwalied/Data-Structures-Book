# 📚 Queues — Formal Definition and Circular Queue Update

## ⚙️ Queue — formal definition

A queue is a linear abstract data type (ADT) that models a collection of elements with two primary operations:

- ➕ Enqueue(x): insert element x at the rear (also called tail) of the queue.
- ➖ Dequeue(): remove and return the element at the front (also called head) of the queue.

### 🧾 Formal contract

- Data shape: a finite sequence of elements (a0, a1, ..., a\_{k-1}).
- Invariants:
  - ✅ Elements are ordered by time of insertion (FIFO — first-in, first-out).
  - ✅ Only the front element can be removed; insertions always happen at the rear.

### 🔧 Operations (specification)

- isEmpty() -> bool

  - Precondition: none
  - Postcondition: returns true if the sequence is empty (k == 0)

- enqueue(x) -> void or error

  - Precondition: queue is not full (if there is a bounded capacity)
  - Postcondition: sequence becomes (a0, ..., a\_{k-1}, x)

- dequeue() -> element or error
  - Precondition: queue is not empty (k > 0)
  - Postcondition: returns a0 and sequence becomes (a1, ..., a\_{k-1})

### ⏱ Complexity guarantees (typical implementations)

- enqueue: O(1) amortized or worst-case
- dequeue: O(1)

### ⚠️ Edge cases and error modes

- ⛔ Underflow: calling dequeue on an empty queue — should return an error or raise an exception depending on the environment.
- ⛔ Overflow: enqueue on a bounded-capacity queue when full — either reject the insertion (error) or resize the underlying storage.

## 🔁 Update: Circular queue (fixed-size circular buffer)

### 🎯 Motivation

- A naive array-backed queue that shifts elements on each dequeue is O(n) per dequeue. A circular buffer provides O(1) enqueue and dequeue using constant-time index arithmetic.

### 🧭 Representation

- Use a fixed-size array of capacity N and two integer indices: front and rear.
  - front: index of the current element to remove (head).
  - rear: index of the position where the last element was inserted (or alternatively the next free slot depending on the convention).

### 🔢 Index arithmetic

- All index updates are performed modulo N: index = (index + 1) mod N.

### 🧩 Empty and full detection (two common conventions)

1. "One-slot reserved" convention:

   - Invariant: queue is empty when front == rear.
   - Queue is full when (rear + 1) % N == front.
   - This convention sacrifices one array slot to distinguish empty vs full.

2. Count-based convention:
   - Maintain a separate size counter `count`.
   - Empty when count == 0, full when count == N.
   - Requires one extra integer but allows use of all N slots.

### 🧾 Pseudocode (one-slot reserved convention)

- enqueue(x):

  - if ( (rear + 1) % N == front ) then error (overflow)
  - rear = (rear + 1) % N
  - items[rear] = x

- dequeue():
  - if ( front == rear ) then error (underflow)
  - front = (front + 1) % N
  - return items[front]

### 📝 Notes on conventions

- The pseudocode above follows the common C textbook convention where `front` points to the slot immediately before the first element and `rear` points to the last element's slot; pre-increment is used before access. Other implementations set `front` to point at the first element and `rear` to point to the next free slot — both are correct when the invariants and checks match the chosen convention.

### ✅ Advantages of circular queue

- Constant-time enqueue/dequeue with no element movement.
- Memory locality due to contiguous array backing.

### 🔗 Mapping to the example C file

- The file `Queue.c` in this folder implements a fixed-size circular buffer using the one-slot-reserved convention with `MAXQUEUE` as N and integer indices `front` and `rear`.

- Implemented functions (current file):

  - `int empty(struct queue *q)` — returns whether the queue is empty (front == rear).
  - `int dequeue(struct queue *q)` — removes an element from the front.
  - `void insert(struct queue *q, int item)` — inserts an element at the rear (this is the file's name; equivalent to enqueue).

- Initialization in the example sets `front = MAXQUEUE - 1` and `rear = MAXQUEUE - 1` so the buffer indices wrap correctly under the chosen convention.

⚠️ Important implementation note (off-by-one):

The current `Queue.c` implementation uses `insert` to increment `rear` first and store into `items[rear]` (i.e., `rear = (rear + 1) % N; items[rear] = item;`).

However, `dequeue` in the file reads `items[front]` first and then advances `front` (i.e., `item = items[front]; front = (front + 1) % N;`). With the initialization `front = rear = N-1`, this ordering causes `dequeue` to return the wrong slot (a stale or uninitialized value) on the first removal.

Recommended fixes (pick one):

1. Make `dequeue` pre-increment `front` before accessing the buffer (common textbook style):

   - `front = (front + 1) % N; item = items[front];`

2. Alternatively, change `insert` to write into the current `rear` slot and then advance `rear` (i.e., post-increment convention). That option requires adjusting the full/empty checks accordingly.

The simplest patch to make the example correct and consistent is to change `dequeue` to pre-increment `front` before reading `items[front]`. This preserves `insert`'s current behavior and the one-slot-reserved invariant.

Example corrected `dequeue` (recommended):

```c
int dequeue(struct queue *q) {
	if (empty(q)) { /* underflow */ }
	q->front = (q->front + 1) % MAXQUEUE; // move to the first element
	int item = q->items[q->front];
	return item;
}
```

If you prefer, I can apply the fix directly to `Queue.c`, add a corresponding `enqueue` alias for `insert`, and re-run the build and a small demo.

### 🛠 Edge cases and recommended practices

- Carefully document which convention is used (front points at first element vs at the slot before it) and ensure all operations match that choice.
- Prefer the count-based approach when you need full utilization of the buffer.
- For production C code, avoid using identifiers that collide with standard library names (e.g., `remove`). Use explicit names such as `dequeue` and `enqueue`.

---

### ➕ Want more?

- 🧩 I can add a complete `enqueue` implementation and example usage to `Queue.c` following either convention you prefer.
- 🧪 I can add a small test harness that demonstrates overflow/underflow handling.

---

## 🧾 Example implementation — `Queue.c`

Source (GitHub): [Queue.c on GitHub](https://github.com/0marwalied/Data-Structures-Book/blob/main/Queues%20%26%20Lists/Queue.c)

See the implementation on GitHub (link above) for the exact source.
