# 📚 Stack and Its Importance

A **stack** is a fundamental data structure in computer science that follows the **Last In, First Out (LIFO)** principle. This means the last element added to the stack is the first one to be removed.

---

## 📌 Importance of Stack

Stacks are widely used in:

- **Function calls** and **recursion** (call stack)
- **Undo/Redo** mechanisms in applications
- **Parsing expressions**, syntax checking
- **Backtracking algorithms** (e.g., solving mazes)
- **Depth-first search** in graphs
- **Evaluating arithmetic expressions**

---

## ⚙️ Main Operations

| Operation       | Description                                 |
|----------------|---------------------------------------------|
| `Push`         | Add an element to the top of the stack      |
| `Pop`          | Remove the top element from the stack       |
| `Peek` or `Top`| Look at the top element without removing it |
| `isEmpty`      | Check if the stack is empty                 |

---

## 🧱 Stack Implementations

### C Implementation

- [`stackTemplateInC.c`](https://github.com/0marwalied/Data-Structures-Book/blob/main/Stack/stackTemplateInC.c): Stack implementation template in C.
- [`stackUsageExample.c`](https://github.com/0marwalied/Data-Structures-Book/blob/main/Stack/stackUsageExample.c): Example of stack usage in C.

### Modern C++ Implementation

- [`stackTemplateInCpp.cpp`](https://github.com/0marwalied/Data-Structures-Book/blob/main/Stack/stackTemplateInCPP.cpp):  
  Reusable, type-safe stack class using C++ templates. Supports `push`, `pop`, `size`, and `empty` operations, and throws exceptions on overflow/underflow.
- [`stackUsageExampleCpp.cpp`](https://github.com/0marwalied/Data-Structures-Book/blob/main/Stack/stackUsageExample.cpp):  
  Usage demonstration of the C++ stack template, showing how to create a stack, push/pop elements, and check size and emptiness.

---

## ✅ Parentheses Validation

- [`validatingNestedParentheses.cpp`](https://github.com/0marwalied/Data-Structures-Book/blob/main/Stack/validatingNestedParentheses.cpp):  
  Checks for valid nested parentheses using a stack in C++.

**Example Input:**  
```text
{ x + (y - [a + b]) - (d + e) } - (j - (k - l))
```

---

## 🔄 Infix to Postfix Conversion

- [`infixToPostfix.c`](https://github.com/0marwalied/Data-Structures-Book/blob/main/Stack/infixToPostfix.c):  
  Converts infix mathematical expressions to postfix notation (Reverse Polish Notation) using a stack.

**Infix to Postfix Examples:**

| Infix Expression                        | Postfix Output                  |
|----------------------------------------|----------------------------------|
| `A + B`                                | `AB+`                            |
| `(A + B) * C`                          | `AB+C*`                          |
| `A + B * C`                            | `ABC*+`                          |
| `A * B + C`                            | `AB*C+`                          |
| `A + (B - C) * D`                      | `ABC-D*+`                        |
| `(A + B) * (C - D)`                    | `AB+CD-*`                        |
| `A + (B * C - D) + (E / F / (G + H))`  | `ABC*D-+EF/GH+/+`                |

---

## 📤 Postfix Expression Evaluation

- [`solvingPostfixFormat.c`](https://github.com/0marwalied/Data-Structures-Book/blob/main/Stack/solvingPostfixFormat.c):  
  Evaluates mathematical expressions given in postfix notation (Reverse Polish Notation) using a stack.  
  This file demonstrates how to process and solve postfix expressions by reading the expression, pushing operands onto the stack, and applying operators.

---