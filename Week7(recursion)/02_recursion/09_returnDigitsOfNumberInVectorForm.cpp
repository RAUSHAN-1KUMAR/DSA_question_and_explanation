
/*
Question:- we are given a number. we have to return its digits in vector form
*/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> findIndex(int num)
{
    vector<int> ans;

    // base case
    if(num==0)
    {
        return ans;
    }  

    // head recursion
    vector<int> nextAnswer = findIndex(num/10);

    // solving that one case
    for(int num:nextAnswer) ans.push_back(num);
    ans.push_back(num%10);

    return ans;
}

int main()
{
    int number = 4215;

    vector<int> indexes = findIndex(number);

    for(auto ele:indexes)
    {
        cout << ele << " ";
    }

    return 0;
}