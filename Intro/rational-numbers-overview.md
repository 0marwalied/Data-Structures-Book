# 📘 Rational Numbers: Classes vs Structs

This document explains the implementation of rational numbers using two approaches: **Class-Based Implementation** and **Struct-Based Implementation**. Both implementations provide functionality for working with rational numbers, focusing on operator overloading, validation, and simplification of fractions.

---

## 💡 Key Concepts

1. **Rational Numbers**:
   - Represented as `numerator/denominator`.
   - Must have a non-zero denominator.

2. **Validation**:
   - Ensures the denominator is not zero.
   - Simplifies fractions by removing common factors using the greatest common divisor (GCD).

3. **Operator Overloading**:
   - Enables arithmetic operations (`+`, `*`, `/`, etc.) directly on rational numbers.
   - Provides comparison and stream operations for input/output.

4. **Inheritance**:
   - Demonstrated in the class-based implementation with the `Integer` class.

---

## 📂 Class-Based Implementation (File: [`rationalClass.cpp`](https://github.com/0marwalied/Data-Structures-Book/blob/828547b6a6c037ce74f6379f907860609b9f7714/Intro/rationalClass.cpp))

### Features:
1. **Encapsulation**:
   - Implemented using a class with private/protected members.
   - Ensures internal consistency by hiding implementation details.

2. **Simplification**:
   - Fractions are simplified after every operation using the `removeAdditionalNumbers` method.

3. **Validation**:
   - Ensures the denominator is not zero using the `checkValiedFormat` method.

4. **Operator Overloading**:
   - Arithmetic (`+`, `*`, `/`, `+=`, `*=`).
   - Comparison (`==`).
   - Assignment (`=`).
   - Stream I/O (`<<`, `>>`).

5. **Inheritance**:
   - Demonstrated with the `Integer` class, which inherits from the `rational` class.

### Example Code:
```cpp
rational r1(3, 4), r2(1, 2);
rational result = r1 + r2; // Adds two rational numbers.
cout << result; // Outputs: 5/4
```

### Integer Subclass:
- Represents whole numbers as rational numbers with a denominator of 1.
- Inherits from the `rational` class.

### Example Code:
```cpp
Integer int1(5);
cout << int1; // Outputs: 5
```

---

## 📂 Struct-Based Implementation (File: [`rationalStruct.cpp`](https://github.com/0marwalied/Data-Structures-Book/blob/828547b6a6c037ce74f6379f907860609b9f7714/Intro/rationalStruct.cpp))

### Features:
1. **Simpler Design**:
   - Implemented using a struct with public data members.
   - Focuses on simplicity and minimal encapsulation.

2. **Simplification**:
   - Fractions are simplified using the `removeAdditionalNumbers` method.

3. **Validation**:
   - Ensures the denominator is not zero via the `checkValiedFormat` method.

4. **Operator Overloading**:
   - Arithmetic (`+`, `*`, `+=`, `*=`).
   - Comparison (`==`).
   - Stream I/O (`<<`, `>>`).

### Example Code:
```cpp
rational r1(3, 4), r2(1, 2);
rational result = r1 + r2; // Adds two rational numbers.
cout << result; // Outputs: 5/4
```

---

## 🔍 Key Differences Between Class and Struct

| Feature                | Class-Based Implementation            | Struct-Based Implementation         |
|------------------------|----------------------------------------|--------------------------------------|
| **Encapsulation**      | Uses private/protected members.       | All members are public.             |
| **Inheritance**        | Supports inheritance (`Integer`).     | No inheritance.                     |
| **Stream Overloading** | Uses `friend` functions.              | Uses `friend` functions.            |
| **Validation**         | Defined in `checkValiedFormat` method.| Defined in `checkValiedFormat` method. |
| **Simplification**     | Done automatically in constructors and methods. | Done explicitly in methods.         |

---

## 🧩 Conclusion

Both implementations serve as examples of working with rational numbers in C++:

- The **Class-Based Implementation** provides better encapsulation, supports inheritance, and adheres to object-oriented principles.
- The **Struct-Based Implementation** focuses on simplicity and is suitable for scenarios where minimal overhead is required.

Choose the implementation that best suits your project's needs. For complex applications, the class-based approach is recommended, while the struct-based approach is useful for lightweight tasks.