# Encapsulation vs Abstraction in C++

| Feature     | Encapsulation                                                          | Abstraction                                                      |
| :---------- | :--------------------------------------------------------------------- | :--------------------------------------------------------------- |
| Meaning     | Binding data and functions together, hiding data from outside          | Hiding complex implementation details, showing only essentials   |
| Focus       | **How** data is protected                                              | **What** functionality is exposed                                |
| Achieved By | Access specifiers (private, protected, public)                         | Abstract classes, interfaces, pure virtual functions             |
| Example     | Making class variables `private` and exposing `public` getters/setters | Providing a simple interface while hiding complex internal logic |
| Goal        | Protect the data                                                       | Hide complexity                                                  |

## Example (Encapsulation + Abstraction Together)

```cpp
#include <iostream>
using namespace std;

// Abstract Class for Abstraction
class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

// Encapsulation inside a concrete class
class SavingsAccount : public Account {
private:
    double balance; // Private Data (Encapsulation)

public:
    SavingsAccount(double initialBalance) {
        balance = initialBalance;
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << ", Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", Balance: " << balance << endl;
        }
    }
};

int main() {
    Account* acc = new SavingsAccount(1000);
    acc->deposit(500);
    acc->withdraw(200);
    acc->withdraw(2000); // Insufficient balance
    delete acc;
}
```

- **Encapsulation** protects the data from unauthorized access.
- **Abstraction** hides internal complexity and exposes only necessary parts.

Both are fundamental to achieve **security**, **simplicity**, and **reusability** in large software systems.

### Summary

| Point             | Encapsulation                             | Abstraction                             |
| :---------------- | :---------------------------------------- | :-------------------------------------- |
| Access Control    | YES                                       | NO                                      |
| Complexity Hiding | Partially                                 | Fully                                   |
| Achieved by       | Access specifiers                         | Abstract classes, Interfaces            |
| Example           | Private data members with getters/setters | Abstract classes exposing only behavior |
