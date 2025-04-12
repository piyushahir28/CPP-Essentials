# Lambda Expressions in C++

A lambda expression is an anonymous function (i.e., it has no name) that can be defined inline.

**Syntax:**

```c++
[capture](parameter_list) -> return_type {
    // function body
}
```

**Example**

```c++
#include <iostream>
using namespace std;

int main() {
    auto greet = []() {
        cout << "Hello from lambda!" << endl;
    };
    greet();  // Output: Hello from lambda!
}
```

## Lambda Syntax Breakdown

| Component        | Purpose                                            |
| ---------------- | -------------------------------------------------- |
| `[ ]`            | Capture list – variables captured from outer scope |
| `( )`            | Parameter list – just like regular functions       |
| `-> return_type` | Optional – deduced automatically if omitted        |
| `{ }`            | Function body                                      |

## **Mutable Lambda:**

Allows modifying captured-by-value variables inside the lambda.

```c++
int x = 5;
auto modify = [x]() mutable {
    x += 10;
    cout << x << endl;  // Output: 15
};
modify();

cout << x << endl;  // Output: 5 (original x not changed)
```
