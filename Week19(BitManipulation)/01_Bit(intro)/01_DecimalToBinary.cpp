

#include<bits/stdc++.h>
using namespace std;

// by using loop
string convertToBit(int n)
{
    string res = "";

    while(n!=0)
    {
        if(n%2==1) res+='1';
        else res+='0';

        n = n/2;
    }

    reverse(res.begin(), res.end());

    return res;
}

// or we can use bitset
string convertToBitBitset(int n)
{
    bitset<32> bit(n);

    string ans = bit.to_string();
    ans = ans.substr(ans.find('1'));

    return ans;
}

int main()
{
    int num = 11;
    cout << convertToBitBitset(num) << endl;
    return 0;
}
