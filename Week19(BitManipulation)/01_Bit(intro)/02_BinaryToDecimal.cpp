

#include<bits/stdc++.h>
using namespace std;

// by using loop
int binaryToDecimal(string n)
{
    int power2 = 1;
    int len = n.length();
    int num = 0;
    
    for(int i=len-1 ; i>=0 ; i--)
    {
        if(n[i]=='1') num = num + power2;

        power2 = power2*2;
    }

    return num;
}

// using bitset
int binaryToDecimalBitset(string n)
{
    bitset<32> bit(n);

    return bit.to_ulong();
}

// using stoi
int binaryToDecimalStoi(string n)
{
    int ans = stoi(n, nullptr, 2); // base 2: this will consider the given string 'n' as base 2 and will convert it into base 10 i.e., integer

    return ans;
}


int main()
{
    string num = "1101";
    cout << binaryToDecimalStoi(num) << endl;
    return 0;
}
