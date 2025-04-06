# `static` in C++

The `static` keyword in C++ changes the lifetime and sometimes scope or linkage of a variable or function. It’s used in multiple contexts, each with a different effect.

## Use of `static` Keyword

| Use Case                  | Where Used            | Purpose                      |
| ------------------------- | --------------------- | ---------------------------- |
| 1. Static Local Variable  | Inside a function     | Retains value between calls  |
| 2. Static Global Variable | Outside all functions | Limits scope to the file     |
| 3. Static Member Variable | Inside a class        | Shared by all objects        |
| 4. Static Member Function | Inside a class        | Can be called without object |

1. **Static Local Variable**: Retains its value between function calls. It is initialized only once, and its lifetime lasts until the program ends.

```cpp
#include <iostream>
using namespace std;

void counter() {
    static int count = 0;
    count++;
    cout << "Count: " << count << endl;
}

int main() {
    counter(); // Count: 1
    counter(); // Count: 2
    counter(); // Count: 3
    return 0;
}

```

2. **Static Global Variable**: Limits the scope of a variable to the file in which it is declared. It cannot be accessed from other files.

```cpp
// file1.cpp
static int secret = 42;
```

3. **Static Member Variable in a Class**: A class member that is shared by all objects of the class. It is initialized only once and can be accessed without creating an object of the class.

```cpp
#include <iostream>
using namespace std;

class MyClass {
public:
    static int objCount;

    MyClass() {
        objCount++;
    }
};

int MyClass::objCount = 0;

int main() {
    MyClass a, b, c;
    cout << "Total objects created: " << MyClass::objCount << endl;
    return 0;
}

```

4. **Static Member Function**: A function that can be called without creating an object of the class. It can only access static member variables.

```cpp
class MyClass {
public:
    static void sayHello() {
        cout << "Hello from static function!" << endl;
    }
};

int main() {
    MyClass::sayHello();
    return 0;
}
```
