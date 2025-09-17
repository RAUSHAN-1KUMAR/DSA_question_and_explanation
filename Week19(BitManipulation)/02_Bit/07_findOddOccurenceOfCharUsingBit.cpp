/*
Given a string find the no. of characters having odd freq
EX:- aaattvezez = 2(a and v)
*/

/*
Approach:- using XOR operator
    -- if even at the end XOR will give 0
    -- if odd at the end XOR will give 1
*/

#include<bits/stdc++.h>
using namespace std;

int charWithOddOccu(string s){
    int bitMask=0;
    for(char ch:s){
        int bitPos = ch-'a';
        bitMask = bitMask^(1<<bitPos);
    }

    // now lets count the odd occurence
    int ans = 0;
    while (bitMask){
        ans++;
        bitMask = bitMask&(bitMask-1);
    }

    //int ans = __builtin_popcount(bitMask); we can also use builin function to count set bits in O(1) time
    
    return ans;
}

int main()
{
    string s ="aaattvezccce";
    cout << charWithOddOccu(s) << endl;
    return 0;
}