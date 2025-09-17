/* GFG
check redundant/unwanted bracket present h ya nhi:-

Example:-
    Input: (a+b)
    Output: false
    
    Input: (a+(b))
    Output: true

    Input: (a+b*c)
    Output: false

    Input: ((a)+(b*c))
    Output: true

    Input: ((a+b))
    Output: true
*/

/*
Apprach:-
    -- ager do bracket ke bich m at least ek operator h it means redundant nhi h.
*/

#include<iostream>
#include<stack>
using namespace std;

bool checkRedundant(string &str)
{
    stack<char> st;

    for(int i=0 ; i<str.size() ; i++)
    {
        char ch =str[i];

        // push kerne wala case:- jab opening bracket ya koi operator h
        if(ch=='(' || ch=='*' || ch=='+' || ch=='-' || ch=='/')
        {
            st.push(ch);
        }
        else if(ch==')')// redundant check kerne wala case:- jab closing bracket mile
        {
            int operatorCount = 0;

            // check kro kya koi operator h stack p
            while (!st.empty() && st.top() != '(')
            {
                operatorCount++;
                st.pop();
            }

            // jab stack ke top pe '(', opening bracket hoga.
            st.pop();// kyunki iss '(' opening bracket ke liye check ker liye h

            // ager koi operator nhi mila matlab redundant present h
            if(operatorCount==0) return true;
            
        }
    }

    return false;
}


int main()
{
    string str = "((a+b)*(c+(d)))";

    bool ans = checkRedundant(str);

    if(ans == true){
        cout << "Redundant Brackets Present" << endl;
    }
    else{
        cout << "Redundant Brackets Not Present" << endl;
    }

    return 0;
}




