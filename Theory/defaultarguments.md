# Deafult arguments in C++

In C++, default arguments are values given in function declarations that are used if no value is passed during the function call.

## Syntax:

```c++
void functionName(int a, int b = 10);  // b has a default value
```

## Example:

```c++
#include <iostream>
using namespace std;

void greet(string name = "Guest") {
    cout << "Hello, " << name << "!" << endl;
}

int main() {
    greet();            // Output: Hello, Guest!
    greet("Piyush");    // Output: Hello, Piyush!
}
```

## Where Are They Used?

- Optional parameters
- Backward compatibility (adding parameters without breaking old code)
- Simplifying function calls

## Rules:

- Default values must be specified from right to left (trailing parameters).
- Can be given only once (either in declaration or definition, not both).
- You can't skip arguments in the middle while calling.
