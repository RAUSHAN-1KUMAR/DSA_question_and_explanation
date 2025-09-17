/*
Input : AB+CD-*
Output : *+AB-CD
Explanation : Postfix to Infix : (A+B) * (C-D)
              Infix to Prefix :  *+AB-CD

Input : ABC/-AK/L-*
Output : *-A/BC-/AKL
Explanation : Postfix to Infix : ((A-(B/C))*((A/K)-L))
              Infix to Prefix :  *-A/BC-/AKL 

There is also a direct way -> read the below steps
*/

/*
Steps:- while reading the input infix
    1. if char is (a, A, or digits) push it into answer stack

    2. OtherWise, if symbol is an operator
        i) Pop the top 2 values from the stack. 
        ii) Put the operator before second top and first top, and form a string -> operator second_top first_top
        iii) Push the resulted string back to stack.

    3. if there is only one value in the stack -> That value in the stack is the desired infix string.

TC:- O(n)
*/

#include<bits/stdc++.h>
using namespace std;

string postFixToPrefix(string& s)
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

            string result = ch+second+first; // operator second_top first_top

            ansSt.push(result);
        }
    }

    return ansSt.top();
}


int main()
{
    string s = "ABC/-AK/L-*";

    cout << postFixToPrefix(s) << endl;

    return 0;
}

