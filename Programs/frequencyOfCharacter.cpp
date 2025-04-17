#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int count[256] = {0};  // ASCII character count (covers all characters)

    for (char ch : input) {
        if (ch != ' ') {   // Skip spaces
            count[(unsigned char)ch]++;
        }
    }

    cout << "\nCharacter Frequency:\n";
    for (int i = 0; i < 256; ++i) {
        if (count[i] > 0) {
            cout << (char)i << ": " << count[i] << "\n";
        }
    }

    return 0;
}
