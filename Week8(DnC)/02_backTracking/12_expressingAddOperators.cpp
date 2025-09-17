/* 282

Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.

Note that a number can contain multiple digits.



Example 1:
    Input: num = "123", target = 6
    Output: ["1*2*3","1+2+3"]
    Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

Example 2:
    Input: num = "232", target = 8
    Output: ["2*3+2","2+3*2"]
    Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.\

Example 3:
    Input: num = "3456237490", target = 9191
    Output: []
    Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
*/

/*
Approach: recursively solved
    -- the only deal is to handle mul(*) as per the BODMAS rule, for that we are also gonna pass the prevVal that we added to our currSum
*/

#include <bits/stdc++.h>
using namespace std;

void helper(vector<string> &ans, string child, string &num, int pos, long long currSum, int &target, long long preValue)
{
    if(pos>=num.size()){
        if(currSum==target){
            ans.push_back(child);
        }
        return;
    }


    for(int i = pos; i<num.size() ; i++)
    {
        string str = num.substr(pos, i-pos+1);
        
        if(str.size()>1 && str[0] == '0')
            break;

        long long currVal = stoll(str);

        // lets add it
        helper(ans, child+'+'+str, num, i+1, currSum+currVal, target, currVal);

        // lets sub it
        helper(ans, child+'-'+str, num, i+1, currSum-currVal, target, -currVal);

        // lets mul it: using preValue to maintain the BODMAS rule
        helper(ans, child+'*'+str, num, i+1, currSum-preValue+currVal*preValue, target, currVal*preValue);
    }
}

vector<string> addOperators(string num, int target)
{
    int n=num.size();

    vector<string> ans;
    string child = "";

    for(int i=0 ; i<n ; i++)
    {
        string str = num.substr(0, i+1);

        if(str.size()>1 && str[0] == '0') // skip leading zeroes
            break;

        long long firstNum = stoll(str);

        helper(ans, child+str, num, i+1, firstNum, target, firstNum); // ans, child, num, pos, currSum, target, preValue 
    }

    return ans;
}

int main()
{
    string num = "0200031";
    int target = 6;

    for(string s:addOperators(num, target)){
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
