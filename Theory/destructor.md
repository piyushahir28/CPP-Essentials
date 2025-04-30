# Destructor in C++

## What is Destructor?

- A special member function that is automatically called when an object goes out of scope or is deleted.
- It cleans up resources (memory, file handles, etc.) used by the object.

```cpp
class MyClass {
public:
    ~MyClass() {
        // cleanup code
    }
};
```

## Basic Example

```cpp
#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "Constructor called\n";
    }
    ~MyClass() {
        cout << "Destructor called\n";
    }
};

int main() {
    MyClass obj;
}
```

**Output:**

```cpp
Constructor called
Destructor called
```

## Important Rules

| Rule           | Explanation                         |
| -------------- | ----------------------------------- |
| Name           | Same as class but prefixed with `~` |
| Return type    | No return type, not even `void`     |
| Parameters     | No parameters                       |
| Automatic call | Destructor is automatically called  |
| One per class  | Only one destructor per class       |

## Private Destructor

### Why Private Destructor?

- To prevent object destruction outside the class.
- To force controlled deletion, often via friend classes or static functions.

### Example

```cpp
#include <iostream>
using namespace std;

class MyClass {
private:
    ~MyClass() {
        cout << "Private Destructor called\n";
    }
    friend void destroy(MyClass*);
public:
    MyClass() {
        cout << "Constructor called\n";
    }
};

void destroy(MyClass* p) {
    delete p;
}

int main() {
    MyClass* obj = new MyClass();
    destroy(obj);
}
```

## When is Destructor Called?

| Situation             | When Destructor is Called                  |
| --------------------- | ------------------------------------------ |
| Normal object         | When it goes out of scope                  |
| Dynamically allocated | When `delete` is called                    |
| Array of objects      | When `delete[]` is called                  |
| Inheritance           | Base class destructor called after derived |
| Exception thrown      | During stack unwinding                     |

## Virtual Destructor

### Why Virtual Destructor?

- Needed when deleting object via base class pointer.
- Ensures proper destruction of derived parts.

```cpp
#include <iostream>
using namespace std;

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
    Base* b = new Derived();
    delete b;
}
```

**Output:**

```
Derived Destructor
Base Destructor
```

### If Destructor is not Virtual:

- Only Base destructor would be called.
- Resource leak from Derived part.

### Quick Summary

| Aspect             | Key Points                      |
| ------------------ | ------------------------------- |
| Destructor call    | Automatic when object dies      |
| Private Destructor | Prevent deletion from outside   |
| Virtual Destructor | Needed for polymorphism cleanup |

### Interview Tips

- Always use `virtual` destructor for polymorphic base classes.
- Destructor cannot be overloaded.
- Use private destructors carefully (singleton, factory patterns).
