/* -> 1903

You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.


Example 1:
Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.

Example 2:
Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".

Example 3:
Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
*/

/*
Approach:- one pointer(starts from end of the string)
*/

#include<iostream>
using namespace std;
    
string largestOddNumber(string num)
{
    int n = num.size();

    int i = n-1;
    while(i>=0)
    {
        if((num[i]-'0')&1) break;
        i--;
    }

    return num.substr(0, i+1);
}

int main()
{
    string num = "4206";

    cout << largestOddNumber(num) << endl;

    return 0;
}