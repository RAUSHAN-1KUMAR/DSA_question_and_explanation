/* -> 2116

A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
    1. It is ().

    2. It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.

    3. It can be written as (A), where A is a valid parentheses string.

You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,
    1. If locked[i] is '1', you cannot change s[i].

    2. But if locked[i] is '0', you can change s[i] to either '(' or ')'.

Return true if you can make s a valid parentheses string. Otherwise, return false.


Example 1:
    Input: s = "))()))", locked = "010100"
    Output: true
    Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
    We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.


Example 2:
    Input: s = "()()", locked = "0000"
    Output: true
    Explanation: We do not need to make any changes because s is already valid.


Example 3:
    Input: s = ")", locked = "0"
    Output: false
    Explanation: locked permits us to change s[0]. 
    Changing s[0] to either '(' or ')' will not make s valid.
*/

/*
Approach:-
    -- the only thing which is disturbing is the unlocked bracket, because it can be close(')') or can be open('(')
    -- so we are gonna have two stack, one will be for normal play as we do if there is no unlocking system and if we encounter an unlocked(0) bracket then we will store it in another stack, it means normal stack will be played on locked(1) ones and if we encounter an closing bracket then we will use normal stack to check it is valid or not and if normal stack is empty then we will use another stack to check valid
    -- we are gonna store the index in stack
    -- at last if stack is not empty then we also have to play again at last

It can also be solved without using stack i.e., O(1) space
*/

#include<bits/stdc++.h>
using namespace std;

bool canBeValid(string s, string locked)
{
    int n = s.length();

    if(n%2 != 0) {
        return false;
    }

    stack<int> open;//normal play
    stack<int> openClose;// to store unlocked bracket

    for(int i = 0; i < n; i++) 
    {
        if(locked[i] == '0'){
            openClose.push(i);
        } else if(s[i] == '('){
            open.push(i);
        } else if(s[i] == ')'){
            if(!open.empty()){
                open.pop();
            } else if(!openClose.empty()) {
                openClose.pop();
            } else {
                return false;
            }
        }
    }

    // if still we have open bracket at normal stack(open?? yes only open will be left inside normal stack)
    while(!open.empty() && !openClose.empty() && open.top() < openClose.top()) {
        open.pop();
        openClose.pop();
    }

    return open.empty(); //true
}

int main()
{
    string s="))()))";
    string locked="010100";
    cout << canBeValid(s, locked) << endl;
    return 0;
}

