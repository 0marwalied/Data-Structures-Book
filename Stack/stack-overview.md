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

| Operation       | Description                                |
|----------------|--------------------------------------------|
| `Push`          | Add an element to the top of the stack     |
| `Pop`           | Remove the top element from the stack      |
| `Peek` or `Top` | Look at the top element without removing it |
| `isEmpty`       | Check if the stack is empty                |

---

## ✅ Validating Nested Parentheses with Stack

To determine if a string of parentheses is valid:

1. Each **right parenthesis** must match a **preceding left parenthesis**.
2. The number of left and right parentheses must be **equal**.
3. Scope enders must match their respective **openers** (e.g., `(` with `)`, `{` with `}`, `[` with `]`).

🔗 **Code Example on GitHub:**  
[Validating Nested Parentheses - C++ Implementation](https://github.com/0marwalied/Data-Structures-Book/blob/main/Stack/validatingNestedParentheses.cpp)

### ✔️ Algorithm

- Initialize an empty stack.
- Traverse each character of the string:
  - If it is an opening bracket `(`, `{`, `[`, push it onto the stack.
  - If it is a closing bracket `)`, `}`, `]`, check:
    - If the stack is empty → ❌ invalid
    - If the top of the stack doesn't match the closing type → ❌ invalid
    - Else → ✅ pop the stack
- After traversal, if the stack is empty → ✅ valid

---

## 🧪 Example

```text
Input: { x + (y - [a + b]) - (d + e) } - (j - (k - l))
