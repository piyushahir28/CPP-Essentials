# C++ Strings Cheatsheet

## 1. Types of Strings

| Type            | Description                       |
| --------------- | --------------------------------- |
| Character Array | C-style, null-terminated          |
| `std::string`   | C++ Standard Library string class |

---

## 2. Character Array vs `std::string`

| Feature          | Character Array | `std::string`   |
| ---------------- | --------------- | --------------- |
| Null-Terminated  | ✅ Yes          | ⚠️ Optional     |
| Size Handling    | ❌ Manual       | ✅ Automatic    |
| Safety           | ❌ Unsafe       | ✅ Safe         |
| Function Support | ❌ Limited      | ✅ Rich methods |
| Dynamic Resizing | ❌ No           | ✅ Yes          |

---

## 3. Common `std::string` Functions

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Piyush";
    s.length();         // 6
    s.substr(0, 3);     // "Piy"
    s.find("yu");       // 1
    s.replace(0, 2, "Hi");  // "Hiyush"
    s.append(" Dev");   // "Piyush Dev"
    s.erase(0, 2);      // "yush"
    s.compare("ABC");   // Lexicographical compare
    s.c_str();          // C-style string (const char*)
}
```

---

## 4. String with Pointers

```cpp
char* s1 = "Hello";          // C-string (read-only)
string s2 = "Hello";
string* ptr = &s2;
cout << ptr->length();       // Access using pointer
```

---

## 5. Tokenizing Strings

### `strtok()` (C-style)

```cpp
#include <cstring>
char str[] = "apple,banana";
char* token = strtok(str, ",");
while (token != NULL) {
    cout << token << endl;
    token = strtok(NULL, ",");
}
```

### `stringstream` (Modern C++)

```cpp
#include <sstream>
stringstream ss("apple banana");
string word;
while (ss >> word) {
    cout << word << endl;
}
```

---

## 6. Substrings

```cpp
string s = "PiyushDev";
cout << s.substr(0, 6);   // Output: "Piyush"
```

---

## 7. Iterating Strings

```cpp
for (char c : s) {
    cout << c;
}

for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it;
}
```

---

## 8. Raw String Literals

```cpp
string r = R"(path\to\folder\file.txt)";
```

---

## 9. `std::string_view` (C++17)

```cpp
#include <string_view>

std::string_view sv = "Hello, World";
cout << sv.substr(0, 5);  // Output: "Hello"
```

---

## 10. String Conversion

```cpp
int x = stoi("123");           // string → int
string s = to_string(456);     // int → string
```

---

## 11. Regex Matching

```cpp
#include <regex>

regex email(".+@.+\..+");
if (regex_match("piyush@example.com", email)) {
    cout << "Valid email";
}
```

---

## 12. Array of Strings

```cpp
string cars[] = {"BMW", "Audi", "Tesla"};
```

---

## 13. Interview Q&A

| Question                                    | Answer / Code                                |
| ------------------------------------------- | -------------------------------------------- |
| Difference: `char* str = "abc"` vs `char[]` | `char*` is read-only, `char[]` is modifiable |
| Reverse string                              | `reverse(s.begin(), s.end());`               |
| `std::string` in switch?                    | ❌ Not allowed                               |
| Convert to char\*                           | `s.c_str()`                                  |
| `substr()` complexity                       | `O(n)`                                       |

---

## ✅ Summary Table

| Topic               | Key Usage              |
| ------------------- | ---------------------- |
| `std::getline()`    | Input with spaces      |
| `to_string`, `stoi` | Conversions            |
| `string_view`       | Read-only, lightweight |
| `stringstream`      | Tokenization & parsing |
| `regex`             | Pattern matching       |
