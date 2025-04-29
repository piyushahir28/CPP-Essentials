# Copy Constructor in C++

## What is a Copy Constructor?

A **copy constructor** is a special constructor used to create a **new object** as a **copy of an existing object**.

```cpp
ClassName(const ClassName& other);
```

## Example of Copy Constructor

```cpp
#include <iostream>
using namespace std;

class Sample {
    int value;

public:
    Sample(int v) : value(v) {}

    // Copy constructor
    Sample(const Sample& obj) {
        cout << "Copy Constructor called\n";
        value = obj.value;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Sample a(10);
    Sample b = a;  // Copy constructor called
    b.display();
}
```

## Why Define a User-Defined Copy Constructor?

C++ provides a **default copy constructor** that does a **shallow copy**. This is fine for simple types, but problematic when:

- Your class **manages dynamic memory**
- You want a **deep copy**
- You need to add **logging or constraints**

### Problem with Default Copy Constructor

```cpp
class MyClass {
    int* ptr;

public:
    MyClass(int val) {
        ptr = new int(val);
    }

    // Default copy constructor → shallow copy
    ~MyClass() {
        delete ptr;
    }
};

int main() {
    MyClass a(5);
    MyClass b = a;  // ❌ Both a and b have same ptr → double free on destruction
}
```

### Fix with User-Defined Copy Constructor

```cpp
MyClass(const MyClass& obj) {
    ptr = new int(*(obj.ptr));  // Deep copy
}
```

## Copy Elision (Optimization)

Copy Elision is a compiler optimization where unnecessary calls to the copy constructor are eliminated — even if a copy seems to happen in code.

### Why it happens?

> To improve performance — avoid creating temporary objects.

```cpp
#include <iostream>
using namespace std;

class Demo {
public:
    Demo() { cout << "Constructor\n"; }
    Demo(const Demo&) { cout << "Copy Constructor\n"; }
};

Demo create() {
    return Demo();  // Normally looks like: create a temporary object, then copy it.
}

int main() {
    Demo obj = create();  // Only "Constructor" is printed — no "Copy Constructor"
}
```

> The compiler optimizes and constructs `Demo` directly in `obj`, skipping the copy.

## Copy Constructor vs Assignment Operator

| Feature               | Copy Constructor                    | Assignment Operator                      |
| --------------------- | ----------------------------------- | ---------------------------------------- |
| Purpose               | Create new object from existing one | Copy values to an existing object        |
| Called when           | Object is initialized               | Object is already created                |
| Syntax                | `ClassName(const ClassName&)`       | `ClassName& operator=(const ClassName&)` |
| Allocates new memory? | Yes (in deep copy)                  | No (usually reuses existing memory)      |

> **Copy Constructor:** Making a photocopy of a document while creating it.
>
> **Assignment Operator:** You already have two papers, now you're replacing the content of one with the other.

## Interview Q&A:

**Q1: What happens if you don’t define a copy constructor?**  
A: The compiler provides a default one that performs a shallow copy.

**Q2: Can copy constructor be private?**  
A: Yes, to prevent copying of objects (e.g., singleton design pattern).

**Q3: What is the difference between `Test t = other;` and `t = other;`?**  
A: First invokes the copy constructor, second uses assignment operator.

**Q4: What is copy elision?**  
A: It's an optimization to eliminate unnecessary copies, often with return-by-value.
