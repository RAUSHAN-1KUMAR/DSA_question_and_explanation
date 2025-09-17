/*

Input : *+AB-CD
Output : ((A+B)*(C-D))

Input : *-A/BC-/AKL
Output : ((A-(B/C))*((A/K)-L))

*/

/*
Steps:-
    - Steps are mostly same as postfixToInfix, the only change is we scan our infix from last and put the operator between first and second top.

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

string prefixToInfix(string& s)
{
    reverse(s.begin(), s.end()); //change1

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

            string result = "("+first+ch+second+")"; //change2

            ansSt.push(result);
        }
    }

    return ansSt.top();
}


int main()
{
    string s = "*-A/BC-/AKL";

    cout << prefixToInfix(s) << endl;

    return 0;
}

