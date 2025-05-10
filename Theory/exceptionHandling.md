# Exception Handling in C++

Exceptions are unexpected problems or errors that occur while a program is running. For example, in a program that divides two numbers, dividing a number by 0 is an exception as it may lead to undefined errors.

The process of dealing with exceptions is known as **exception handling**. It allows programmers to make the program ready for any errors that may happen during execution and handle them gracefully so that it keeps running without errors.

- **Exception** = Runtime abnormality (e.g., divide by zero, file not found).
- **Exception Handling** = Mechanism to handle errors and maintain normal flow.

```cpp
try {
    // Code that might throw
} catch (Type e) {
    // Handle exception
}
```

**Example**

```cpp
#include<iostream>
using namespace std;

int main() {
    try {
        int a = 10, b = 0;
        if (b == 0)
            throw "Division by zero!";
        cout << a/b;
    } catch (const char* msg) {
        cout << "Exception caught: " << msg << endl;
    }
}
```

## Stack Unwinding

- Automatic destruction of local objects when an exception occurs.

Stack Unwinding is the process of removing function call frames from function call stack at run time. The local objects are destroyed in reverse order in which they were constructed.

Stack unwinding is a normal process that occurs when a function returns a value. But it can also occur due to exception handling in C++.

```cpp
class Test {
public:
    Test() { cout << "Constructor Called\n"; }
    ~Test() { cout << "Destructor Called\n"; }
};

int main() {
    try {
        Test t1;
        throw 100;
    } catch (int e) {
        cout << "Caught exception: " << e << endl;
    }
}
```

## Exception Handling Using Classes

**Custom Exception Class:**

```cpp
class MyException {
public:
    void display() {
        cout << "Custom Exception Occurred!" << endl;
    }
};

int main() {
    try {
        throw MyException();
    } catch (MyException& e) {
        e.display();
    }
}
```

## Built-in Exception Classes

| Exception Class    | Purpose        |
| ------------------ | -------------- |
| std::exception     | Base class     |
| std::bad_alloc     | Memory failure |
| std::out_of_range  | Range errors   |
| std::runtime_error | Runtime errors |
| std::logic_error   | Logic errors   |

```cpp
#include<exception>
using namespace std;

int main() {
    try {
        throw runtime_error("Something went wrong!");
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
}
```

### Custom Exception with Inheritance

```cpp
class MyException : public exception {
public:
    const char* what() const noexcept override {
        return "My Custom Exception";
    }
};

int main() {
    try {
        throw MyException();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}
```

### Exception in Constructor

```cpp
class Test {
public:
    Test() {
        throw runtime_error("Constructor Error!");
    }
};

int main() {
    try {
        Test t;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}
```

### Important Points

- Throw anything.
- Always **catch by reference**.
- Catch most generic exceptions **last**.

### Interview Questions

| Question                         | Answer                                         |
| -------------------------------- | ---------------------------------------------- |
| What is stack unwinding?         | Auto-calling destructors when exception occurs |
| Can constructor throw exception? | Yes                                            |
| Destructor throw exception?      | No, bad practice                               |
| Base class of all exceptions?    | `std::exception`                               |
| No matching catch block?         | Calls `std::terminate()`                       |
| What is noexcept?                | Specifies function won't throw                 |

### Summary Example

```cpp
#include<iostream>
#include<exception>
using namespace std;

class MyEx : public exception {
public:
    const char* what() const noexcept override {
        return "Custom Exception Thrown!";
    }
};

void test() {
    throw MyEx();
}

int main() {
    try {
        test();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}
```
