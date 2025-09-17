/*
Input : *+AB-CD
Output : AB+CD-*
Explanation : Prefix to Infix :  (A+B) * (C-D)
              Infix to Postfix :  AB+CD-*

Input : *-A/BC-/AKL
Output : ABC/-AK/L-*
Explanation : Prefix to Infix :  (A-(B/C))*((A/K)-L)
              Infix to Postfix : ABC/-AK/L-* 

There is also a direct way -> read the below steps
*/

/*
Steps:-  
    - Steps are mostly same as postfixToPrefix, the only change is we scan our prefix from last and put the operator at last first and second top.

    1. if char is (a, A, or digits) push it into answer stack

    2. OtherWise, if symbol is an operator
        i) Pop the top 2 values from the stack. 
        ii) Put the operator at last first top and second top, and form a string -> first_top second_top operator
        iii) Push the resulted string back to stack.

    3. if there is only one value in the stack -> That value in the stack is the desired infix string.

TC:- O(n)
*/

#include<bits/stdc++.h>
using namespace std;

string prefixToPostfix(string& s)
{
    reverse(s.begin(), s.end());

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

            string result = first+second+ch;// first_top second_top operator

            ansSt.push(result);
        }
    }

    return ansSt.top();
}


int main()
{
    string s = "*-A/BC-/AKL";

    cout << prefixToPostfix(s) << endl;

    return 0;
}

