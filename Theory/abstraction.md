# Abstraction in C++

## What is Abstraction?

- **Abstraction** means **hiding internal implementation details** and **showing only the essential features**.
- Focus on **what an object does**, not **how it does it**.

> **Example:** Drive a car without knowing how the engine works internally.

## 🔗 Key Points

| Concept              | Description                       |
| :------------------- | :-------------------------------- |
| Hiding Complexity    | User sees only necessary features |
| Show Only Essentials | Hide unneeded data/functions      |
| Interface-focused    | What to do, not how to do         |

```cpp
#include <iostream>
using namespace std;

// Abstract class
class AbstractDevice {
public:
    virtual void start() = 0; // Pure virtual function
    virtual void stop() = 0;  // Pure virtual function
};

class Fan : public AbstractDevice {
public:
    void start() override {
        cout << "Fan started." << endl;
    }

    void stop() override {
        cout << "Fan stopped." << endl;
    }
};

int main() {
    AbstractDevice* device = new Fan();
    device->start();
    device->stop();
    delete device;
    return 0;
}
```

- `AbstractDevice` provides an abstract view (`start()`, `stop()`)
- `Fan` implements how to **start** and **stop**

## How to Achieve Abstraction in C++?

| Method            | Description                                           |
| :---------------- | :---------------------------------------------------- |
| Abstract Classes  | Classes with at least one pure virtual function       |
| Interfaces        | Fully abstract class (all pure virtual functions)     |
| Access Specifiers | Hide unnecessary data/methods using private/protected |

## Why is Abstraction Useful?

- Reduces complexity for users.
- Helps in building scalable and maintainable systems.
- Provides security by exposing only relevant operations.
- Supports **polymorphism** and **design flexibility**.

## Real-life Analogy

| Real World         | Programming                                                 |
| :----------------- | :---------------------------------------------------------- |
| Using a TV remote  | Calling methods without knowing internal circuits           |
| Using a smartphone | Using functions like call, SMS without knowing OS internals |

## Interview Questions and Answers

| Question                                                                  | Answer                                                               |
| :------------------------------------------------------------------------ | :------------------------------------------------------------------- |
| What is abstraction?                                                      | Hiding complex implementation details and exposing only essentials.  |
| How do we achieve abstraction in C++?                                     | Using abstract classes and pure virtual functions.                   |
| Can abstraction exist without inheritance?                                | Partially, but full abstraction needs polymorphism (inheritance).    |
| Difference between abstraction and encapsulation?                         | Abstraction hides complexity; encapsulation hides data.              |
| What happens if we do not override a pure virtual function?               | Class remains abstract, cannot instantiate objects from it.          |
| What is a pure virtual function?                                          | `virtual void fun() = 0;` function without body, must be overridden. |
| Is it mandatory to implement all pure virtual functions in derived class? | Yes, otherwise derived class also becomes abstract.                  |

## Quick Interface Example

```cpp
class Interface {
public:
    virtual void show() = 0;
    virtual void hide() = 0;
};
```

- Fully abstract class = Interface
