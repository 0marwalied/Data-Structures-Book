# 📘 Introduction Overview

This document serves as an overview of two key topics covered in the "Intro" section of the repository: **Custom Floating-Point Notation** and **Rational Numbers Implementation**. These topics provide foundational knowledge and practical implementations for numerical data representation and manipulation.

---

## 1. 🧮 Custom Floating-Point Notation (Base 10)

This section covers a custom 32-bit floating-point representation designed for simplicity and exactness in base 10. The implementation is inspired by scientific notation but tailored for educational or custom use cases.

### Key Highlights:
- **32-bit Format**:
  - **Mantissa (24 bits)**: Represents the significant digits.
  - **Exponent (8 bits)**: Represents the power of 10.
  - **Base**: Fixed at 10.
- **Formula**:  
  `Value = Mantissa × 10^Exponent`
- **Examples**:
  - `100` is represented as `000000000000000000000001 00000010`.
  - `0.5` is represented as `000000000000000000000101 11111111`.

For a detailed explanation of the structure, examples, and implementation, refer to the file:  
[Custom Floating-Point Notation (Base 10)](https://github.com/0marwalied/Data-Structures-Book/blob/main/Intro/Floating%20Point%20Notation%20Problem.md)

---

## 2. 📘 Rational Numbers: Classes vs Structs

This section explores two approaches for implementing rational numbers in C++: **Class-Based Implementation** and **Struct-Based Implementation**. Both approaches demonstrate the use of operator overloading, validation, and simplification of fractions.

### Key Highlights:
- **Class-Based Implementation**:
  - Encapsulation and inheritance.
  - Supports arithmetic and stream operations.
  - Includes an `Integer` subclass for whole numbers.
- **Struct-Based Implementation**:
  - Simple design with public members.
  - Focuses on minimal overhead and straightforward functionality.

For a detailed comparison between the two implementations, examples, and code snippets, refer to the file:  
[Rational Numbers: Classes vs Structs](https://github.com/0marwalied/Data-Structures-Book/blob/a3fd80b267c159a579b506ddd1cc67c5aec69afc/Intro/rational-numbers-overview.md)

---

## 🧩 Conclusion

The topics covered in this section provide a solid foundation for understanding numerical data representation and manipulation. Whether it's designing a custom floating-point format or implementing rational numbers, these examples illustrate key programming concepts such as operator overloading, validation, and encapsulation.