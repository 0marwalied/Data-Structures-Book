# 🔄 Circular Linked Lists: Overview and Implementation

This document provides a comprehensive guide to circular linked list implementations in this folder.

---

## 📖 Overview

A circular linked list is a variation of a linked list where the last node points back to the first node instead of pointing to NULL. This creates a circular chain of nodes, allowing traversal to continue indefinitely from any starting point. Every node in a circular list has a successor, eliminating the concept of a "tail" pointing to NULL.

---

## 🧩 Structure

Unlike a regular linked list that terminates with a NULL pointer, a circular linked list forms a closed loop:

- **Regular Linked List**: `Node1 -> Node2 -> Node3 -> NULL`
- **Circular Linked List**: `Node1 -> Node2 -> Node3 -> Node1 (circular)`

---

## ✨ Key Characteristics

- **No NULL Termination**: The last node's `next` pointer references the first node.
- **Cyclic Traversal**: Can traverse the entire list starting from any node by stopping when you return to the starting point.
- **Flexible Entry Point**: Any node can serve as a reference point (often called the "list pointer").
- **Convention**: Typically, we maintain a pointer to the **last node** (not the first), which gives O(1) access to both the tail and head (via `last->next`).

---

## ✅ Advantages

- **Efficient Queue Operations**: When maintaining a pointer to the last node, both enqueue (insert at rear) and dequeue (remove from front) are O(1).
- **Round-Robin Scheduling**: Naturally suited for applications that need to cycle through items repeatedly.
- **No NULL Checks**: Eliminates the need to check for NULL during traversal in many cases.
- **Symmetry**: No distinction between "first" and "last" from a structural perspective.

---

## ❌ Disadvantages

- **Complexity in Termination**: Must explicitly track when traversal is complete (return to starting node).
- **Risk of Infinite Loops**: Improper traversal logic can cause endless iteration.
- **Memory Leaks**: Deleting all nodes requires care to avoid accessing deleted nodes when following the cycle.
- **Debugging Difficulty**: Circular references can be harder to visualize and debug.

---

## 🔧 Operations

### Core Operations

- **getNode()**: Allocate a new node dynamically.
- **isEmpty(list)**: Check if the circular list is empty (list == NULL).
- **push(list, val)**: Insert a new node with value `val` into the circular list.
  - If list is empty, create the first node pointing to itself.
  - Otherwise, insert after the current list pointer and update connections.
- **pop(list, val)**: Remove and return the node with value `val`.
  - Traverse to find the predecessor of the target node.
  - Update pointers to bypass the target node.
  - Handle the case where the value is not found.
- **printList(list)**: Traverse and display all elements in the circular list.
  - Uses a `do-while` loop to ensure at least one traversal.
  - Stops when returning to the starting node.

---

## 🎯 Common Use Cases

1. **Round-Robin Scheduling**: Operating systems use circular lists for CPU scheduling where processes cycle through in order.
2. **Multiplayer Games**: Turn-based systems where play rotates among players.
3. **Circular Buffers**: Efficient FIFO queues with wraparound.
4. **Resource Allocation**: Fair distribution of shared resources in a cyclic manner.

### 💡 Using Circular Lists as Stacks and Queues

Circular linked lists can efficiently implement both stack and queue data structures:

#### **Stack Implementation**

- **Push**: Insert at the rear (after list pointer) → O(1)
- **Pop**: Remove from the rear (at list pointer) → O(1)
- **Why it works**: The list pointer acts as the top of stack, giving direct access to the most recently added element.
- **See**: [stackCircularList.cpp](./stackCircularList.cpp) for implementation.

#### **Queue Implementation**

- **Enqueue**: Insert at the rear (after list pointer) → O(1)
- **Dequeue**: Remove from the front (at list->next) → O(1)
- **Why it works**: Maintaining a pointer to the last node gives O(1) access to both ends - the rear directly and the front via `last->next`.
- **Key advantage**: Unlike array-based queues, no wraparound logic needed; unlike regular linked lists, both operations are O(1) with a single pointer.
- **See**: [queueCircularList.cpp](./queueCircularList.cpp) for implementation.

**Important**: Both stack and queue operations must pass the list pointer by reference (`Node*&`) to ensure modifications persist in the caller's scope.

---

## ⚙️ Implementation Details

### Insertion Strategy

When inserting into a circular list with a pointer to the last node:

```
1. Create new node p
2. If list is empty:
   - Make p point to itself: p->next = p
   - Set list = p
3. If list is not empty:
   - p->next = list->next  (new node points to first node)
   - list->next = p        (old last points to new node)
   - optionally: list = p  (if inserting at the end)
```

### Deletion Strategy

Removing a node with a specific value:

```
1. Start from list pointer
2. Traverse until p->next contains target value
3. Check if we've cycled back (p == list) without finding value
4. Update p->next to skip the target node
5. Delete the target node
6. Return the value
```

### Traversal Pattern

```cpp
if (!isEmpty(list)) {
    Node* p = list->next;  // Start from the first node
    do {
        // Process p->val
        p = p->next;
    } while (p != list->next);  // Stop when back at start
}
```

---

## ⏱ Time Complexity

| Operation           | Time Complexity | Notes                                       |
| ------------------- | --------------- | ------------------------------------------- |
| Insert at end       | O(1)            | When maintaining pointer to last node       |
| Insert at beginning | O(1)            | Access via last->next                       |
| Delete by value     | O(n)            | Must search for the value                   |
| Search              | O(n)            | Must traverse until found or cycle complete |
| Print/Traverse      | O(n)            | Visit each node once                        |

---

## 📂 Implementation Files

This folder contains the following implementation file:

- [circularList.cpp](./circularList.cpp): Implementation of a circular singly linked list in C++.

---

## 🔄 Circular vs. Regular Linked Lists

| Feature               | Regular Linked List                     | Circular Linked List                            |
| --------------------- | --------------------------------------- | ----------------------------------------------- |
| Last node points to   | NULL                                    | First node                                      |
| Traversal termination | `p == NULL`                             | `p == start`                                    |
| Access to both ends   | Need head and tail pointers             | One pointer to last gives both                  |
| Use case              | General linear data                     | Cyclic/round-robin data                         |
| Queue efficiency      | O(1) enqueue if tail pointer maintained | O(1) both enqueue and dequeue with last pointer |

---

## ⚠️ Important Considerations

- **Traversal Care**: Always use conditions that detect returning to the starting point, not just NULL checks.
- **Empty List Handling**: A circular list is empty when the list pointer is NULL, not when it points to itself.
- **Memory Management**: When deleting the entire list, break the circle first or carefully track visited nodes.
- **Single Node Case**: A circular list with one node has that node pointing to itself: `node->next == node`.

---

## 🧪 Testing Edge Cases

When implementing or using circular linked lists, test these scenarios:

1. **Empty list**: Operations on NULL list.
2. **Single node**: Node pointing to itself.
3. **Two nodes**: Proper circular linkage.
4. **Delete last remaining node**: Ensure list becomes NULL.
5. **Search for non-existent value**: Proper cycle detection.
6. **Insert and delete multiple times**: Verify integrity of circular structure.

---

## 📝 Notes

The implementation in [circularList.cpp](./circularList.cpp) demonstrates basic operations on a circular linked list using C++ with dynamic memory allocation. The list maintains its circular property throughout all operations, making it suitable for applications requiring continuous cyclic access to elements.
