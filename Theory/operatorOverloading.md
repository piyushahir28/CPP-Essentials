# Operator Overloading in C++

```cpp
return_type operator op (arguments) {
    // your code
}
```

## Simple Example: Overloading `+` for a class

```cpp
#include<iostream>
using namespace std;

class Complex {
    int real, imag;
public:
    Complex(int r=0, int i=0) : real(r), imag(i) {}

    // Overloading + operator
    Complex operator + (const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;
    c3.display(); // 4 + 6i
}
```

## Types of Operator Overloading

| Type                                               | Example       | Description                                   |
| :------------------------------------------------- | :------------ | :-------------------------------------------- |
| **Unary Operator Overloading**                     | `-obj`        | Works with one operand                        |
| **Binary Operator Overloading**                    | `obj1 + obj2` | Works with two operands                       |
| **Overloading with Member Functions**              |               | Operator defined inside class                 |
| **Overloading with Non-member (Friend) Functions** |               | Operator defined outside class using `friend` |

## Criteria/Rules for Operator Overloading

- In the case of a non-static member function, the binary operator should have only one argument and the unary should not have an argument.
- In the case of a friend function, the binary operator should have only two arguments and the unary should have only one argument.
- Operators that cannot be overloaded are .\* :: ?:
- Operators that cannot be overloaded when declaring that function as friend function are = () [] ->.
- The operator function must be either a non-static (member function), global free function or a friend function.

## Operators That Cannot Be Overloaded

| Operator                                                        | Reason                   |
| :-------------------------------------------------------------- | :----------------------- |
| `::`                                                            | Scope resolution         |
| `.`                                                             | Member access            |
| `.*`                                                            | Pointer-to-member access |
| `sizeof`                                                        | Size of type or variable |
| `typeid`                                                        | Runtime type information |
| `?:`                                                            | Ternary conditional      |
| `const_cast`, `static_cast`, `dynamic_cast`, `reinterpret_cast` | Cast operators           |

## Functors (Function Objects)

```cpp
#include<iostream>
using namespace std;

class Adder {
    int value;
public:
    Adder(int v) : value(v) {}

    int operator()(int x) {
        return value + x;
    }
};

int main() {
    Adder add5(5);
    cout << add5(10); // Output: 15
}
```

### Quick Summary

| Feature             | Explanation                                        |
| :------------------ | :------------------------------------------------- |
| **Purpose**         | Customize operator behavior for user-defined types |
| **Functors**        | Objects that behave like functions                 |
| **Cannot overload** | `::`, `.`, `.*`, `sizeof`, `?:`, etc.              |
| **Rules**           | Must involve user-defined types                    |

### Interview Questions on Operator Overloading

| Question                                                            | Quick Answer                                                                                                   |
| :------------------------------------------------------------------ | :------------------------------------------------------------------------------------------------------------- |
| Why overload operators?                                             | For intuitive use of custom classes.                                                                           |
| Can you overload `.` operator?                                      | No.                                                                                                            |
| Difference between friend function and member function overloading? | Friend function takes **both operands** as parameters; member function takes **only one** (other is implicit). |
| Is it necessary to overload both `==` and `!=` together?            | Not necessary but recommended for logical consistency.                                                         |

---

> **Note:** Operator overloading makes code natural and expressive, but misuse can lead to confusing code. Use wisely!
