/* -> 22

We have to generate all possible valid parentheses combination w.r.t to a given number

Example:-
    1. input: 2
       output: ()(), (())
    
    2. input: 3
       output: ((())), (())(), ()(()), (()()), ()()()
*/

/*
Below code is my code:- 
    -- and the approch i applied is that i looked for a count, if one bracket is opened and it is closed later then for that particular braket the count will be nalify, and at last if the count is equal to zero and output string has the length of desired length then print and return.
*/

#include<iostream>
#include<vector>
using namespace std;


void solve(int num, int count, string &output, vector<string> &ans)
{
    // base case
    if(count<0 && output.back()==')') return;

    if(output.size()==num*2 && count==0){
        ans.push_back(output);
        return;
    }
    else if(output.size()==num*2){
        return;
    }


    // solve one case
    output.push_back('(');
    solve(num, count+1, output, ans);

    output.pop_back();
    output.push_back(')');
    solve(num,count-1, output, ans);

    output.pop_back();// because ouput is passed as reference variable
}


vector<string> generateParenthesis(int n) 
{
    vector<string> ans;

    string output = "(";

    solve(n, 1, output, ans);

    return ans;
}


int main()
{
    int n=2;

    vector<string> ans = generateParenthesis(n);

    for(auto eachS:ans){
        cout << eachS << endl;
    }

    return 0;
}