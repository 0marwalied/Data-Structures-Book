# Recursive Definition of Algebraic Expressions

## Explanation

Recursive definitions can be used to describe algebraic expressions in a hierarchical structure:

1. **Expression**:

   - An expression is either:
     - A term followed by a `+` sign followed by another term, or
     - A term alone.

2. **Term**:

   - A term is either:
     - A factor followed by a `*` sign followed by another factor, or
     - A factor alone.

3. **Factor**:
   - A factor is either:
     - A single letter, or
     - An expression enclosed in parentheses.

## Indirect Recursion

None of the definitions directly reference themselves, but they are indirectly recursive:

- An **expression** refers to a **term**, which refers to a **factor**, which in turn refers back to an **expression**. This forms a recursive chain.

## Examples

Here are examples illustrating valid and invalid algebraic expressions:

- **Valid Expressions**:

  - `A`, `B`, `(A + B)`, `A * (B + C)`
  - These follow the recursive definitions.

- **Invalid Expressions**:
  - `A + *B`, `(A + YC`, `A + B * 4C`
  - These violate the recursive definitions.

## Implementation

To validate algebraic expressions programmatically, recursive functions can be written to check the structure:

1. **`expr` Function**:

   - Validates expressions.

2. **`term` Function**:

   - Validates terms.

3. **`factor` Function**:

   - Validates factors.

4. **`getsymb` Function**:

   - Retrieves the next character from the input string while skipping spaces.

5. **`readstr` Function**:
   - Reads the input string and removes trailing newline characters.

These functions form the backbone of validating algebraic expressions recursively.

## Source Code

For the complete implementation, refer to the source code:
[Recursive Algebraic Expressions Validator](https://github.com/0marwalied/Data-Structures-Book/blob/29df172127151d501ebefafca91a4354eeaa9609/Recursion/algebraicExpressionsRecursive.c)
