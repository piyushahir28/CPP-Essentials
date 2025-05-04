# Polymorphism in C++

**Polymorphism** means "many forms". It allows the same interface (function/method) to behave differently for different types.

In C++, polymorphism is mainly achieved through **function overriding** and **virtual functions**.

**Types:**

- Compile-time Polymorphism (Static Binding)
- Run-time Polymorphism (Dynamic Binding)

## Types of Polymorphism

| Type                      | Description                               | How                                        |
| :------------------------ | :---------------------------------------- | :----------------------------------------- |
| Compile-time Polymorphism | Function behavior decided at compile time | Function Overloading, Operator Overloading |
| Run-time Polymorphism     | Function behavior decided at run time     | Virtual Functions, Function Overriding     |

### Compile-time Polymorphism Example

#### 1. Function Overloading

```cpp
#include<iostream>
using namespace std;

class Print {
public:
    void show(int i) {
        cout << "Integer: " << i << endl;
    }
    void show(string s) {
        cout << "String: " << s << endl;
    }
};

int main() {
    Print p;
    p.show(5);
    p.show("Hello");
}
```

### Run-time Polymorphism Example

#### 2. Function Overriding using Virtual Function

```cpp
#include<iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class show()" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show()" << endl;
    }
};

int main() {
    Base* bptr;
    Derived d;
    bptr = &d;

    bptr->show(); // Calls Derived's show() at runtime
}
```

## Function Overriding Types

| Type                  | Description                                         |
| :-------------------- | :-------------------------------------------------- |
| Simple Overriding     | Same signature in derived class                     |
| Covariant Return Type | Overridden function returns a derived class type    |
| Virtual Destructors   | Destructor must be virtual for polymorphic deletion |

### Example: Covariant Return Type

```cpp
class Base {
public:
    virtual Base* get() {
        cout << "Base get()\n";
        return this;
    }
};

class Derived : public Base {
public:
    Derived* get() override {
        cout << "Derived get()\n";
        return this;
    }
};

int main() {
    Base* b = new Derived();
    b->get();
    delete b;
}
```

## Important Concepts Related to Polymorphism

- **Virtual Functions**: Necessary for dynamic binding.
- **Pure Virtual Functions**: Used to create abstract classes.
- **Virtual Destructors**: Ensure correct destructor call order.
- **vtable (Virtual Table)**: Mechanism behind virtual function calls.
- **Early Binding vs Late Binding**: Compile-time vs Run-time resolution.

### Interview Questions on Polymorphism

#### Q1. What is polymorphism?

> It allows functions or methods to act differently based on the object type.

#### Q2. How does C++ achieve runtime polymorphism?

> Using **virtual functions** and **function overriding**.

#### Q3. What happens if the destructor is not virtual?

> Only the base class destructor is called, leading to **resource leaks**.

#### Q4. What is the use of vtable?

> It's a mechanism to map virtual function calls at runtime.

#### Q5. Can constructors be virtual?

> **No**, constructors can't be virtual.

### Best Practices

- Use `override` keyword for clarity.
- Always make base class destructors virtual when using polymorphism.
- Prefer abstract classes if some methods must be overridden.
