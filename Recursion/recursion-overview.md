# 🌀 Recursion Overview

Recursion is a fundamental programming concept wherein a function calls itself directly or indirectly to solve a problem. It is widely used in computer science for tasks such as traversing data structures, solving complex problems elegantly, and implementing algorithms.

---

## 📘 Key Concepts

1. **Base Case**:

   - A condition that stops the recursion to prevent infinite loops.
   - Example: In calculating factorial, the base case is when `n == 0`.

2. **Recursive Case**:

   - The part of the function that reduces the problem size and calls itself.
   - Example: `factorial(n) = n * factorial(n-1)`.

3. **Call Stack**:
   - Each recursive call adds a frame to the stack.
   - Too many calls can lead to "stack overflow."

---

## 📂 Examples and Tracing

### 1. **Factorial Calculation**

- **Definition**:
  - `n! = 1` if `n = 0`
  - `n! = n * (n - 1) * ... * 1` if `n > 0`
- **Idea**: Factorial of a number `n` is the product of all positive integers less than or equal to `n`.
- **Tracing**:

  - For `factorial(3)`:  
    `factorial(3) -> 3 * factorial(2)`  
    `factorial(2) -> 2 * factorial(1)`  
    `factorial(1) -> 1 * factorial(0)`  
    `factorial(0) -> 1` (base case)  
    Result: `3 * 2 * 1 * 1 = 6`

- **Source Code**:
  - [Factorial Function](https://github.com/0marwalied/Data-Structures-Book/blob/9b164915a156894529662e14d82c129e867807e0/Recursion/recursionExamples.c#L8)

---

### 2. **Multiplication of Natural Numbers**

- **Definition**:
  - `a * b = a` if `b = 1`
  - `a * b = a * (b - 1) + a` if `b > 1`
- **Idea**: Multiply two natural numbers using recursion by repeated addition.
- **Tracing**:

  - For `multiply(4, 3)`:
    `multiply(4, 3) -> 4 + multiply(4, 2)`  
    `multiply(4, 2) -> 4 + multiply(4, 1)`  
    `multiply(4, 1) -> 4 + multiply(4, 0)`  
    `multiply(4, 0) -> 0` (base case)  
    Result: `4 + 4 + 4 = 12`

- **Source Code**:
  - [Multiplication Function](https://github.com/0marwalied/Data-Structures-Book/blob/9b164915a156894529662e14d82c129e867807e0/Recursion/recursionExamples.c#L25)

---

### 3. **Fibonacci Sequence**

- **Definition**:
  - `fib(n) = n` if `n = 0` or `n = 1`
  - `fib(n) = fib(n-1) + fib(n-2)` if `n >= 2`
- **Idea**: Fibonacci sequence is defined as:  
  `fib(0) = 0, fib(1) = 1, fib(n) = fib(n-1) + fib(n-2)`
- **Tracing**:

  - For `fib(4)`:
    `fib(4) -> fib(3) + fib(2)`  
    `fib(3) -> fib(2) + fib(1)`  
    `fib(2) -> fib(1) + fib(0)`  
    `fib(1) -> 1` (base case)  
    `fib(0) -> 0` (base case)  
    Result: `fib(4) = 3 + 2 = 5`

- **Source Code**:
  - [Fibonacci Function](https://github.com/0marwalied/Data-Structures-Book/blob/9b164915a156894529662e14d82c129e867807e0/Recursion/recursionExamples.c#L42)

---

### 4. **Binary Search**

- **Definition**:
  - If `low > high`, return `-1`
  - `mid = (low + high) / 2`
  - If `x == a[mid]`, return `mid`
  - If `x < a[mid]`, search for `x` in `a[low]` to `a[mid-1]`
  - Else, search for `x` in `a[mid+1]` to `a[high]`
- **Idea**: Search for an element in a sorted array by dividing the array into halves recursively.
- **Tracing**:

  - Array: `[1, 3, 5, 7, 9]`, Target: `5`
    - `binarySearch(arr, 5)`:
      - Divide: `[1, 3, 5]` (left half), `[7, 9]` (right half)
      - Compare middle: `5 == Target`  
        Result: Found at index `2`.

- **Source Code**:
  - [Binary Search Function](https://github.com/0marwalied/Data-Structures-Book/blob/9b164915a156894529662e14d82c129e867807e0/Recursion/recursionExamples.c#L67)

---

### 5. **Algebraic Expressions Validation**

- **Definition**:
  - Validates algebraic expressions recursively by breaking them into components like expressions, terms, and factors.
- **Idea**: Uses recursion to parse and validate expressions in the form of strings.
- **Source Code**:
  - [Recursive Algebraic Expressions Validator](https://github.com/0marwalied/Data-Structures-Book/blob/2b9f89e7579ead03597312cddd70c80a858f5c1b/Recursion/algebraic-expressions.md)

---

### 6. **Tower of Hanoi**

- **Definition**:
  - The Tower of Hanoi is a classic mathematical puzzle that demonstrates the power of recursion. It involves moving a series of disks from one rod to another following specific rules:
    1. Only one disk can be moved at a time.
    2. A disk can only be placed on top of a larger disk or an empty rod.
    3. The goal is to move all disks from the source rod to the destination rod.
- **Idea**:
  - The puzzle is solved recursively:
    - **Base Case**: If there is only one disk, move it directly from the source rod to the destination rod.
    - **Recursive Case**:
      - Move `n-1` disks from the source rod to the auxiliary rod.
      - Move the `nth` disk from the source rod to the destination rod.
      - Move the `n-1` disks from the auxiliary rod to the destination rod.
- **Source Code**:
  - [Tower of Hanoi Problem](https://github.com/0marwalied/Data-Structures-Book/blob/main/Recursion/tower-of-hanoi.md)

---

## ⚠️ Common Pitfalls

1. **Missing Base Case**:

   - Leads to infinite recursion and stack overflow.

2. **Inefficient Recursion**:

   - Recomputing values multiple times (e.g., Fibonacci without memoization).

3. **Stack Overflow**:
   - Too many recursive calls for large input sizes.

---

## 🌟 Best Practices

- Always define a clear base case.
- Use memoization or iterative versions for efficiency if needed.
- Test with edge cases to ensure correctness.

---

Recursion is a powerful tool in a programmer's arsenal. While it can be challenging to master, understanding its principles opens the door to solving complex problems elegantly.
