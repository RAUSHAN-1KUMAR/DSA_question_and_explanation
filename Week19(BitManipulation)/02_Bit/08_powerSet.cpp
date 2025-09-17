/*
print all subsetsSum of a given array

Actually we can solve this question by using recursion but now we will solve it by using BIT MASK technique
*/

#include<bits/stdc++.h>
using namespace std;

// this technique is useful in place of recursion when you want to get the subsequence of an array of string
vector<int> allSubsetsSum(vector<int> &nums)
{
    int n=nums.size();
    vector<int> ans;

    //1<<n = 2^n
    for(int i=0 ; i<(1<<n) ; i++) // each i represents a bit mask
    {
        int sum=0;
        for(int pos=0; pos<n ; pos++)
        {
            if(i&(1<<pos)){
                sum+=nums[pos];
            }
        }
        ans.push_back(sum);
    }

    return ans;
}


int main()
{
    vector<int> nums = {1,2,3};

    vector<int> ans = allSubsetsSum(nums);

    for(auto num:ans){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

