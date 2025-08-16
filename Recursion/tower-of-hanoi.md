# 🏰 Tower of Hanoi Problem

The **Tower of Hanoi** is a classic mathematical puzzle that demonstrates the power of recursion. It involves three rods (or pegs) and a number of disks of different sizes, stacked in decreasing order of size on one rod. The goal is to move the entire stack to another rod, following specific rules.

---

## 📜 Problem Rules
1. 🟠 **Move One Disk at a Time**: Only one disk can be moved per step.
2. 🟢 **Larger Disk Restriction**: A disk can only be placed on top of a larger disk or an empty rod.
3. 🔵 **Goal**: Move all disks from the source rod to the destination rod.

---

## 🔍 Algorithm
The puzzle is solved using recursion:
1. **Base Case**: If there is only one disk, move it directly from the source rod to the destination rod.
2. **Recursive Case**:
   - Move `n-1` disks from the source rod to the auxiliary rod.
   - Move the `nth` (largest) disk from the source rod to the destination rod.
   - Move the `n-1` disks from the auxiliary rod to the destination rod.

---

## 🧩 Example with Simulation

### Problem Setup:
- **Number of Disks**: 3
- **Pegs**: `A` (Source), `B` (Auxiliary), `C` (Destination)

### Initial State:
```
Peg A: [3, 2, 1]  (3 = largest, 1 = smallest)
Peg B: []
Peg C: []
```

### Steps to Solve:
1. Move disk `1` from `A` to `C`.
   ```
   Peg A: [3, 2]
   Peg B: []
   Peg C: [1]
   ```

2. Move disk `2` from `A` to `B`.
   ```
   Peg A: [3]
   Peg B: [2]
   Peg C: [1]
   ```

3. Move disk `1` from `C` to `B`.
   ```
   Peg A: [3]
   Peg B: [2, 1]
   Peg C: []
   ```

4. Move disk `3` from `A` to `C`.
   ```
   Peg A: []
   Peg B: [2, 1]
   Peg C: [3]
   ```

5. Move disk `1` from `B` to `A`.
   ```
   Peg A: [1]
   Peg B: [2]
   Peg C: [3]
   ```

6. Move disk `2` from `B` to `C`.
   ```
   Peg A: [1]
   Peg B: []
   Peg C: [3, 2]
   ```

7. Move disk `1` from `A` to `C`.
   ```
   Peg A: []
   Peg B: []
   Peg C: [3, 2, 1]
   ```

### Final State:
```
Peg A: []
Peg B: []
Peg C: [3, 2, 1]
```

---

## 📂 Source Code
The implementation of the Tower of Hanoi problem can be found [here](https://github.com/0marwalied/Data-Structures-Book/blob/main/Recursion/towerHanoiProblem.cpp).

---

## 🕒 Time Complexity
The algorithm has an exponential time complexity of **O(2^n)**, where `n` is the number of disks. This is because each recursive step involves two smaller subproblems and a single move.

---

The Tower of Hanoi is an elegant demonstration of recursion in action, showcasing how complex problems can be broken into smaller, manageable subproblems. 🌀✨
