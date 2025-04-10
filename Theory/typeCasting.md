# Type Casting

Type casting means converting a variable from one data type to another. It is a way to change the data type of a variable. In C++, type casting can be done in two ways: implicit and explicit. Implicit type casting is done automatically by the compiler, while explicit type casting requires the programmer to specify the conversion. Additionally, it is important to understand the potential loss of data when converting from a larger data type to a smaller one. For example, converting a `double` to an `int` may result in the loss of the decimal part.

## Implicit Type Casting (Automatic)

- Done automatically by the compiler.
- Also called "type promotion".
- Happens when converting from lower to higher precision.

```c++
int x = 10;
float y = x;  // int to float conversion
cout << y;    // Output: 10.0
```

## Explicit Type Casting (Manual)

- Done manually by the programmer.
- You force the conversion using casting syntax.

```c++
float x = 5.75;
int y = (int)x; // Explicitly cast float to int
cout << y;      // Output: 5
```

## Types of Casts in C++

| Cast Type          | Purpose                                         |
| ------------------ | ----------------------------------------------- |
| `static_cast`      | Most common, safe for compatible types          |
| `dynamic_cast`     | Used with polymorphism (base ↔ derived classes) |
| `const_cast`       | Removes const/volatile from a variable          |
| `reinterpret_cast` | Dangerous, used for low-level conversions       |

1. `static_cast`:

- Used for converting between compatible types.
- Safer and more readable than C-style cast.

```c++
double d = 9.99;
int i = static_cast<int>(d);
cout << i;  // Output: 9
```

2. `dynamic_cast`:

- Used for safe downcasting in class hierarchies (i.e., base → derived).
- Requires at least one virtual function in the base class.

```c++
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {}
};

class Derived : public Base {
public:
    void display() {
        cout << "Derived class\n";
    }
};

int main() {
    Base* b = new Derived;
    Derived* d = dynamic_cast<Derived*>(b);
    if (d)
        d->display();  // Output: Derived class
    else
        cout << "Cast failed";
}
```

3. `const_cast`:

- Used to add/remove `const` or `volatile` qualifiers.

```c++
void print(int* p) {
    *p = 100;
    cout << *p << endl;
}

int main() {
    const int x = 50;
    print(const_cast<int*>(&x));  // Dangerous: modifying const
    return 0;
}
```

4. `reinterpret_cast`:

- Used for low-level, unsafe conversions (like pointer-to-int, int-to-pointer).
- Use only when absolutely necessary.

```c++
#include <iostream>
using namespace std;

int main() {
    int x = 65;
    char* ptr = reinterpret_cast<char*>(&x);
    cout << *ptr;  // Output: A (ASCII 65)
}
```
