# 🧮 Custom Floating-Point Notation (Base 10)

This document describes a custom 32-bit floating-point representation for real numbers, inspired by scientific notation but tailored for simplicity and exactness in base 10.

---

## 📌 Format Overview

Each floating-point number is represented by **32 bits**, split into:

- **Mantissa (24 bits)**: Two’s complement signed **integer**, representing the significant digits. Must have **no trailing zeros**.
- **Exponent (8 bits)**: Two’s complement signed **integer**, representing the power of 10.
- **Base**: Fixed at **10**

### 🧠 Formula

`Value = Mantissa × 10^Exponent`

---

## 🔢 Binary Structure

| Bits         | Purpose      | Format              |
|--------------|--------------|---------------------|
| 0–23         | Mantissa     | 24-bit two’s complement integer |
| 24–31        | Exponent     | 8-bit two’s complement integer  |
| Base         | Constant     | 10                  |

---

## ✅ Examples

| Decimal Value | Mantissa (24-bit)             | Exponent (8-bit) | Binary Representation                       |
|---------------|-------------------------------|------------------|---------------------------------------------|
| **0**         | `000000000000000000000000`     | `00000000`       | `000000000000000000000000 00000000`         |
| **100**       | `000000000000000000000001`     | `00000010`       | `000000000000000000000001 00000010`         |
| **0.5**       | `000000000000000000000101`     | `11111111` (-1)  | `000000000000000000000101 11111111`         |
| **12000**     | `000000000000000000001100` (12)| `00000011` (3)   | `000000000000000000001100 00000011`         |
| **-12000**    | `111111111111111111110100` (-12)| `00000011` (3)   | `111111111111111111110100 00000011`         |

---

## ⚙️ Notes

- The **mantissa must not contain trailing zeros**, so `12000` is stored as `12 × 10³`, not `12000 × 10⁰`.
- Both mantissa and exponent are in **two’s complement**, allowing for negative numbers.
- This format is **not based on IEEE-754** and may not be implemented by hardware directly — it is a logical model used for educational or custom use cases.

---

## 🔧 Optional: Python Encoding Function

```python
def encode_custom_float(value: float):
    import math
    if value == 0:
        return '0' * 32

    sign = -1 if value < 0 else 1
    abs_val = abs(value)
    exponent = int(math.floor(math.log10(abs_val)))
    mantissa = int(sign * abs_val / (10 ** exponent))

    # remove trailing zeros in mantissa
    while mantissa % 10 == 0:
        mantissa //= 10
        exponent += 1

    mantissa_bin = format((mantissa + (1 << 24)) % (1 << 24), '024b')
    exponent_bin = format((exponent + (1 << 8)) % (1 << 8), '08b')

    return f"{mantissa_bin} {exponent_bin}"
