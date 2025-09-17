/* -> 2163

You are given a 0-indexed integer array nums consisting of 3 * n elements.

You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:
    -- The first n elements belonging to the first part and their sum is sumfirst.
    -- The next n elements belonging to the second part and their sum is sumsecond.

The difference in sums of the two parts is denoted as sumfirst - sumsecond.

For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.

Return the minimum difference possible between the sums of the two parts after the removal of n elements.


Example 1:
    Input: nums = [3,1,2]
    Output: -1
    Explanation: Here, nums has 3 elements, so n = 1. 
    Thus we have to remove 1 element from nums and divide the array into two equal parts.
    - If we remove nums[0] = 3, the array will be [1,2]. The difference in sums of the two parts will be 1 - 2 = -1.
    - If we remove nums[1] = 1, the array will be [3,2]. The difference in sums of the two parts will be 3 - 2 = 1.
    - If we remove nums[2] = 2, the array will be [3,1]. The difference in sums of the two parts will be 3 - 1 = 2.
    The minimum difference between sums of the two parts is min(-1,1,2) = -1. 


Example 2:
    Input: nums = [7,9,5,8,1,3]
    Output: 1
    Explanation: Here n = 2. So we must remove 2 elements and divide the remaining array into two parts containing two elements each.
    If we remove nums[2] = 5 and nums[3] = 8, the resultant array will be [7,9,1,3]. The difference in sums will be (7+9) - (1+3) = 12.
    To obtain the minimum difference, we should remove nums[1] = 9 and nums[4] = 1. The resultant array becomes [7,5,8,3]. The difference in sums of the two parts is (7+5) - (8+3) = 1.
    It can be shown that it is not possible to obtain a difference smaller than 1.
*/


/*
Approach:- n = size/3
    -- so in this question we are asked to remove n elements, and return the minimum difference of sumFirst(only n elements)-sumSecond(only n elements)

    1. so think about it, do we actually have to remove the elements or did they asked for it -> NO,  the said to return minimum difference.

    2. to how can we get the minimum of sumFirst-sumSecond -> to minimize this we need sumFirst minimum as much possible(i.e., minHeap) and sumSecond maximum as much possible(i.e., maxHeap),, we are gonna find it for every index,,
        -- OKK then how you confirm that you have removed n elements, see as we are taking sumFirst of only n elements and sumSecond of only n elemnets, so automatically it will remove n elemnts.

        Example:-        7  9  5  8  1  3
         sumFirst(n)->  -1 16 12 12  6  4  -> left to right
         sumSecond(n)-> 17 17 13 11  4 -1  -> right to left

         Diff = 16-17 NO becuse sum second should not include the sumFirst elements, SO 16-13=3

    WE ARE SOLVING THIS QUESTION IN REVERSE ORDER, THEY ASKED US TO REMOVE N ELEMENTS AND THEN RETURN MIN DIFFSUM, BUT WE ARE ACTUALLY CALCULTING MIN DIFFSUM FIRST AND AUTOMATICALLY N ELEMETS REMOVED.

    we are going to use the concept kth smallest element for sumFirst(i.e., using maxHeap) and kth largest element for sumSecond(i.e., using minHeap) to reduce space and time complexity as mush as possible

SC:- O(n)
TC:- O(nlogn)
*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long

long long minimumDifference(vector<int>& nums) 
{
    int n = nums.size()/3;

    vector<ll> prefix(nums.size(), -1);// sumFirst n elements from left side
    vector<ll> suffix(nums.size(), -1);// sumSecond n elements from right side

    // maxHeap for prefix array
    priority_queue<ll>pqmax;
    ll sum=0;
    for(int i=0 ; i<nums.size() ; i++) // left to right
    {
        sum+=nums[i];
        pqmax.push(nums[i]);

        // we need n sum, so if pqmax.size()>n then pop the maxElement, so that we can have our sumFirst(prefix) minimum
        if(pqmax.size()>n)
        {
            sum -= pqmax.top();
            pqmax.pop();
        }

        // also maintaining the sumFirst(prefix array)
        if(pqmax.size()==n)
        {
            prefix[i]=sum;
        }
    }


    // minHeap for suffix array
    priority_queue<ll, vector<ll>, greater<ll>> pqmin;
    sum=0;
    for(int i=nums.size()-1 ; i>=0 ; i--) // right to left
    {
        sum+=nums[i];
        pqmin.push(nums[i]);

        // we need n sum, so if pqmin.size()>n then pop the minElement, so that we can have our sumSecond(prefix) maximum
        if(pqmin.size()>n)
        {
            sum -= pqmin.top();
            pqmin.pop();
        }

        // also maintaining the sumFirst(prefix array)
        if(pqmin.size()==n)
        {
            suffix[i]=sum;
        }
    }


    // lets find the min difference
    ll ans = LONG_LONG_MAX; // its a long long int_ max
    for(int i=n-1 ; i<2*n ; i++)
    {
        ans = min(ans, prefix[i]-suffix[i+1]);
    }

    return ans;
}

int main()
{
    vector<int> nums = {7,8,2,3,5,6,4,2,2};

    long long num = minimumDifference(nums);

    cout << num << endl;

    return 0;
}