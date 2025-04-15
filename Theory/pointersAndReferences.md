# Pointers and References in C++

## Pointers:

A pointer is a variable that stores the **memory address** of another variable.

**Syntax:**

```c++
int x = 10;
int* ptr = &x;  // ptr stores address of x
```

**Example:**

```c++
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* p = &a;

    cout << "Value: " << *p << endl;      // 10
    cout << "Address: " << p << endl;     // address of a
}
```

### Types of Pointers:

| Pointer Type     | Description                                                                     |
| ---------------- | ------------------------------------------------------------------------------- |
| Null Pointer     | Points to nothing → `int* p = nullptr;`                                         |
| Dangling Pointer | Points to a deleted or out-of-scope object                                      |
| Void Pointer     | Can point to any data type → `void* p;`                                         |
| Function Pointer | Points to a function                                                            |
| Smart Pointer    | Modern C++ pointer from `<memory>` (e.g., `std::shared_ptr`, `std::unique_ptr`) |

## Reference:

A reference is an **alias** for another variable. It must be initialized when declared and **cannot be null**.

**Syntax:**

```c++
int x = 10;
int& ref = x;  // ref is another name for x
```

**Example:**

```c++
int a = 10;
int& r = a;

r = 20;
cout << a;  // Output: 20 (a is modified through r)
```

## Pointer vs Reference:

| Feature             | Pointer          | Reference                       |
| ------------------- | ---------------- | ------------------------------- |
| Can be reassigned   | ✅ Yes           | ❌ No (once assigned)           |
| Can be null         | ✅ Yes           | ❌ No (must refer to something) |
| Must be initialized | ❌ No            | ✅ Yes                          |
| Syntax              | Uses `*` and `&` | Uses `&`                        |
| Memory manipulation | ✅ Yes           | ❌ Not allowed                  |
