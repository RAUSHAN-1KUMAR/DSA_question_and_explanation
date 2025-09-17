// Add two numbers represented by two array.

/*
Hint:-
    -- to convert digit into characterDigit:     digit + '0'
    -- to convert characterDigit into digit:     digitChar - '0'
    -- to convert digit into string:             to_string(digit)
    -- to convert string into digit:             stoi(digitString)

Note:- works only in case of single digit.
*/

#include<bits/stdc++.h>
using namespace std;

string calc_Sum(int *a, int n, int *b, int m)
{
    int carry = 0;
    string ans;
    int i = n-1;// for array a
    int j = m-1;// for array b

    while(i>=0 && j>=0)
    {
        int x = a[i] + b[j] + carry;
        int digit = x%10;
        carry = x/10;
        ans.push_back(digit + '0');// digit to character conversion
        i--;
        j--;
    }

    // if elements left in array a
    while(i>=0)
    {
        int x = a[i] + carry;
        int digit = x%10;
        carry = x/10;
        ans.push_back(digit + '0');// digit to character conversion   
        i--;    
    }

    // if elements left in array b
    while(j>=0)
    {
        int x = b[i] + carry;
        int digit = x%10;
        carry = x/10;
        ans.push_back(digit + '0');// digit to character conversion     
        j--;  
    }

    // if at last carry is non-zero
    if(carry) ans.push_back(carry + '0');

    // poping the zero character from last because when we reverse the ans, the zero character will come at the begining of the string.
    while(ans[ans.size()-1]=='0')
    {
        ans.pop_back();
    }

    // reversing the elements 
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int A[]={9,5,4,9};
    int B[]={2,1,4};

    int n = sizeof(A)/sizeof(int);
    int m = sizeof(B)/sizeof(int);

    string sum = calc_Sum(A,n,B,m);

    cout << sum;

    return 0;
}
