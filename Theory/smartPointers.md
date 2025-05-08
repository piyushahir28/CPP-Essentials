# Smart Pointers in C++

Smart pointers in C++ are class templates provided by the C++ Standard Library that manage dynamic memory automatically. They ensure that memory is properly deallocated when no longer needed, preventing memory leaks.

**Why Smart Pointers?**

- Manual `new`/`delete` management is error-prone.
- Prevent memory leaks and dangling pointers.
- Provide ownership semantics.

## Types of Smart Pointers

|   Smart Pointer   | Purpose                                                                     |
| :---------------: | :-------------------------------------------------------------------------- |
| `std::unique_ptr` | Owns a resource exclusively. Only one `unique_ptr` can point to a resource. |
| `std::shared_ptr` | Shared ownership. Multiple `shared_ptr` can point to the same resource.     |
|  `std::weak_ptr`  | Non-owning reference to a `shared_ptr` resource.                            |

### Examples

### 1. `std::unique_ptr`

```cpp
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass created\n"; }
    ~MyClass() { std::cout << "MyClass destroyed\n"; }
};

int main() {
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
    // No need to delete, done automatically
}
```

### 2. `std::shared_ptr`

```cpp
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass created\n"; }
    ~MyClass() { std::cout << "MyClass destroyed\n"; }
};

int main() {
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    std::shared_ptr<MyClass> ptr2 = ptr1; // Both share ownership
    std::cout << "Reference count: " << ptr1.use_count() << "\n";
}
```

### 3. `std::weak_ptr`

```cpp
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass created\n"; }
    ~MyClass() { std::cout << "MyClass destroyed\n"; }
};

int main() {
    std::shared_ptr<MyClass> sp = std::make_shared<MyClass>();
    std::weak_ptr<MyClass> wp = sp; // Doesn't increase ref count

    if (auto temp = wp.lock()) {
        std::cout << "Object is still alive\n";
    }
}
```

## Differences between Smart Pointers

|     Feature     |    `unique_ptr`     |   `shared_ptr`   |       `weak_ptr`        |
| :-------------: | :-----------------: | :--------------: | :---------------------: |
|    Ownership    |       Single        |      Shared      |          None           |
| Reference Count |         No          |       Yes        |   Weak (observe only)   |
|    Use Case     | Exclusive resources | Shared resources | Avoid cyclic references |

## Other Concepts

- **Cyclic References:** Using only `shared_ptr` can cause cyclic references, preventing objects from being destroyed. `weak_ptr` helps break cycles.
- **Custom Deleters:** Smart pointers can accept custom deleters when created.
- **Performance:** `unique_ptr` is lighter and faster than `shared_ptr`.

## Interview Questions

### Q1: Why prefer `unique_ptr` over `shared_ptr`?

**Answer:** `unique_ptr` has no overhead of reference counting and enforces exclusive ownership.

### Q2: When do you use `weak_ptr`?

**Answer:** When you want a non-owning reference to a `shared_ptr` object to prevent cyclic references.

### Q3: Can you use smart pointers with arrays?

**Answer:** Yes, e.g., `std::unique_ptr<int[]> arr(new int[10]);`

### Q4: What happens if you copy a `unique_ptr`?

**Answer:** Compile-time error. `unique_ptr` is non-copyable but movable.

### Q5: How does `shared_ptr` manage the resource?

**Answer:** It uses a control block to keep track of the number of references.

### Best Practices

- Prefer `unique_ptr` by default.
- Use `shared_ptr` when multiple owners are needed.
- Break cycles with `weak_ptr`.
- Avoid manual `new`/`delete`.
- Use `make_shared` and `make_unique` instead of direct `new`.
