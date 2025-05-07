# Virtual Functions in C++

- A **virtual function** is a member function that you expect to be overridden in derived classes.
- Declared using the keyword `virtual` in the base class.
- Enables **runtime polymorphism** (dynamic dispatch).

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class show() called" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show() called" << endl;
    }
};

int main() {
    Base* bptr;
    Derived d;
    bptr = &d;
    bptr->show(); // Calls Derived::show() due to virtual
    return 0;
}
```

## Early Binding vs Late Binding

| Binding Type           | Description                               | Example               |
| ---------------------- | ----------------------------------------- | --------------------- |
| Early Binding (Static) | Function call is resolved at compile time | Normal function call  |
| Late Binding (Dynamic) | Function call resolved at runtime         | Virtual function call |

### Early Binding Example:

```cpp
void func() {
    cout << "Hello";
}
int main() {
    func(); // Resolved at compile time
}
```

### Late Binding Example:

See virtual function example above.

## VTable and vptr

- **VTable (Virtual Table)**: Table containing pointers to virtual functions.
- **vptr**: A hidden pointer maintained by the compiler inside the object to point to the VTable.

### How It Works:

- Each class with virtual functions has a VTable.
- Every object of such a class has a hidden vptr pointing to the class's VTable.
- At runtime, vptr is used to resolve the correct function call.

### Diagram

```
[Object] -> [vptr] -> [VTable]
```

## Virtual Function and Default Arguments

- **Default arguments are bound at compile-time**, not runtime.
- Default arguments are decided based on the static type of the pointer/reference.

### Example:

```cpp
class Base {
public:
    virtual void show(int x = 10) {
        cout << "Base x = " << x << endl;
    }
};

class Derived : public Base {
public:
    void show(int x = 20) override {
        cout << "Derived x = " << x << endl;
    }
};

int main() {
    Base* ptr = new Derived;
    ptr->show(); // Base x = 10 (Default from Base)
    return 0;
}
```

## Virtual Destructors

- Necessary when deleting a derived class object via a base class pointer.

```cpp
class Base {
public:
    virtual ~Base() {
        cout << "Base Destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived Destructor\n";
    }
};

int main() {
    Base* b = new Derived;
    delete b; // Calls Derived then Base destructor
}
```

## Virtual Constructors

- **Not possible** in C++.
- Constructors are meant for object creation; virtual mechanism requires an object to exist.

## Pure Virtual Function and Abstract Class

- **Pure virtual function**: `virtual void func() = 0;`
- **Abstract class**: Any class with at least one pure virtual function.

```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};
```

## Pure Virtual Destructor

- Can exist but must have a body!

```cpp
class Base {
public:
    virtual ~Base() = 0; // Pure virtual destructor
};

Base::~Base() {
    cout << "Base destructor body" << endl;
}
```

## Can Static Functions Be Virtual?

- **No**, because static functions are not tied to any object.

## RTTI (Run-Time Type Information)

- Used to identify the type of an object at runtime.
- `typeid` and `dynamic_cast` are examples.

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

class Base { virtual void foo() {} };
class Derived : public Base {};

int main() {
    Base* b = new Derived;
    cout << typeid(*b).name(); // Shows type Derived
    return 0;
}
```

## Private Virtual Functions

- Allowed!
- Useful with friend functions or internal usage.

### Example:

```cpp
class Base {
private:
    virtual void show() { cout << "Base::show()"; }
    friend int main(); // Main can call show
};

int main() {
    Base b;
    b.show(); // Ok due to friend
}
```

## Common Interview Questions

| Question                                  | Answer                                                |
| ----------------------------------------- | ----------------------------------------------------- |
| Why use virtual functions?                | Achieve runtime polymorphism                          |
| What is VTable?                           | Table of function pointers                            |
| Can constructor be virtual?               | No                                                    |
| Can destructor be pure virtual?           | Yes, with a body                                      |
| Difference between override and overload? | Override happens at runtime, overload at compile-time |
