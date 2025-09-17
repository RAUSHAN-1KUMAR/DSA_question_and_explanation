/*
We have to generate all possible valid parentheses combination w.r.t to a given number

Example:-
    1. input: 2
       output: ()(), (())
    
    2. input: 3
       output: ((())), (())(), ()(()), (()()), ()()()
*/

/*
Below code is rohit negi's code:-
    -- he looked for left(no. of opening bracket) and right(no. of closing bracket) parantheses, i.e., at last the count of left parantheses and right parantheses will be equal and to obtain the correct order parathesis he used the logic that [no. of opening brackets >= no. of closing bracket] at the time of building.
*/

#include<iostream>
#include<vector>
using namespace std;

void parenth(int n, int left, int right, vector<string> &ans, string &temp)
{
    // base case
    if(left+right == 2*n){
        ans.push_back(temp);
        return;
    }

    // left parenth
    if(left<n){
        temp.push_back('(');
        parenth(n, left+1, right, ans, temp);
        temp.pop_back();
    }

    // right parenth
    if(right<left){
        temp.push_back(')');
        parenth(n, left, right+1, ans, temp);
        temp.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string temp = "";

    parenth(n,0,0,ans,temp);

    return ans;
}

int main()
{
    int n=3;

    vector<string> ans = generateParenthesis(n);

    for(auto eachS:ans){
        cout << eachS << endl;
    }

    return 0;
}