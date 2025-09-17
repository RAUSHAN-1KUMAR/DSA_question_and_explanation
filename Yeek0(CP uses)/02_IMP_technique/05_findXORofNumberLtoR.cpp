/* GFG

You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

Example:
    Input: L = 4, R = 8 
    Output: 8 
    Explanation: 4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
*/

/*
Approach:- Observation based
    -- take XOR form 1^2^3^4^5^6^7^8^9 and then observe a pattern
        i) n%4==1: ans will be 1
        ii) n%4==2: ans will be n+1
        iii) n%4==3: ans will be 0
        iv) n%4==0: ans will be n
*/

#include<bits/stdc++.h>
using namespace std;

int XorFrom1toN(int n){
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
    if(n%4==0) return n;
}

int findXor(int l, int r){
    return (XorFrom1toN(l-1)^XorFrom1toN(r));
}


int main()
{
    int l = 4;
    int r = 8;
    cout << findXor(l, r) << endl;
    return 0;
}





