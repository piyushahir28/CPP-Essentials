# Classes and Objects

## Friend Class and Friend Function in C++

### What is a `friend` in C++?

The `friend` keyword allows a **non-member function or another class** to access **private and protected members** of a class.

> It's a **controlled breach of encapsulation**, useful in tightly coupled scenarios.

### Friend Function

A **friend function** is a non-member function that can access private and protected members.

```cpp
class ClassName {
    friend void friendFunction(ClassName obj);
};
```

**Example**

```cpp
#include <iostream>
using namespace std;

class Box {
private:
    int length = 10;

public:
    friend void printLength(Box b);  // Declaration
};

void printLength(Box b) {
    cout << "Length: " << b.length << endl;  // Accessing private member
}

int main() {
    Box b;
    printLength(b);
}
```

### Friend Class

A **friend class** can access private and protected members of another class.

```cpp
class B;  // Forward declaration

class A {
    friend class B;
private:
    int secret = 42;
};

class B {
public:
    void reveal(A a) {
        cout << "Secret is: " << a.secret << endl;
    }
};
```

### When to Use `friend`?

| Use Case             | Reason                            |
| -------------------- | --------------------------------- |
| Operator overloading | Needs access to private members   |
| Tight coupling       | One class closely manages another |
| Utility functions    | Debug or inspect class internals  |

### Important Notes

- Friendship is **not mutual** – if A is a friend of B, B is **not** a friend of A.
- Friendship is **not inherited** – derived classes don’t inherit friendship.
- Use it **sparingly** – it breaks encapsulation if overused.

### Interview Q&A

**Q: Can a function be a friend of more than one class?**  
✅ Yes, declare it as `friend` in each class.

**Q: Is friendship mutual or inherited?**  
❌ No. Must be explicitly declared.

**Q: Main use of friend functions?**  
✅ Operator overloading or cross-class internal access.

## Local Classes in C++

### What is a Local Class?

- A **local class** is a **class defined inside a function** (even inside `main`).
- **Scope is limited** to that function only.
- **Cannot be accessed outside** the function where it is defined.

> Useful when you need **temporary classes** for **function-specific tasks**.

```cpp
#include <iostream>
using namespace std;

void myFunction() {
    class Local {
    public:
        void display() {
            cout << "I am a local class!" << endl;
        }
    };

    Local obj;
    obj.display();
}

int main() {
    myFunction();
    // Local obj2; // ❌ Error: 'Local' is not visible here
}
```

### How to Access Local Class

- Create objects inside the **same function** where it is defined.
- Cannot access from outside the function.

### Restrictions of Local Classes

| Restriction                                  | Explanation                                |
| :------------------------------------------- | :----------------------------------------- |
| Access Only Inside                           | Can only be used inside the function       |
| No Static Data Members                       | Cannot have static data members            |
| No Templates                                 | Cannot define templates inside local class |
| Cannot Access Non-static Local Variables     | Unless passed explicitly                   |
| Static Member Functions are Allowed          | Static functions are allowed               |
| Access to Global Variables                   | Allowed                                    |
| Access Enclosing Function’s Static Variables | Allowed                                    |

### Example Showing Restrictions

```cpp
#include <iostream>
using namespace std;

void myFunction() {
    int a = 10; // non-static local variable

    class Local {
    public:
        // void show() { cout << a; } // ❌ Error

        void display() {
            cout << "Inside Local Class" << endl;
        }

        static void staticFunc() {
            cout << "Static function in Local Class" << endl;
        }
    };

    Local obj;
    obj.display();
    Local::staticFunc();
}

int main() {
    myFunction();
}
```

### Where Local Classes Are Useful?

- Temporary helper classes inside functions.
- Encapsulation inside a function.
- Callbacks, functors, or testing small scopes.
