# String in C++

In C++, strings can be represented in two ways:

1. Character Arrays (C-style strings)
2. std::string class (C++ STL string)

## Character Array VS `std::string`

| Feature          | Character Array (`char[]`)     | `std::string`                     |
| ---------------- | ------------------------------ | --------------------------------- |
| Null-Terminated  | ✅ Yes                         | ⚠️ Usually (`c_str()` ensures it) |
| Size Management  | ❌ Manual                      | ✅ Automatic                      |
| Function Support | ❌ Needs `<cstring>` functions | ✅ Has built-in member functions  |
| Safety           | ❌ Risky (buffer overflows)    | ✅ Safe and easy to use           |
| Dynamic Sizing   | ❌ Fixed                       | ✅ Grows dynamically              |

## Pointer to C-Style String

```c++
char* str = "Hello";  // Read-only string literal
```

## Pointer to `std::string`

```c++
string s = "Hello";
string* ptr = &s;
cout << ptr->length();  // 5
```

## Array of Strings:

```c++
string cars[] = {"BMW", "Audi", "Tesla"};
for (string car : cars)
    cout << car << endl;
```

**Or dynamically using vector:**

```c++
vector<string> names = {"Piyush", "Shubham", "Sachin"};
```

### More Ways to Create Array of Strings

1. **Using Array of Pointers**

   ```c++
   #include <iostream>
   using namespace std;
   int main() {
    // Initialize array of pointer
      const char* colour[4] = { "Blue", "Red", "Orange", "Yellow" };

      for (int i = 0; i < 4; i++)
        cout << colour[i] << "\n";
      return 0;
    }
   ```

2. **Using a 2D Array**

   ```c++
   #include <iostream>
   using namespace std;
   int main() {
    // Initialize 2D array
    char colour[4][10] = { "Blue", "Red", "Orange", "Yellow" };

    // Printing Strings stored in 2D array
    for (int i = 0; i < 4; i++)
        cout << colour[i] << "\n";
    return 0;
   }
   ```

## Tokenizing a string in C++

Tokenizing a string denotes splitting a string with respect to some delimiter(s). There are many ways to tokenize a string.

**`std::stringstream`**

```c++
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input = "GeeksForGeeks,is,a,must,try";

    std::stringstream ss(input);  // Load the input string into a stream
    std::string token;

    std::cout << "Tokens:" << std::endl;

    // Use getline with comma as delimiter
    while (std::getline(ss, token, ',')) {
        std::cout << token << std::endl;
    }

    return 0;
}
```

**How it works:**

- `std::getline(stream, variable, delimiter)` reads from the stream until it hits the specified delimiter — in this case, a comma.
- Each segment before a comma is stored in `token`.

## Substring in C++ `substr()`

The substring function takes two values pos and len as an argument and returns a newly constructed string object with its value initialized to a copy of a sub-string of this object.

`string substr (size_t pos, size_t len) const;`
