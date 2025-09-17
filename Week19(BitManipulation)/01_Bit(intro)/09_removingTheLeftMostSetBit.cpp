/*
remove the left most set bit
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=15;
    int m=15;

    // Method1
        cout << "Original: " << bitset<8>(n) << " (" << n << ") " << endl;

        // find pos of msb set bit
        int msb_pos = 31 - __builtin_clz(n);
        
        n = (n & ~(1<<msb_pos));

        cout << "After removing MSB: " << bitset<8>(n) << " (" << n << ")" << endl;
        
    cout << endl;

    // Method2
        cout << "Original: " << bitset<8>(m) << " (" << m << ") " << endl;

        int highestPower = (int)log2(m);

        m = (m & ~(1<<highestPower));

        cout << "After removing MSB: " << bitset<8>(m) << " (" << m << ")" << endl;



    return 0;
}