/*

Input : abc++
Output : (a + (b + c))

Input  : ab*c+
Output : ((a*b)+c)

*/

/*
Steps:- while reading the input infix
    1. if char is (a, A, or digits) push it into answer stack

    2. OtherWise, if symbol is an operator
        i) Pop the top 2 values from the stack. 
        ii) Put the operator between second top and first top, and form a string. 
        iii) Push the resulted string back to stack.

    3. if there is only one value in the stack -> That value in the stack is the desired infix string.

TC:- O(n) + O(n1 + n2) -> O(n)
*/


#include<bits/stdc++.h>
using namespace std;

string postFixToInfix(string& s)
{
    stack<string> ansSt;

    for(auto &ch:s)
    {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            ansSt.push(string(1, ch));
        }
        else
        {
            string first = ansSt.top(); ansSt.pop();
            string second = ansSt.top(); ansSt.pop();

            string result = "("+second+ch+first+")"; //-> O(n1 + n2) addition take time

            ansSt.push(result);
        }
    }

    return ansSt.top();
}


int main()
{
    string s = "AB-DE+F*/";

    cout << postFixToInfix(s) << endl;

    return 0;
}

