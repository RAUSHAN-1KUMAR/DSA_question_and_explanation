/*
Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.

Example:-
    input: nums={4,2,2,6,4}, k=6
    output: 4
    explanation: The subarrays having XOR of their elements as 6 are {4,2}, {4,2,2,6,4}, {2,2,6} and {6}
*/

/*
Approach:- similar way as we did in "longest subarray with zero sum"
    -- a^k=x => x^k=a, so if we get repeating XOR value 'a' then it means we have a subarray whose XOR is equal to 'k'
*/

#include<bits/stdc++.h>
using namespace std;

int subarrayXORequalsK(vector<int> &nums, int &k)
{
    int n=nums.size();

    unordered_map<int,int> xorHash;
    int XOR=0;
    xorHash[0]++;

    int count=0;
    for(int i=0 ; i<n ;i++)
    {
        XOR^=nums[i];

        if(xorHash.find(XOR^k)!=xorHash.end()){
            count+=xorHash[XOR^k];
        }

        xorHash[XOR]++;
    }

    return count;
}

int main()
{
    vector<int> nums={4,2,2,6,4};
    int k=6;
    cout << subarrayXORequalsK(nums, k) << endl;
    return 0;
}

