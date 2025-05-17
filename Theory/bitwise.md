# Bitwise Operators in C++

Bitwise operators perform operations on bits and are used for low-level programming, optimization, and embedded systems. They manipulate individual bits within an integer type (int, char, etc.).

## Bitwise Operators

| Operator | Name        | Description                              | Example                       | Result |     |     |
| -------- | ----------- | ---------------------------------------- | ----------------------------- | ------ | --- | --- |
| `&`      | AND         | Sets bit to 1 if both bits are 1         | `5 & 3`                       | `1`    |     |     |
| \`       | \`          | OR                                       | Sets bit to 1 if any bit is 1 | \`5    | 3\` | `7` |
| `^`      | XOR         | Sets bit to 1 if only one bit is 1       | `5 ^ 3`                       | `6`    |     |     |
| `~`      | NOT         | Inverts all the bits                     | `~5`                          | `-6`   |     |     |
| `<<`     | Left Shift  | Shifts bits left (adds zeros on right)   | `5 << 1`                      | `10`   |     |     |
| `>>`     | Right Shift | Shifts bits right (drops rightmost bits) | `5 >> 1`                      | `2`    |     |     |

### Binary Breakdown Example:

```cpp
// Binary: 5 = 0101, 3 = 0011
int a = 5, b = 3;
cout << (a & b); // 0001 => 1
cout << (a | b); // 0111 => 7
cout << (a ^ b); // 0110 => 6
```

## Bitwise Assignment Operators

| Operator | Usage Example | Meaning            |        |       |     |
| -------- | ------------- | ------------------ | ------ | ----- | --- |
| `&=`     | `a &= b;`     | a = a & b          |        |       |     |
| \`       | =\`           | \`a                | = b;\` | a = a | b   |
| `^=`     | `a ^= b;`     | a = a ^ b          |        |       |     |
| `<<=`    | `a <<= 2;`    | Shift a left by 2  |        |       |     |
| `>>=`    | `a >>= 2;`    | Shift a right by 2 |        |       |     |

## Practical Uses of Bitwise Operators

- Setting and clearing individual bits
- Masking bits
- Performance optimization
- Embedded systems and low-level programming
- Permissions systems (e.g., flags)

## Bit Masking Example

```cpp
int flags = 0b0000;
const int READ = 0b0001;
const int WRITE = 0b0010;
flags |= READ; // enable read
flags |= WRITE; // enable write
if (flags & READ) cout << "Read enabled";
```

## Interview Questions & Answers

**Q1: What is the use of bitwise AND `&` operator?**

> Used to mask bits, e.g., checking whether a specific bit is set.

**Q2: How does left shift `<<` operator work?**

> It shifts bits to the left, equivalent to multiplying by powers of two.

**Q3: What's the difference between `^` and `|`?**

> `^` (XOR) sets bit if only one operand has that bit set. `|` sets if any operand has it.

**Q4: What happens when we use `~` (bitwise NOT)?**

> Inverts all bits, often resulting in a negative number due to two's complement representation.

**Q5: Can bitwise operations be used on floating-point numbers?**

> No. Bitwise operations are only defined for integral types.

## Best Practices

- Use bitwise operations only when necessary for readability.
- Always document the purpose of bitmasks.
- Avoid mixing signed and unsigned types with bit shifts.
