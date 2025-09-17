/* -> 415

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.


Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"

*/

/*
Note:- observe the previous code with this code
*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string addStrings(string num1, string num2)
{
    string dummyResult;
    int i=num1.size()-1;
    int j=num2.size()-1;

    int carry = 0;
    while(i>=0 || j>=0)
    {
        int n1 = (i>=0 ? num1[i]-'0' : 0);
        int n2 = (j>=0 ? num2[j]-'0' : 0);

        int csum = n1+n2+carry;
        int digit = csum%10;
        carry = csum/10;

        dummyResult.push_back(digit+'0');

        i--,j--;
    }

    if(carry) dummyResult.push_back(carry+'0');

    reverse(dummyResult.begin(), dummyResult.end());

    return dummyResult;
}


int main()
{
    string s1 = "6";
    string s2 = "77";

    string ans = addStrings(s1,s2);

    cout << ans << endl;

    return 0;
}