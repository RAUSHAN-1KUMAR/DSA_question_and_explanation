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

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string addStrings(string num1, string num2)
{
    vector<int> dummyResult;
    int i=num1.size()-1;
    int j=num2.size()-1;


    int carry = 0;
    while (i>=0 && j>=0)
    {
        int digit = (num1[i]-'0') + (num2[j]-'0') + carry;
        dummyResult.push_back(digit%10);
        carry = digit/10;

        i--,j--;
    }


    //if length of num1 is greater
    while (i>=0)
    {
        int digit = (num1[i]-'0') + carry;
        dummyResult.push_back(digit%10);
        carry = digit/10;

        i--;
    }

    // if length of num2 is greater
    while (j>=0)
    {
        int digit = (num2[j]-'0') + carry;
        dummyResult.push_back(digit%10);
        carry = digit/10;

        j--;
    }

    // if carry left
    if(carry) dummyResult.push_back(carry);
    
    // forming ans string
    string ans = "";
    for(int i=dummyResult.size()-1 ; i>=0 ; i--)
    {
        ans.push_back(dummyResult[i]+'0');
    }

    return ans;
}


int main()
{
    string s1 = "456";
    string s2 = "77";

    string ans = addStrings(s1,s2);

    cout << ans << endl;

    return 0;
}