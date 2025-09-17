/*
Factorial of a large number.
    -- because if we store the answer in a integer it will get overflow because range of int is only till 2^31.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> factorial(int N)
{
    vector<int> ans;// to store the answer
    ans.push_back(1);

    int carry = 0;

    //i represents the consecutive multiplied digits
    for(int i = 2 ; i<=N ; i++)
    {
        //j represents the element present in ans.
        for(int j = 0 ; j<ans.size() ; j++)
        {
            int x = ans[j] * i + carry;
            ans[j] = x%10;
            carry = x/10;
        }

        //if carry is left and it is large value
        while(carry)
        {
            ans.push_back(carry%10);
            carry /= 10;
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> answer = factorial(n);

    for(int i = 0 ; i<answer.size(); i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}