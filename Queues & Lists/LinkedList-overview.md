# 🧩 Linked Lists: Overview and Implementation

This document provides a comprehensive guide to linked list implementations in this folder.

---

## 📖 Overview

A linked list is a linear data structure where each element (node) contains data and a reference (pointer) to the next node. Unlike arrays, linked lists do not require contiguous memory allocation, allowing for dynamic sizing and efficient insertions/deletions.

---

## 🧩 Types of Linked Lists

- **Singly Linked List**: Each node points to the next node. The implementations in this folder (`LinkedList.c` and `linkedList.cpp`) are singly linked.
- **Doubly Linked List**: Each node has pointers to both next and previous nodes (not implemented here).
- **Circular Linked List**: The last node points back to the first (not implemented here).

---

## ✨ Key Characteristics

- **Dynamic Size**: Can grow or shrink without predefined limits.
- **Non-Contiguous Memory**: Nodes can be scattered in memory, connected via pointers.
- **Traversal**: Access elements sequentially from the head; no random access like arrays.
- **Overhead**: Each node requires extra space for the pointer(s).

---

## ✅ Advantages

- **Efficient insertions/deletions**: At any position (O(1) with a pointer).
- **No wasted space**: From unused capacity.
- **Flexible memory usage**.

---

## ❌ Disadvantages

- **No random access**: Must traverse from the start (O(n) access time).
- **Extra memory per node**: For pointers.
- **Potential for memory leaks**: If not managed properly.

---

## 🗂️ Array-Based Linked Lists

Linked lists can be implemented using arrays by simulating pointers with indices. However, this approach has significant disadvantages:

- **Fixed Capacity**: Limited by array size; resizing is complex and expensive.
- **Inefficient Operations**: Insertions and deletions require shifting elements, making them O(n).
- **Memory Waste**: Allocates the full array even if the list is small, leading to wasted space.
- **Complexity**: Managing free slots and simulating pointers adds significant overhead.
- **Performance**: Worse cache locality compared to true dynamic lists, as nodes aren't contiguous.
- **Fragility**: Errors in index management can corrupt the entire list.

For these reasons, array-based linked lists are generally avoided in favor of dynamic implementations.

## Dynamic Linked Lists

The implementations in this folder use pointers and dynamic memory allocation (`malloc`/`free` in C, `new`/`delete` in C++), which is far superior.

### Key Features

- **Dynamic Allocation**: No fixed size; can grow/shrink as needed.
- **Operations**:
  - `getnode()`: Allocates a new node.
  - `freenode()`: Deallocates a node.
  - `insafter()`: Inserts a node after a specified node.
  - `delafter()`: Deletes the node after a specified node.

### Advantages Over Array-Based

- **Flexibility**: Grows/shrinks dynamically without resizing overhead.
- **Efficiency**: Insertions/deletions in the middle are O(1) with a pointer.
- **Memory**: Only allocates for existing nodes, no wasted space.
- **Simplicity**: No need to manage indices or free slots.
- **Performance**: Better cache locality with contiguous node allocation.

Dynamic linked lists are the preferred method for linked lists in most applications.
---

## 📂 Implementation Files

This folder contains the following implementation files:

- [LinkedList.c](./LinkedList.c): Implementation of a singly linked list in C.
- [linkedList.cpp](./linkedList.cpp): Implementation of a singly linked list in C++.