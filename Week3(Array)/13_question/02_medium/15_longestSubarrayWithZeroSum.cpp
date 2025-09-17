/*
we need to find the longest subarrat with zero sum

example:-
    input:- 1,-1,3,2,-2,-8,1,7,10,23
    output:- 5
    explanation:- the subarray 2,-2,-8,1,7
*/

/*
Approach:- prefix sum technique
    -- x + y = x => y=0, so we get repeating sum 'x' then it means we have a subarray sum 'y' equal to zero
*/

#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithZeroSum(vector<int> &nums)
{
    int n=nums.size();
    unordered_map<int,int> sumHash;
    int sum=0, maxLen=0;
    sumHash[0]=-1;

    for(int i=0 ; i<n ;i++){
        sum+=nums[i];
        if(sumHash.find(sum)!=sumHash.end()){
            maxLen=max(maxLen, i-sumHash[sum]);
        }
        else{
            sumHash[sum]=i;
        }
    }

    return maxLen;
}

int main()
{
    // vector<int> nums={1,-1,3,2,-2,-8,1,7,10,23}; //-> output = 5
    vector<int> nums={15,-2,-8,1,7,10,23}; //-> output = 3
    cout << longestSubarrayWithZeroSum(nums)  << endl;
    return 0;
}