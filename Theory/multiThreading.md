# Multithreading and Thread Management in C++

- Multithreading allows a program to run multiple parts (threads) concurrently.
- Threads are independent sequences of execution within a program.
- Main advantage: improves performance by doing multiple operations simultaneously.

## How to Create Threads in C++

C++11 introduced the `<thread>` header.

```cpp
#include <iostream>
#include <thread>
using namespace std;

void function1() {
    cout << "Hello from thread function!" << endl;
}

int main() {
    thread t1(function1);
    t1.join();
    cout << "Main thread finished!" << endl;
    return 0;
}
```

## Thread Management

| Operation                | Explanation                                  |
| ------------------------ | -------------------------------------------- |
| `join()`                 | Wait for a thread to complete                |
| `detach()`               | Let a thread run independently               |
| `joinable()`             | Check if a thread is joinable before joining |
| `hardware_concurrency()` | Tells how many threads can run concurrently  |

```cpp
#include <iostream>
#include <thread>
using namespace std;

void func() {
    cout << "Inside thread\n";
}

int main() {
    thread t(func);
    if (t.joinable()) {
        t.join();
    }
    return 0;
}
```

## Problems in Multithreading

| Problem        | Meaning                                             | Example/Note                       |
| -------------- | --------------------------------------------------- | ---------------------------------- |
| Race condition | Two threads accessing/modifying data simultaneously | Use mutex to lock critical section |
| Deadlock       | Threads waiting forever for each other              | Lock ordering is important         |
| Starvation     | Some threads never get access to resources          | Fair locking                       |
| Livelock       | Threads keep changing state but never proceed       | Careful resource management        |

## Important Concepts

| Concept              | Explanation                                                                              |
| -------------------- | ---------------------------------------------------------------------------------------- |
| Mutex (`std::mutex`) | Locks to prevent race conditions                                                         |
| `std::lock_guard`    | Automatically acquires/releases a lock (RAII for mutex)                                  |
| Condition Variables  | Used to wait and notify threads (`std::condition_variable`)                              |
| Thread Pools         | Manage a collection of pre-created threads                                               |
| Atomic Variables     | Operations that are guaranteed to be thread-safe (`std::atomic`)                         |
| Futures & Promises   | Mechanisms for thread communication and result retrieval (`std::future`, `std::promise`) |

### Mutex Example

```cpp
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void print_message(string msg) {
    lock_guard<mutex> lock(mtx);
    cout << msg << endl;
}

int main() {
    thread t1(print_message, "Hello from Thread 1");
    thread t2(print_message, "Hello from Thread 2");

    t1.join();
    t2.join();

    return 0;
}
```

## Common Interview Questions

| Question                                | Answer                                                                                |
| :-------------------------------------- | :------------------------------------------------------------------------------------ |
| What is a race condition?               | When two threads access shared data simultaneously leading to unpredictable behavior. |
| What is deadlock?                       | Two or more threads waiting for each other indefinitely.                              |
| What is a mutex?                        | A mechanism to ensure only one thread accesses critical section at a time.            |
| Difference between join() and detach()? | `join()` waits for thread to finish, `detach()` runs thread independently.            |
| How to prevent race conditions?         | Use `std::mutex` or `std::atomic` types.                                              |
| Why use thread pools?                   | To reuse threads efficiently instead of creating/destroying them frequently.          |
| Can two threads access same function?   | Yes, but synchronization is needed if modifying shared data.                          |
| What is condition_variable?             | Used for thread communication (wait/notify patterns).                                 |

---

## Summary Mindmap:

```
Multithreading
 ├── Create Threads
 │    ├── std::thread
 │    └── Functions/Lambdas
 ├── Manage Threads
 │    ├── join()
 │    ├── detach()
 │    └── joinable()
 ├── Synchronization
 │    ├── Mutex
 │    ├── Lock_guard
 │    ├── Condition Variables
 │    └── Atomic
 ├── Problems
 │    ├── Race Condition
 │    ├── Deadlock
 │    ├── Starvation
 │    └── Livelock
 └── Communication
      ├── Futures
      └── Promises
```

## Real World Example

Suppose you are downloading a file and displaying a progress bar simultaneously:

- One thread handles download.
- Another thread updates progress bar.
- Both run independently and concurrently.
