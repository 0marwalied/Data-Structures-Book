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

## 🧱 Stack Template in C

A reusable and simple stack implementation in C using an array for storing elements. Useful for all types of basic stack problems.

🔗 **Code Template on GitHub:**  
[`stackTemplateInC.c`](https://github.com/0marwalied/Data-Structures-Book/blob/main/Stack/stackTemplateInC.c)

---

## ✅ Validating Nested Parentheses with Stack

To determine if a string of parentheses is valid:

1. Each **right parenthesis** must match a **preceding left parenthesis**.
2. The number of left and right parentheses must be **equal**.
3. Scope enders must match their respective **openers** (e.g., `(` with `)`, `{` with `}`, `[` with `]`).

---

## 🧪 Example (Parentheses Validation)

```text
Input: { x + (y - [a + b]) - (d + e) } - (j - (k - l))
```

🔗 **Code Example on GitHub:**  
[Validating Nested Parentheses - C++ Implementation](https://github.com/0marwalied/Data-Structures-Book/blob/main/Stack/validatingNestedParentheses.cpp)

---

## 🔄 Infix to Postfix Conversion

Infix expressions (like `A + B`) require precedence rules and parentheses, while **postfix** expressions (like `AB+`) do not.

### 💡 Rules

1. **Operands (variables or numbers)** are added directly to output.
2. **Operators** are pushed onto a stack.
3. **Left parenthesis** `(` is pushed to the stack.
4. **Right parenthesis** `)` causes popping until matching `(` is found.
5. Operators are popped based on **precedence and associativity**.

---

## 🧪 Infix to Postfix – Examples

| Infix Expression                        | Postfix Output                  |
|----------------------------------------|----------------------------------|
| `A + B`                                | `AB+`                            |
| `(A + B) * C`                          | `AB+C*`                          |
| `A + B * C`                            | `ABC*+`                          |
| `A * B + C`                            | `AB*C+`                          |
| `A + (B - C) * D`                      | `ABC-D*+`                        |
| `(A + B) * (C - D)`                    | `AB+CD-*`                        |
| `A + (B * C - D) + (E / F / (G + H))`  | `ABC*D-+EF/GH+/+`                |

📘 These examples help visualize how expressions are transformed using stack operations.

---

## 📤 Postfix Expression Evaluation

Postfix (or Reverse Polish Notation) is easy to evaluate using stacks and avoids the need for parentheses.

- Read the expression left to right
- Push operands onto the stack
- On encountering an operator:
  - Pop two operands
  - Apply the operator
  - Push the result back

🔗 **Code Example on GitHub:**  
[Solving Postfix Format - C Implementation](https://github.com/0marwalied/Data-Structures-Book/blob/main/Stack/solvingPostfixFormat.c)

