# Dynamic Memory Allocation (DMA) in C++

## 1. What is DMA?

- **Dynamic Memory Allocation** means allocating memory **at runtime** using pointers.
- Useful when we don't know the size of memory needed during compile time.

## 2. `new` and `delete` in C++

- **`new`** → Allocates memory dynamically.
- **`delete`** → Deallocates memory (frees it).

```cpp
int* ptr = new int;         // Allocate single int
*ptr = 5;                   // Assign value
delete ptr;                 // Free memory

int* arr = new int[5];       // Allocate array of 5 ints
delete[] arr;                // Free array memory
```

## 3. Difference Between `new/delete` and `malloc()/free()`

| Feature                     | new/delete              | malloc/free                           |
| :-------------------------- | :---------------------- | :------------------------------------ |
| Language                    | C++                     | C                                     |
| Type safety                 | ✅ Yes                  | ❌ No (returns `void*`)               |
| Constructor/Destructor call | ✅ Yes                  | ❌ No                                 |
| Exception on failure        | Throws `std::bad_alloc` | Returns `NULL`                        |
| Syntax                      | `int* p = new int;`     | `int* p = (int*)malloc(sizeof(int));` |

## 4. Using DMA for Arrays

```cpp
// Dynamic array allocation
int* arr = new int[5];
for (int i = 0; i < 5; i++) {
    arr[i] = i * 10;
}
for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
}
delete[] arr;  // Deallocate
```

- Use `delete[]` for arrays
- Use `delete` for single variables

## 5. Memory Leaks

- **Memory leak** happens when we **forget to free** the dynamically allocated memory.
- **Problem:** Application uses more memory and slows down.

```cpp
void func() {
    int* p = new int(10);
    // forgot to delete -> memory leak
}
```

## 6. How to Avoid Memory Leaks

- Always match `new` with `delete`, and `new[]` with `delete[]`.
- Prefer using **smart pointers** like `std::unique_ptr`, `std::shared_ptr`.

```cpp
#include <memory>

std::unique_ptr<int> p(new int(5));  // Auto free when out of scope
```

## 7. Static vs Dynamic Memory Allocation

| Feature     | Static Memory            | Dynamic Memory         |
| :---------- | :----------------------- | :--------------------- |
| Memory size | Fixed at compile time    | Allocated at runtime   |
| Lifetime    | Entire program execution | Until explicitly freed |
| Speed       | Faster                   | Slower                 |
| Control     | Limited                  | Full control           |

## Interview Questions on DMA

| Question                              | Answer                                           |
| :------------------------------------ | :----------------------------------------------- |
| What is dynamic memory allocation?    | Allocating memory at runtime                     |
| Difference between malloc and new?    | `new` is type-safe and calls constructors        |
| How to prevent memory leaks?          | Always `delete` memory and prefer smart pointers |
| How to allocate array dynamically?    | `int* arr = new int[size];`                      |
| What happens if you forget to delete? | Causes memory leak                               |
| Can delete be used without new?       | ❌ Undefined Behavior                            |

---

### Dynamic 2D Array

```cpp
int** arr = new int*[3]; // 3 rows
for (int i = 0; i < 3; i++) {
    arr[i] = new int[4]; // 4 columns
}

// Assign and print
arr[0][0] = 10;

// Free memory
for (int i = 0; i < 3; i++) {
    delete[] arr[i];
}
delete[] arr;
```

### Summary

- `new` allocates memory, `delete` frees it.
- Always free dynamic memory to prevent leaks.
- Prefer `std::unique_ptr`/`std::shared_ptr` for safety.
