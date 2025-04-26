# Array in C++

An array is a collection of elements of the same type, stored in contiguous memory locations.

**Ways to initialize array in c++:**

- **Basic Initialization**

  `int arr[3] = {10, 20, 30};`

- **Partial Initialization**

  `int arr[5] = {1, 2};  // Remaining set to 0`

- **Zero Initialization**

  `int arr[5] = {};  // All set to 0`

- **Without Size (Compiler deduces)**

  `int arr[] = {5, 10, 15};  // Size is 3`

**How to Find Size of an Array**

```c++
int arr[] = {1, 2, 3, 4, 5};

int totalSize = sizeof(arr);           // total bytes
int elementSize = sizeof(arr[0]);      // size of one element
int length = totalSize / elementSize;  // number of elements

cout << "Length: " << length << endl;  // Output: 5
```

_This only works inside the same function where the array is declared._

## How to pass Array to Function

1. **Using Pointer**

   ```c++
   void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
   }
   ```

2. **Using Array Notation (same as pointer)**

   ```c++
   void printArray(int arr[], int size) { /* same as above */ }
   ```

3. **Using Reference to Array (best for fixed size)**

   ```c++
   void printArray(const int (&arr)[5]) {
    for (int i : arr) cout << i << " ";
   }
   ```

## Array Decay

When you pass an array to a function, it decays into a pointer — meaning it loses its size information.

```c++
void func(int arr[]) {
    cout << sizeof(arr);  // Output: size of pointer (usually 8 on 64-bit)
}
```

❗ That's why sizeof(arr) doesn't work as expected inside the function.

## Array Pointer vs Pointer to Array?

- **Array Pointer (`int* ptr`)**

  ```c++
  int arr[5];
  int* ptr = arr;  // Pointer to first element
  ```

- **Pointer to an Array (`int (*ptr)[5]`)**

  ```c++
  int arr[5];
  int (*ptr)[5] = &arr;  // Points to the whole array

  cout << (*ptr)[2]; // Access 3rd element
  ```

| Term            | Meaning                        |
| --------------- | ------------------------------ |
| `int*`          | Pointer to an int              |
| `int* arr`      | Array decays to pointer to int |
| `int (&arr)[5]` | Reference to array of 5 ints   |
| `int (*ptr)[5]` | Pointer to an array of 5 ints  |
