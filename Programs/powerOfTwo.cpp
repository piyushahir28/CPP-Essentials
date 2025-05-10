#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0)
        return false;
    
    while (n > 1) {
        if (n % 2 != 0)  // If n is not divisible by 2, it's not a power of 2
            return false;
        n /= 2;          // Keep dividing by 2
    }
    
    return true; // If we reach 1, it was a power of 2
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    if (isPowerOfTwo(num))
        cout << num << " is a power of 2." << endl;
    else
        cout << num << " is NOT a power of 2." << endl;

    return 0;
}
