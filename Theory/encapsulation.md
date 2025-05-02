# Encapsulation in OOP (C++)

## What is Encapsulation?

- **Encapsulation** means **binding data and functions** that operate on that data **into a single unit (class)**.
- It **hides internal details** and **only exposes necessary operations**.

> **In simple words:** Data Hiding + Controlled Access = Encapsulation

## 🔗 Key Points

| Concept            | Description                                 |
| :----------------- | :------------------------------------------ |
| Data Hiding        | Hide internal data from outside world       |
| Access via Methods | Only access/modification via public methods |
| Protects Integrity | Prevents invalid state                      |
| Improves Security  | Controls who can modify the data            |

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance; // Private data member (Hidden)

public:
    BankAccount() : balance(0) {}

    void deposit(int amount) {
        if (amount > 0)
            balance += amount;
    }

    void withdraw(int amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
    }

    int getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account;
    account.deposit(1000);
    account.withdraw(200);
    cout << "Current Balance: " << account.getBalance() << endl;
    return 0;
}
```

- `balance` is private.
- Access only via `deposit()`, `withdraw()`, `getBalance()`.

### Why Encapsulation?

- Protects data from unintended modification.
- Easier maintenance and code changes.
- Improves modularity.
- Helps in achieving **abstraction**.

### Real-life Analogy

| Real World               | Programming                           |
| :----------------------- | :------------------------------------ |
| ATM Machine              | Interface (functions) to bank account |
| Bank Database            | Private data (hidden)                 |
| Withdraw/Deposit Buttons | Public methods                        |

### How to Implement Encapsulation in C++

- **Private** data members.
- **Public** getter and setter methods.

### Interview Questions and Answers

| Question                                          | Answer                                                           |
| :------------------------------------------------ | :--------------------------------------------------------------- |
| What is encapsulation?                            | Wrapping data and methods into a class, hiding internal details. |
| How to achieve it in C++?                         | By using private members and public methods.                     |
| Difference between encapsulation and abstraction? | Encapsulation hides data; abstraction hides complexity.          |
| Can a class exist without encapsulation?          | Yes, but it is unsafe.                                           |
| Does encapsulation mean private only?             | No, it's about controlled access, often with private data.       |
| Maintenance advantage?                            | Changes inside class do not affect outside code.                 |
