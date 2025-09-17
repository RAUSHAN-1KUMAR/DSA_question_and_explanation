
// using bitset: bitset<N> b; N-> no. of bits we want to store
// remember the 'N' is required in compile time

#include<iostream>
#include<bitset>
using namespace std;


int main()
{
    // initialization
        bitset<40> bit1(42); // from integer
        cout << bit1 << endl;
        cout << bit1[1] << endl; 

        bitset<10> bit2("100010"); // from string (must be a valid binary string)
        cout << bit2 << endl;
        cout << bit2[3] << endl;

        // how can we remove leading zeroes: using to_string() and substr() function
        string s = bit1.to_string();
        string forbit1 = s.substr(s.find('1'));
        cout << forbit1 << endl;

    // member functions for bitset
    cout << endl;
    cout << "Size of bit1: " << bit1.size() << endl;         // Total bits
    cout << "Count of 1s in bit1: " << bit1.count() << endl; // Number of set bits
    cout << "Any set in bit1? " << bit1.any() << endl;       // true if any bit is 1
    cout << "All set in bit1? " << bit1.all() << endl;       // true if all bits are 1
    cout << "None set in bit1? " << bit1.none() << endl;     // true if all bits are 0
    cout << endl;


    // Conversion from bit to unsigned int
    cout << "bit1 as unsigned long: " << bit1.to_ulong() << endl;
    cout << "bit1 as unsigned long long: " << bit1.to_ullong() << endl;
    cout << endl;


    // Bit modification
    bit1.set(4);    // Set bit at index 4
    cout << "After set(4): " << bit1 << endl;

    bit1.reset(1);  // Reset bit at index 1
    cout << "After reset(1): " << bit1 << endl;

    bit1.flip(3);   // Flip bit at index 3
    cout << "After flip(3): " << bit1 << endl;
    
    bit1.flip();    // It we don't provide index, it will Flip all bits
    cout << "After flip(): " << bit1 << endl;

    bit1.set();     // If we don't provide index, it will Set all bits to 1
    cout << "After set(): " << bit1 << endl;

    bit1.reset();   // If we don't provide index, it will Reset all bits to 0
    cout << "After reset(): " << bit1 << endl;

    return 0;
}
