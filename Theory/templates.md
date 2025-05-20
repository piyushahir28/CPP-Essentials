# Templates in C++

Templates allow us to write generic and reusable code. They enable functions and classes to operate with any data type without rewriting code for each type.

## Types of Templates

### 1. Function Templates

```cpp
#include <iostream>
using namespace std;

template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << getMax(10, 20) << endl;
    cout << getMax(5.5, 2.3) << endl;
    cout << getMax('a', 'z') << endl;
    return 0;
}
```

### 2. Class Templates

```cpp
#include <iostream>
using namespace std;

template <class T>
class Calculator {
public:
    T a, b;
    Calculator(T x, T y) : a(x), b(y) {}
    T add() { return a + b; }
    T multiply() { return a * b; }
};

int main() {
    Calculator<int> obj1(10, 20);
    cout << obj1.add() << endl;

    Calculator<float> obj2(2.5, 4.1);
    cout << obj2.multiply() << endl;
    return 0;
}
```

### 3. Template Specialization

```cpp
#include <iostream>
using namespace std;

template <class T>
class Display {
public:
    void show(T x) {
        cout << "Generic: " << x << endl;
    }
};

template <>
class Display<char> {
public:
    void show(char x) {
        cout << "Character: " << x << endl;
    }
};

int main() {
    Display<int> d1;
    d1.show(100);

    Display<char> d2;
    d2.show('A');
    return 0;
}
```

> If you specialize a class template, you must re-define all required members (data and methods) in that specialization—even constructors—because it doesn't inherit from the primary template.

### 4. Variadic Templates (C++11 and above)

```cpp
#include <iostream>
using namespace std;

void print() {}

template <typename T, typename... Args>
void print(T first, Args... rest) {
    cout << first << " ";
    print(rest...);
}

int main() {
    print(1, 2.5, "hello", 'c');
    return 0;
}
```

## STL (Standard Template Library)

STL is a powerful library built using templates. It provides generic classes and functions.

### Components of STL

1. **Containers** - Store data: `vector`, `list`, `map`, `set`
2. **Algorithms** - Operate on containers: `sort`, `find`, `count`
3. **Iterators** - Access elements in containers
4. **Functors** - Objects that behave like functions

### Example

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 3, 9, 1};
    sort(v.begin(), v.end());

    for (int x : v)
        cout << x << " ";
    return 0;
}
```

## Benefits

- Code reusability
- Type safety
- Compile-time polymorphism
- Clean and modular code

## Interview Questions

### Q1. What are templates in C++?

Templates are used to create generic functions and classes.

### Q2. Difference between templates and macros?

Templates are type-safe and evaluated by the compiler, whereas macros are handled by the preprocessor and not type-safe.

### Q3. What is STL?

A collection of template-based classes and functions such as `vector`, `map`, and `sort`.

### Q4. Difference between `typename` and `class` in templates?

Both are interchangeable when declaring template parameters.

### Q5. What is a functor?

An object that behaves like a function using overloaded `operator()`.

### Q6. Can templates be specialized?

Yes, using template specialization you can define custom behavior for specific types.
