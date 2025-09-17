// Add two numbers represented by two array.

/*
Hint:-
    -- to convert digit into characterDigit:     digit + '0'
    -- to convert characterDigit into digit:     digitChar - '0'
    -- to convert digit into string:             to_string(digit)
    -- to convert string into digit:             stoi(digitString)

Note:- works only in case of single digit.
*/

// better approach than previous one

#include<bits/stdc++.h>
using namespace std;

string calc_Sum(int *a, int n, int *b, int m)
{
    string ans = "";
    int ai = n-1;
    int bi  = m-1;
    int carry = 0;

    while(ai>=0 || bi>=0)
    {
        int na = ai>=0 ? a[ai] : 0 ;
        int nb = bi>=0 ? b[bi] : 0 ;

        int digit = na + nb + carry;
        int num = digit%10;
        carry = digit/10;

        ans.push_back(num + '0');

        ai--;
        bi--;
    }

    // if carry left
    if(carry) ans.push_back(carry + '0');

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int A[]={9,5,4,9};
    int B[]={9,1,4};

    int n = sizeof(A)/sizeof(int);
    int m = sizeof(B)/sizeof(int);

    string sum = calc_Sum(A,n,B,m);

    cout << sum << endl;

    return 0;
}
