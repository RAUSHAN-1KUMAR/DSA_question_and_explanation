/* -> 1614

Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.
 

Example 1:
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation:
Digit 8 is inside of 3 nested parentheses in the string.

Example 2:
Input: s = "(1)+((2))+(((3)))"
Output: 3
Explanation:
Digit 3 is inside of 3 nested parentheses in the string.

Example 3:
Input: s = "()(())((()()))"
Output: 3
*/

/*
Appraoch:-
    -- we will count the left parenthesis, and the answer will be the highest times the left parenthesis stays.
*/

#include<iostream>
#include<vector>
using namespace std;

int maxDepth(string s)
{
    int LPC = 0;
    int LPCMax = 0;
    for(auto eachChar:s)
    {
        if(eachChar == '('){
            LPC += 1;
        }
        else if(eachChar == ')'){
            LPC -= 1;
        }

        LPCMax = max(LPC, LPCMax);
    }

    return LPCMax;
}


int main()
{
    string s1 = "(1+(2*3)+((8)/4))+1";
    string s2 = "(1)+((2))+(((3)))";
    string s3 = "()(())((()()))";

    cout << maxDepth(s1) << endl;
    cout << maxDepth(s2) << endl;
    cout << maxDepth(s3) << endl;

    return 0;
}