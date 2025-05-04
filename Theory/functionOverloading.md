# Function Overloading in C++

**Function Overloading** means having **multiple functions** in the same scope **with the same name but different parameters**.

C++ decides which function to call based on **the number, type, and order of parameters**.

```cpp
#include<iostream>
using namespace std;

class Print {
public:
    void show(int i) {
        cout << "Integer: " << i << endl;
    }
    void show(double d) {
        cout << "Double: " << d << endl;
    }
    void show(string s) {
        cout << "String: " << s << endl;
    }
};

int main() {
    Print p;
    p.show(5);
    p.show(3.14);
    p.show("Hello");
}
```

## Functions That **Cannot Be Overloaded**

| Case                                          | Reason               |
| :-------------------------------------------- | :------------------- |
| Functions differing only by return type       | Not allowed          |
| Functions differing only by default arguments | Ambiguous            |
| `main()` function                             | Cannot be overloaded |

## Function Overloading and `const`

C++ allows functions to be overloaded on the basis of the const-ness of parameters only if the const parameter is a reference or a pointer.

- `const` can create different overloads.

```cpp
void print(int x);
void print(const int x); // Different from above
```

| Aspect         | Explanation                                                         |
| :------------- | :------------------------------------------------------------------ |
| `const` object | Can call only `const` member functions.                             |
| Overloading    | `const` can help overload functions based on object/parameter type. |
| Mutability     | `const` ensures data members are not modified accidentally.         |

## Function Overloading and Return Type

- Return type **alone** cannot distinguish overloaded functions.

```cpp
int func(int x);
float func(int x); // Error: Cannot overload only by return type
```

## Function Overloading and `float`

```cpp
void fun(float x);
void fun(double x);

int main() {
    fun(3.5f); // Calls float version
    fun(3.5);  // Calls double version
}
```

## 🤔 Can `main()` be overloaded?

- **No**, `main()` cannot be overloaded.
- It has a **special signature** understood by the OS:
  - `int main()`
  - `int main(int argc, char* argv[])`
- To overload main() function in C++, it is necessary to use class and declare the main as member function. Note that main is not reserved word in programming languages like C, C++, Java and C#. For example, we can declare a variable whose name is main.

### Difference: Function Overloading vs Overriding

| Feature               | Overloading                    | Overriding                               |
| :-------------------- | :----------------------------- | :--------------------------------------- |
| Definition            | Same name, different signature | Same signature in base and derived class |
| Scope                 | Within same class              | Across base and derived class            |
| Binding Time          | Compile time                   | Runtime                                  |
| Requires inheritance? | No                             | Yes                                      |

## Interview Questions on Function Overloading

### Q1. What is function overloading?

> Defining multiple functions with the same name but different parameter lists.

### Q2. Can you overload functions differing only in return type?

> **No**, it will cause a compiler error.

### Q3. What role does `const` play in overloading?

> `const` can differentiate overloaded functions if used properly.

### Q4. Can constructors be overloaded?

> **Yes**, constructor overloading is very common.

### Q5. Why is overloading useful?

> Simplifies the API/interface by grouping similar operations under one function name.
