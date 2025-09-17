
// builtin is used mostly, not bitset
// __builtin_ Functions for Bitwise Operations

#include <iostream>
using namespace std;

int main() 
{
    unsigned int x = 42; // Binary: 00000000 00000000 00000000 00101010
    unsigned long long y = 1234;

    // 1. __builtin_popcount(x): Count number of 1s in binary representation
    cout << "popcount (42): " << __builtin_popcount(x) << endl; // Output: 3
    cout << "popcountll (y): " << __builtin_popcountll(y) << endl;

    // 2. __builtin_clz(x): Count leading zeros (number of 0s before the first 1 from the left)
    cout << "clz (42): " << __builtin_clz(x) << endl; // Output: 26 (32 - 6)
    cout << "clzll (y): " << __builtin_clzll(y) << endl;

    // 3. __builtin_ctz(x): Count trailing zeros (number of 0s after the last 1 from the right)
    cout << "ctz (42): " << __builtin_ctz(x) << endl; // Output: 1 (ends with 10)
    cout << "ctzll (y): " << __builtin_ctzll(y) << endl;

    // 4. __builtin_parity(x): 1 if number of 1s is odd, 0 if even
    cout << "parity (42): " << __builtin_parity(x) << endl; // Output: 1 (3 ones → odd)
    cout << "parityll (y): " << __builtin_parityll(y) << endl;

    return 0;
}
