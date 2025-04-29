# Constructors in C++

## What is a Constructor?

A **constructor** is a special member function of a class that is **automatically called when an object is created**. It initializes class members.

```cpp
class MyClass {
public:
    MyClass() {
        cout << "Constructor called!" << endl;
    }
};
```

## Basic Rules

- Name is same as class name.
- No return type (not even void).
- Automatically called upon object creation.
- Can be **overloaded**.
- Can have **default arguments**.

## Types of Constructors

| Type                      | Description                             | Example                        |
| :------------------------ | :-------------------------------------- | :----------------------------- |
| Default Constructor       | No parameters                           | `MyClass();`                   |
| Parameterized Constructor | With parameters                         | `MyClass(int x);`              |
| Copy Constructor          | Copies another object                   | `MyClass(const MyClass &obj);` |
| Move Constructor          | Moves resource (C++11+)                 | `MyClass(MyClass&& obj);`      |
| Delegating Constructor    | Calls another constructor of same class | `MyClass() : MyClass(10) {}`   |
| Explicit Constructor      | Prevents implicit conversions           | `explicit MyClass(int x);`     |

## Importance of Constructors

- Initialize members
- Enforce object state
- Prevent uninitialized variables
- Handle dynamic memory or file handles safely

## Constructor Overloading

```cpp
class MyClass {
public:
    MyClass() {}
    MyClass(int x) { cout << x; }
    MyClass(double y) { cout << y; }
};
```

## Constructor Inheritance (C++11+)

Constructor Inheritance means a **derived class can reuse the constructors of its base class** without writing them again. We do this using the `using` keyword.
Normally, constructors are NOT inherited automatically from a base class. But C++11 introduced a feature called Constructor Inheritance to make this easier.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base(int x) {}
};

class Derived : public Base {
public:
    using Base::Base; // Inherits constructor
};

int main() {
    Derived d(10);  // Calls Base(int x)
    return 0;
}
```

👉 Even though Derived doesn't define any constructor, it can still accept an int and pass it to Base!

- `using Base::Base;` tells compiler to reuse all constructors of **Base**.
- It does not inherit destructor, assignment operator, etc. Only constructors.
- You can still define your own constructors in Derived alongside inherited ones.

## Member Initializer List

Used for:

- Initializing `const` and reference members
- Calling base class constructors
- Better performance

```cpp
class MyClass {
    const int a;
    int& ref;
public:
    MyClass(int x, int& y) : a(x), ref(y) {}
};
```

### Order of Initialization

- Always in **declaration order** in class, not initializer list order.

## Delegating Constructors

A delegating constructor is a constructor that calls another constructor of the same class to avoid repeating code. Introduced in C++11.

```cpp
class MyClass {
public:
    MyClass() : MyClass(100) {}
    MyClass(int x) { cout << x; }
};
```

## explicit Constructor

The explicit keyword in C++ prevents implicit conversions or copy-initialization when a constructor takes one argument.

By default, a constructor with one parameter allows automatic type conversion.
explicit blocks this behavior to avoid unintended bugs.

```cpp
class ClassName {
public:
    explicit ClassName(int x); // Explicit constructor
};
```

### Without explicit (Problematic)

```cpp
#include <iostream>
using namespace std;

class A {
public:
    A(int x) {
        cout << "Constructor called with x = " << x << endl;
    }
};

void printA(A obj) {
    cout << "Inside printA()" << endl;
}

int main() {
    printA(10); // Implicit conversion from int to A
}
```

Problem: 10 is implicitly converted to A(10), even if you didn't intend to.

### With explicit (Safe)

```cpp
class A {
public:
    explicit A(int x) {
        cout << "Constructor called with x = " << x << endl;
    }
};

void printA(A obj) {
    cout << "Inside printA()" << endl;
}

int main() {
    printA(10); // Compiler Error: no implicit conversion
}

```

### When to Use explicit?

- Your constructor takes a single parameter.
- You want to avoid implicit conversion.
- You’re guarding against unintended object creation from other types.

## Smart Pointers and Constructors

```cpp
#include <memory>
class MyClass {
public:
    MyClass() { cout << "Constructed"; }
};

std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
```

## Common Mistakes & Pitfalls

- Infinite recursion (calling self in constructor)
- Forgetting initializer list for `const`/ref
- Calling virtual methods from constructor
- Object slicing when copying base to derived

## Recursion in Constructor

```cpp
class A {
    A obj; // ❌ Infinite recursion
};
```

Fix using pointer:

```cpp
class A {
    A* obj;
};
```

---

## Object Slicing

```cpp
class Base {
public:
    int x;
};

class Derived : public Base {
public:
    int y;
};

Base b = Derived(); // y is sliced
```

## Best Practices

- Always use initializer list for const/ref
- Avoid logic-heavy constructors
- Prefer `explicit` for single-arg constructors
- Avoid calling virtual methods
- Use smart pointers for resource safety

## When Constructor is Called?

| Scenario                     | Description                                                                                      |
| ---------------------------- | ------------------------------------------------------------------------------------------------ |
| Object creation              | Constructor invoked when local, global, or dynamically allocated (using `new`) object is created |
| Inheritance                  | Base class constructor is called before derived class constructor                                |
| Containment (Member objects) | Member objects are constructed before the containing class                                       |
| Copy object                  | Copy constructor is called when an object is copied                                              |
| Pass-by-value                | Copy constructor is called when passed by value                                                  |
| Move semantics               | Move constructor is called when an object is moved                                               |
| Temporary object             | Created when returned by value or passed by value; may invoke move or copy constructor           |
| Return object                | May invoke move constructor or apply copy elision                                                |

## Interview Questions

| Question                        | Answer                                          |
| :------------------------------ | :---------------------------------------------- |
| Can constructors be virtual?    | ❌ No                                           |
| Can constructor return a value? | ❌ No                                           |
| Is constructor inherited?       | ❌ But can be reused using `using`              |
| What is initializer list?       | Used to initialize members before body executes |
| Can we overload constructor?    | ✅ Yes                                          |
| What is object slicing?         | Derived object copied to base → extra data lost |

## Summary

- Constructors are vital for clean, safe initialization.
- Use initializer list and smart pointers for safety.
- Avoid common pitfalls like recursion and slicing.
