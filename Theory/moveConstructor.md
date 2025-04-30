# Move Constructor in C++

## What is a Move Constructor?

A **Move Constructor** allows resources to be **moved** (not copied) from one object to another, avoiding expensive **deep copies**.

```cpp
ClassName(ClassName&& other);
```

- Takes an **rvalue reference** (`&&`).
- Transfers ownership of resources (like heap memory) from the **temporary object** (`other`) to the current object.

## Why/When is it Needed?

- When your class **manages dynamic memory** (e.g., with pointers).
- To **avoid deep copy overhead** when:
  - Returning large objects from functions
  - Inserting objects into STL containers (`std::vector`, etc.)

## Move Constructor vs Copy Constructor

| Feature     | Copy Constructor                  | Move Constructor                  |
| ----------- | --------------------------------- | --------------------------------- |
| Signature   | `ClassName(const ClassName& obj)` | `ClassName(ClassName&& obj)`      |
| Behavior    | Performs deep copy                | Transfers resources (steals data) |
| Use case    | Copying existing object           | Moving from temporary/rvalue      |
| Performance | Slower (alloc + copy)             | Faster (just pointer moves)       |

## Example

```cpp
#include <iostream>
#include <cstring>
using namespace std;

class MyClass {
public:
    char* data;

    MyClass(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        cout << "Constructor\n";
    }

    MyClass(const MyClass& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "Copy Constructor\n";
    }

    MyClass(MyClass&& other) noexcept {
        data = other.data;
        other.data = nullptr;
        cout << "Move Constructor\n";
    }

    ~MyClass() {
        delete[] data;
        cout << "Destructor\n";
    }
};

MyClass create() {
    return MyClass("Hello");
}

int main() {
    MyClass obj = create();  // Move constructor will be used
}
```

### Output

```cpp
Constructor
Move Constructor
Destructor
```

## When is Move Constructor Called?

- From rvalues or temporaries:

  ```cpp
  MyClass obj = create();
  MyClass obj2 = MyClass("Hi");
  ```

- With `std::move()`

  ```cpp
  MyClass a("World");
  MyClass b = std::move(a);
  ```

> If you define a move constructor, also define the **move assignment operator**.
> This is part of the **Rule of Five** when managing dynamic resources.

> `noexcept` is a C++ keyword that promises **this function will not throw any exception**. When you write a move constructor like this:
