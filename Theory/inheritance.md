# Inheritance in C++

Inheritance is a feature of **Object-Oriented Programming (OOP)** where a class (child or derived class) acquires properties and behavior (methods) from another class (parent or base class).

```cpp
class Base {
    // members
};

class Derived : access_specifier Base {
    // members
};
```

## Types of Inheritance

| Type                         | Description                                   | Example                                   |
| :--------------------------- | :-------------------------------------------- | :---------------------------------------- |
| **Single Inheritance**       | One base and one derived class.               | `class B : public A {}`                   |
| **Multiple Inheritance**     | Multiple base classes, one derived class.     | `class C : public A, public B {}`         |
| **Multilevel Inheritance**   | Chain of inheritance.                         | `class C : public B; class B : public A;` |
| **Hierarchical Inheritance** | Multiple classes derived from one base class. | `class B : public A; class C : public A;` |
| **Hybrid Inheritance**       | Combination of two or more types.             | Mix of multiple and hierarchical          |

### Static Members and Inheritance

- Static members **belong to class** not objects.
- Inheritance doesn't create a new copy of static members.
- Accessible using `Derived::member` if `public` or `protected`.

```cpp
class Base {
public:
    static int count;
};

class Derived : public Base {};

int Base::count = 0;

int main() {
    Derived::count = 5;
}
```

## Constructors and Destructors in Inheritance

- **Base class constructor** is called **first**, then **derived**.
- **Destructor** called in **reverse order** (derived first, then base).

```cpp
#include<iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base Constructor\n"; }
    ~Base() { cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor\n"; }
    ~Derived() { cout << "Derived Destructor\n"; }
};

int main() {
    Derived obj;
}
```

**Output:**

```
Base Constructor
Derived Constructor
Derived Destructor
Base Destructor
```

## Multipath Inheritance (Diamond Problem)

### Example of Diamond Problem

```cpp
class A { public: int a; };
class B : public A {};
class C : public A {};
class D : public B, public C {}; // Problem: two copies of A
```

**Problem:** Ambiguity because D has **two copies of A**.

### Solution: Virtual Inheritance

```cpp
class A { public: int a; };
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};
```

Now, D has **only one copy** of A.

## Virtual Inheritance

- Used to avoid multiple copies of the base class when using multiple inheritance.
- Base class must be inherited using the keyword **`virtual`**.

### Does Friendship Inherit?

- **No.**
- A friend of a base class is **NOT** a friend of the derived class.

## Interview Questions on Inheritance

| Question                                  | Quick Answer                |
| :---------------------------------------- | :-------------------------- |
| When is constructor of base class called? | Before derived constructor. |
| Is destructor called in reverse?          | Yes.                        |
| How to solve diamond problem?             | Using virtual inheritance.  |
| Are static members inherited?             | Yes, but not duplicated.    |
| Does friendship inherit?                  | No.                         |

### Important Points

- Constructors and destructors are **NOT inherited**, but are **automatically called**.
- **Private members** are **not directly accessible** but are inherited.
- Use **protected** if you want members to be inherited but not accessible publicly.
- **Object Slicing:** Happens when a derived object is assigned to a base object (loses derived part).

## Big Example Combining Many Things

```cpp
#include<iostream>
using namespace std;

class A {
public:
    A() { cout << "A Constructor\n"; }
    ~A() { cout << "A Destructor\n"; }
};

class B : virtual public A {
public:
    B() { cout << "B Constructor\n"; }
    ~B() { cout << "B Destructor\n"; }
};

class C : virtual public A {
public:
    C() { cout << "C Constructor\n"; }
    ~C() { cout << "C Destructor\n"; }
};

class D : public B, public C {
public:
    D() { cout << "D Constructor\n"; }
    ~D() { cout << "D Destructor\n"; }
};

int main() {
    D obj;
}
```

**Output:**

```
A Constructor
B Constructor
C Constructor
D Constructor
D Destructor
C Destructor
B Destructor
A Destructor
```

> **Note:** Base constructor called once because of virtual inheritance!
