/* 921

A parentheses string is valid if and only if:
    - It is the empty string,
    - It can be written as AB (A concatenated with B), where A and B are valid strings, or
    - It can be written as (A), where A is a valid string.
    - You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

 
Example 1:
Input: s = "())"
Output: 1

Example 2:
Input: s = "((("
Output: 3
*/

/*
Appraoch:- applied the logic on counting
*/

#include<iostream>
#include<vector>
using namespace std;


int minAddToMakeValid(string s)
{
    int rightPar = 0;

    int count=0;

    for(auto ch:s)
    {
        if(ch=='('){
            count++;
        }
        else{
            count--;
            while(count<0){
                rightPar--;
                count++;
            }
        }
    }

    return count + abs(rightPar);
}


int main()
{
    string s = ")))((())()))";

    cout << minAddToMakeValid(s) << endl;

    return 0;
}