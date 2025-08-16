# 📘 Simulation and Recursion Guide

This document explains the stages of execution for the two provided factorial simulation implementations: the **Original Simulation** and the **Optimized Simulation**. Each implementation follows a series of steps that simulate recursion using an explicit stack.

---

## 💡 Stages of Execution

1. **Passing Arguments**

   - The arguments (e.g., `n` for factorial) are passed to the simulation function.
   - These arguments are then stored in the stack or used directly to control the forward phase of the recursion.

2. **Allocating and Initializing Global Variables**

   - Global variables such as `stack`, `top`, and result-related variables (`y` and `result`) are initialized.
   - These variables handle the stack operations and store intermediate results.

3. **Transferring Control to the Function**
   - The function simulates recursion by transferring control between the **forward** and **backward phases**.
   - The execution flow is maintained using explicit stack operations like `push`, `pop`, and conditional checks for base cases.

---

## 📂 Original Simulation (File: [`simulationToFactorial.c`](https://github.com/0marwalied/Data-Structures-Book/blob/ab27ad9ba3a5b4570ccb12dfd0962502f6360d65/Recursion/simulationToFactorial.c))

### Stage 1: Passing Arguments

- The simulation function `simulationToFactorial` receives `n` as an argument.
- The value of `n` is stored in the current stack frame (`currArea.param`).

### Stage 2: Allocating and Initializing Global Variables

- The stack (`struct stack`) is initialized, including its `top` pointer and space for stack frames.
- The current stack frame (`currArea`) is initialized with default values, and the initial frame is pushed onto the stack.

### Stage 3: Transferring Control to the Function

- **Forward Phase**:
  - The function checks if the base case (`n == 0`) is reached. If so, the result is set to `1`.
  - Otherwise, the current parameter is decremented (`param - 1`), and the function pushes the updated stack frame before continuing.
- **Backward Phase**:
  - Once the base case is resolved, the function combines intermediate results (`result = y * param`) while popping stack frames.
  - The flow alternates between `forward` and `backward` phases until the stack is empty.

---

## 📂 Optimized Simulation (File: [`simulationToFactorialWithOptimization.c`](https://github.com/0marwalied/Data-Structures-Book/blob/ab27ad9ba3a5b4570ccb12dfd0962502f6360d65/Recursion/simulationToFactorialWithOptimization.c))

### Stage 1: Passing Arguments

- The simulation function `simulationToFactorialWithOptimization` receives `n` as an argument.
- The variable `x` is initialized with the value of `n`.

### Stage 2: Allocating and Initializing Global Variables

- The stack (`struct stack`) is initialized with space for storing parameters.
- The result variable `y` is initialized to hold intermediate results.

### Stage 3: Transferring Control to the Function

- **Forward Phase**:
  - The function checks if the base case (`x == 0`) is reached. If so, the result `y` is set to `1`.
  - Otherwise, the current parameter `x` is pushed onto the stack, and the function decrements `x` before continuing.
- **Backward Phase**:
  - After the base case is resolved, parameters are popped from the stack and combined into the result (`y *= x`).
  - The function alternates between `forward` and `backward` phases until the stack is empty.

---

## 🔍 Key Differences

| Stage                  | Original Simulation                    | Optimized Simulation                |
| ---------------------- | -------------------------------------- | ----------------------------------- |
| **Stack Content**      | Full stack frames (`param`, `x`, etc.) | Only parameters (`param`)           |
| **Base Case Handling** | Uses `result` and return addresses     | Directly modifies result `y`        |
| **Control Flow**       | Explicit return address handling       | Simpler forward and backward phases |

---

## 🧩 Conclusion

Both implementations demonstrate how recursion can be simulated explicitly using a stack. The **Original Simulation** is more general and closely resembles standard recursion, while the **Optimized Simulation** uses a streamlined approach to achieve the same result with fewer resources.
