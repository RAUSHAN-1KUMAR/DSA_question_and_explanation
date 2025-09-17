/* GFG

Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa

Example:
    Input:  S = "}{{}}{{{"
    Output: 3
    Explanation: One way to balance is: "{{{}}{}}". There is no balanced sequence that can be formed in lesser reversals.
*/

/*
Appraoch:-
    -- catch condition-> ager length of the string odd h to usko valid banana impossible h,
    -- given string m jo valid pairs h uski koi need nhi, to stack m push kerte waqt valid pairs ko hata te jayengen,
    -- stack m fill kerne ke baad, piche se do do character nikalengen and then:
        (i) if dono char same h means bas ek reversal hoga-> ans+=1
        (ii) if dono char same nhi h means dono ko reverse kerna padega-> ans+=2
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int countRev(string s)
{
    // if odd size string then impossible to make pairs
    if(s.size()&1) return -1; // catch

    int ans=0;
    stack<char> st;

    // first lets remove the already good pairs
    for(char ch:s)
    {
        if(ch=='{') st.push(ch);
        else{
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    // if stack is still not empty,
    // lets count reversal
    while(!st.empty()){
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();

        if(a==b) ans+=1;
        else ans += 2;
    }

    return ans;
}


int main()
{
    string s = "}{{}}{{{";

    int ans = countRev(s);

    cout << ans << endl;

    return 0;
}