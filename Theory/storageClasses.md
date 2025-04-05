# Storage Classes

Storage Classes are used to describe the characteristics of a variable/function. It determines the lifetime, visibility, default value, and storage location which helps us to trace the existence of a particular variable during the runtime of a program. Storage class specifiers are used to specify the storage class for a variable.

Types of Storage Classes:

- `auto`:
  - Default for all local variables.
  - Automatically determines the data type (in modern C++).
  - Rarely used nowadays with auto keyword meaning something else in C++11+.

```c++
void func() {
    auto int x = 5;  // Old style (not used now)
    cout << x;
}
```

In mordern C++, `auto` means _type deduction_.

```c++
auto x = 10; // Compiler infers int
```

- `register`:
  - Suggests storing the variable in a CPU register for fast access.
  - You can’t get the address of a register variable using `&`.

```c++
void func() {
    register int counter = 0;
    for (counter = 0; counter < 5; counter++) {
        cout << counter << " ";
    }
}
```

- `static`:
  - Retains its value between function calls.
  - For global variables, limits the scope to the file (internal linkage).

```c++
void demo() {
    static int count = 0;
    count++;
    cout << "Count: " << count << endl;
}

int main() {
    demo();  // Count: 1
    demo();  // Count: 2
    demo();  // Count: 3
}

```

- `extern`:
  - Used to declare a global variable defined in another file.
  - Tells the compiler "this variable exists, but somewhere else".

File1.cpp

```c++
int num = 10;

```

File 2.cpp

```c++
extern int num;
cout << "Value of num: " << num;
```

- `mutable`: Sometimes there is a requirement to modify one or more data members of class/struct through the const function even though you don’t want the function to update other members of class/struct. This task can be easily performed by using the mutable keyword. The keyword mutable is mainly used to allow a particular data member of a const object to be modified.

```c++
#include <iostream>
using namespace std;

class A {
public:
    int x;

    // Defining mutable variable y
    // now this can be modified
    mutable int y;

    A(): x(4), y(10) {}
};

int main() {

    // a is created as constant
    const A a;

    // Trying to change the value
    a.y = 200;
    cout << a.y;

    // Uncommenting below lines
    // will throw error
    /* a.x = 8;
    cout << a.x; */

    return 0;
}
```

| Storage Class | Keyword        | Lifetime       | Visibility      | Initial Value |
| ------------- | -------------- | -------------- | --------------- | ------------- |
| Automatic     | `auto`         | Function Block | Local           | Garbage       |
| External      | `extern`       | Whole Program  | Global          | Zero          |
| Static        | `static`       | Whole Program  | Local           | Zero          |
| Register      | `register`     | Function Block | Local           | Garbage       |
| Mutable       | `mutable`      | Class          | Local           | Garbage       |
| Thread Local  | `thread_local` | Whole Thread   | Local or Global | Garbage       |
