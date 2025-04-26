# Structures, Unions, Enums, Typedef in C++

---

## 1. Structures (`struct`)

- Group different types of variables into a single unit.
- Members are **public by default**.

```cpp
#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    Person p1 = {"Piyush", 25};
    cout << p1.name << " " << p1.age << endl;
}
```

---

## 2. Pointer to Structure

```cpp
Person p2 = {"Shreyansh", 30};
Person* ptr = &p2;
cout << ptr->name << " " << ptr->age << endl;
```

---

## 3. Self-Referential Structure

```cpp
struct Node {
    int data;
    Node* next;  // Pointer to another Node
};
```

---

## 4. Union

```cpp
union Data {
    int i;
    float f;
};

int main() {
    Data d;
    d.i = 10;
    cout << d.i << endl;
    d.f = 5.5;     // Overwrites 'i'
    cout << d.f << endl;
}
```

---

## 5. Enumeration (`enum`)

```cpp
enum Color { RED, GREEN, BLUE };

int main() {
    Color c = GREEN;
    cout << c << endl;  // Output: 1
}
```

Assigning manual values:

```cpp
enum Days { Mon = 1, Tue, Wed, Thu };
```

---

## 6. `typedef` and `using`

```cpp
typedef unsigned int uint;
using uint2 = unsigned int;  // C++11 modern syntax

uint a = 5;
uint2 b = 10;
cout << a + b;
```

---

| Question                             | Answer                                              |
| :----------------------------------- | :-------------------------------------------------- |
| Difference between struct and class? | Struct → members public by default, Class → private |
| Can struct have functions?           | ✅ Yes, including constructors and destructors      |
| Union memory size?                   | Equal to size of largest member                     |
| Can struct inherit another struct?   | ✅ Yes, C++ allows it                               |
| enum vs #define for constants?       | enum gives type safety                              |
| Can pointer to struct point to NULL? | ✅ Yes, normal pointer behavior                     |
| Can we create array of structures?   | ✅ Yes                                              |

---

### Array of Structures

```cpp
Person people[2] = { {"Piyush", 25}, {"Sachin", 28} };
cout << people[1].name;
```

---

### Structure Inside Structure (Nested Structures)

```cpp
struct Date {
    int day, month, year;
};

struct Employee {
    string name;
    Date dob; // Nested structure
};

Employee e = {"Bhavani", {1, 1, 1995}};
cout << e.name << " born on " << e.dob.day << "/" << e.dob.month;
```

---

### Passing Structure to Function

```cpp
void printPerson(Person p) {
    cout << p.name << endl;
}

void updatePerson(Person& p) {
    p.age += 1;
}

int main() {
    Person p = {"Shubham", 24};
    printPerson(p);
    updatePerson(p);
    cout << p.age;  // 25
}
```

---

## Summary Table

| Feature           | struct                   | union       | enum            |
| :---------------- | :----------------------- | :---------- | :-------------- |
| Memory            | Separate for each member | Shared      | Not applicable  |
| Functions allowed | ✅                       | ❌          | ❌              |
| Inheritance       | ✅                       | ❌          | ❌              |
| Usage             | Group data               | Save memory | Named constants |

---
